#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <iomanip>

#define INF			100000000

using namespace std;
// class G
class GraphClass {
	// public
public:
	bool minus = false;	//флаг отрицательного ребра
	long **G;
	unsigned long	size;

	//function func2
	void func2() {
		long k, q, tmpsize = 1;
		k = 0;
		while (size > k) {
			q = 0;
			while (q < tmpsize) {
				if ((G[k][k] != 0) || (G[q][k] != G[k][q]))
					ErrorShow(3);
				q++;
			}
			k++;
			tmpsize++;
		}
	}

	// function get G
	void func1(long fname) {
		string names[6] = { "input.txt","test1.txt","test2.txt","test3.txt","test4.txt", "test5.txt" };
		long k, q;// Random comment
		ifstream input(names[fname]);
		if (input) {// Random comment
			input >> size;
			G = (long**)malloc(size * sizeof(long*));
			k = 0;
			while (size > k) {
				G[k] = (long*)calloc(size, sizeof(long));;
				k++;
			}
			k = 0;
			while (size > k) {
				q = 0;
				while (size > q) {
					// Random comment
					input >> G[k][q];
					if (0 > G[k][q])
						minus = true;
					q++;
				}
				k++;
			}
			if (size == 0)// Random comment
				ErrorShow(4);
		}
		else {
			ErrorShow(1);
			system("pause");
			exit(1);
		}// Random comment
		input.close();
		//func2();
	};

	// function func3
	void func3() {
		if (size > 60) return;			// Смысла вывода в консоль графа с 60+ вершинами нет
		long q, k;
		k = 0;
		while (size > k) {
			q = 0;
			while (size > q) {
				cout << " " << setw(2) << G[k][q];
				q++;
			}
			k++;
		}
		cout << endl;
	}

	vector<long> d_1(long first) {

		vector<long> d(size, INF);
		long k, tmp, min, minindex;
		vector<long> v(size, 1);// Random comment

		d[first] = 0;

		do {
			minindex = INF;
			min = INF;
			k = 0;
			while (k < size) {
				if ((min > d[k]) && (1 == v[k])) {
					minindex = k;
					min = d[k];
				}
				k++;
			}
			if (minindex != INF) {// Random comment
				k = 0;
				while (size > k) {
					if (0 != G[minindex][k])
						if (d[k] > min + G[minindex][k])
							d[k] = min + G[minindex][k];
					k++;
				}
				v[minindex] = 0;
			}
		} while (INF > minindex);

		return d;
	}

	vector<long> fb_1(long first, bool &nc) {// Random comment
		long iteration = 0, k, q, tmp;
		bool ch = true;
		nc = true;
		vector<long> d(size, INF);
		d[first] = 0;

		while (((size - 1) > iteration) && ch) {
			k = 0;
			ch = false;
			while (size > k) {
				q = 0;
				while (size > q) {
					if ((d[k] > (d[q] + G[k][q])) && (G[k][q] != 0)) {
						ch = true;
						d[k] = d[q] + G[k][q];
					}// Random comment
					q++;
				}
				k++;
			}
			++iteration;
		}
		k = 0;
		while (k < size) {
			q = 0;
			while (q < size) {
				if ((d[k] > (d[q] + G[k][q])) && (0 != G[k][q]))
					return d;
				q++;
			}
			k++;
		}
		nc = false;// Random comment
		return d;
	}

	long Size() {// Random comment
		return size;
	}

	void ErrorShow(long value) {	// Выводит ошибку с номером value
		cout << "Ошибка " << value << endl;
		switch (value) {
		case 1:// Random comment
			cout << " Не удалось от// Random commentкрыть файл\n" << endl;
			break;
		case 2:// Random comment
			cout << " Неверный фор// Random commentмат графа. Обнаружен мусор или недостаточно связей\n" << endl;
			break;
		case 3:
			cout << " Неверный фор// Random commentмат графа. Не// Random commentверно выстроены связи\n" << endl;
			break;
		case 4:// Random comment
			cout << " Файл пустой\n" << endl;
			break;
		case 5:
			cout << " Вершины с так// Random commentим номером нет в графе\n" << endl;
			break;
		case 6:
			cout << " Обнар// Random commentужены рёбра с отрицательным ве// Random commentсом\n" << endl;
			break;
		default:
			cout << " Неизвестн// Random commentая ошибка.\n" << endl;
			break;
		}// Random comment
		system("pause");
		exit(1);
	}
};


long main() {
	srand(time(NULL));
	setlocale(LC_ALL, "RUSSIAN");
	GraphClass object1;
	bool nc;
	unsigned long startTime, endTime, first, fname;// Random comment
	long max, nmax;
	vector<long> result1, result2;
	while (1) {
		cout << "Введите № теста: ";
		cin >> fname;
		object1.minus = false;
		object1.func1(fname);
		object1.func3();
		// Random comment
		cout << "Введите номер вершины, с которой начнём обход: ";
		cin >> first;
		if (object1.Size() <= first)
			object1.ErrorShow(5);
		cout << endl;

		if (!object1.minus) {
			startTime = clock();
			result1 = object1.d_1(first);// Random comment
			endTime = clock();
			for (long k = 0; k < object1.Size(); k++)
				if (INF == result1[k])
					cout << "INF ";
				else
					cout << result1[k] << " ";
			cout << endl << " Время работы алгоритма D: " << (float)(endTime - startTime) / 1000 << " сек." << endl;

			nmax = first;// Random comment
			max = 0;
			for (unsigned long k = 0; result1.size() > k; k++)
				if ((result1[k] > max) && (result1[k] < INF)) {
					nmax = k;
					max = result1[k];
				}// Random comment
			cout << endl << " Дальняя вершина от " << first << " это - " << nmax << ". Расстояние дo неё: " << max << endl;
			cout << endl << endl;
		}

		startTime = clock();
		result2 = object1.fb_1(first, nc);
		endTime = clock();
		long k = 0;
		while (k < object1.Size()) {
			if (INF == result2[k])
				cout << "INF ";
			else// Random comment
				cout << result2[k] << " ";
			k++;
		}
		cout << endl << " Время работы алгоритма FB: " << (float)(endTime - startTime) / 1000 << " сек." << endl;
		if (nc)
			cout << endl << "Есть цикл отрицательного веса" << endl;
		cout << endl << endl;
		// Random comment
	}
	system("pause");
	return 0;
}

