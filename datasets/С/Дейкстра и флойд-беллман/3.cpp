#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <iomanip>

#define INF			100000000

using namespace std;

class GraphClass {
public:
	int **G;	
	bool minus = false;	//флаг отрицательного ребра
	int	size;

	void func1(int fname) {	
		int k, q;
		string names[6] = { "input.txt","test1.txt","test2.txt","test3.txt","test4.txt", "test5.txt" };
		ifstream input(names[fname]);
		if (input) {
			input >> size;
			G = (int**)malloc(size * sizeof(int*));
			for (k = 0; k < size; ++k)
				G[k] = (int*)calloc(size, sizeof(int));

			for (k = 0; k < size; ++k)
				for (q = 0; q < size; ++q) {
					
					input >> G[k][q];
					if (G[k][q] < 0)
						minus = true;
				}
			if (size == 0)
				ErrorShow(4);
		}
		else {
			ErrorShow(1);
			system("pause");
			exit(1);
		}
		input.close();
		//func2();
	};

	void func2() {
		int k, q, tmpsize = 1;
		for (k = 0; k < size; ++k) {
			for (q = 0; q < tmpsize; ++q)
				if ((G[k][q] != G[q][k]) || (G[k][k] != 0))
					ErrorShow(3);
			tmpsize++;
		}
	}

	void func3() {
		if (size > 60) return;			// Смысла вывода в консоль графа с 60+ вершинами нет
		int k, q;
		for (k = 0; k < size; ++k, cout << endl)
			for (q = 0; q < size; ++q)
				cout << " " << setw(2) << G[k][q];
		cout << endl;
	}

	vector<int> d_1(int first) {

		int k, tmp, min, minindex;
		vector<int> v(size, 1);
		vector<int> d(size, INF);

		d[first] = 0;

		do {
			min = INF;
			minindex = INF;
			for (k = 0;k < size; k++) {
				if ((v[k] == 1) && (d[k] < min)) {
					min = d[k];
					minindex = k;
				}
			}
			if (minindex != INF) {
				for (k = 0;k < size; k++) 
					if (G[minindex][k] != 0) 
						if (min + G[minindex][k] < d[k])
							d[k] = min + G[minindex][k];				
				v[minindex] = 0;
			}
		} while (minindex < INF);

		return d;
	}

	vector<int> fb_1(int first, bool &nc) {
		int iteration = 0, k, q, tmp;
		vector<int> d(size, INF);
		bool ch = true;
		nc = true;
		d[first] = 0;

		while (ch && (iteration < (size - 1))) {
			ch = false;
			for (k = 0;k < size; k++) {
				for (q = 0;q < size; q++) {
					if ((G[k][q] != 0) && ((d[q] + G[k][q]) < d[k])) {
						d[k] = d[q] + G[k][q];
						ch = true;
					}
				}
			}
			++iteration;
		}
		for (k = 0;k < size; k++) 
			for (q = 0;q < size; q++)
				if ((G[k][q] != 0) && ((d[q] + G[k][q]) < d[k]))
					return d;
		nc = false;
		return d;
	}

	int Size() {
		return size;
	}

	void ErrorShow(int value) {	// Выводит ошибку с номером value
		cout << "Ошибка " << value << endl;
		switch (value) {
		case 1:
			cout << " Не удалось открыть файл\n" << endl;
			break;
		case 2:
			cout << " Неверный формат графа. Обнаружен мусор или недостаточно связей\n" << endl;
			break;
		case 3:
			cout << " Неверный формат графа. Неверно выстроены связи\n" << endl;
			break;
		case 4:
			cout << " Файл пустой\n" << endl;
			break;
		case 5:
			cout << " Вершины с таким номером нет в графе\n" << endl;
			break;
		case 6:
			cout << " Обнаружены рёбра с отрицательным весом\n" << endl;
			break;
		default:
			cout << " Неизвестная ошибка.\n" << endl;
			break;
		}
		system("pause");
		exit(1);
	}
};


int main() {
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(NULL));
	GraphClass object1;
	unsigned int startTime, endTime;
	unsigned int first, fname;
	vector<int> result1, result2;
	int max, nmax;
	bool nc;
	while (1) {
		object1.minus = false;
		cout << "Введите № теста: ";
		cin >> fname;
		object1.func1(fname);
		object1.func3();

		cout << "Введите номер вершины, с которой начнём обход: ";
		cin >> first;
		if (first >= object1.Size())
			object1.ErrorShow(5);
		cout << endl;

		if (!object1.minus) {
			startTime = clock();
			result1 = object1.d_1(first);
			endTime = clock();
			for (int k = 0; k < object1.Size(); k++)
				if (result1[k] == INF)
					cout << "INF ";
				else
					cout << result1[k] << " ";
			cout << endl << " Время работы алгоритма D: " << (float)(endTime - startTime) / 1000 << " сек." << endl;

		max = 0;
		nmax = first;
		for (unsigned int k = 0; k < result1.size(); k++)
			if ((result1[k] > max) && (result1[k] < INF)) {
				max = result1[k];
				nmax = k;
			}
		cout << endl << " Дальняя вершина от " << first << " это - " << nmax << ". Расстояние дo неё: " << max << endl;
		cout << endl << endl;
	}

		startTime = clock();
		result2 = object1.fb_1(first, nc);
		endTime = clock();
		for (int k = 0; k < object1.Size(); k++)
			if (result2[k] == INF)
				cout << "INF ";
			else
				cout << result2[k] << " ";
		cout << endl << " Время работы алгоритма FB: " << (float)(endTime - startTime) / 1000 << " сек." << endl;
		if (nc)
			cout << endl << "Есть цикл отрицательного веса" << endl;
		cout << endl << endl;

	}
	system("pause");
	return 0;
}

