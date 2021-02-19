#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <iomanip>

#define INF			100000000

using namespace std;

class Class_graph {
public:
	long **graph;	
	bool minus = false;	//флаг отрицательного ребра
	unsigned long size;

	void Get_graph(long fname) {	
		long i, j;
		string names[6] = { "in.txt","test1.txt","test2.txt","test3.txt","test4.txt", "test5.txt" };
		ifstream in(names[fname]);
		if (in) {
			in >> size;
			graph = (long**)malloc(size * sizeof(long*));
			i = 0;
			while(i < size){
				graph[i] = (long*)calloc(size, sizeof(long));
				i++;
			}
			i = 0;
			while(i < size){
				j = 0;
				while(j < size){
					in >> graph[i][j];
					if (graph[i][j] < 0)
						minus = true;
					j++;
				}
				i++;
			}
			if (size == 0)
				ErrorShow(4);
		}
		else {
			ErrorShow(1);
			system("pause");
			exit(1);
		}
		in.close();
		//Check_graph();
	};

	void Check_graph() {
		long i, j, tempsize = 1;
		i = 0;
		while(i < size){
			j = 0;
			while(j < tempsize){
				if ((graph[i][j] != graph[j][i]) || (graph[i][i] != 0))
					ErrorShow(3);
				j++;
			}
			tempsize++;
			i++;
		}
	}

	void Show_graph() {
		if (size > 60) return;			// Смысла вывода в консоль графа с 60+ вершинами нет
		long i = 0, j;
		while(i < size){
			j = 0;
			while(j < size){
				cout << " " << setw(2) << graph[i][j];
				j++;
			}
			i++;
		}
		cout << endl;
	}

	vector<long> D_alg(long first) {

		long i, tmp, min, minindex;
		vector<long> v(size, 1);
		vector<long> d(size, INF);

		d[first] = 0;

		do {
			min = INF;
			minindex = INF;
			i = 0;
			while(i < size){
				if ((v[i] == 1) && (d[i] < min)) {
					min = d[i];
					minindex = i;
				}
				i++;
			}
			if (minindex != INF) {
				i = 0;
				while(i < size){
					if (graph[minindex][i] != 0) 
						if (min + graph[minindex][i] < d[i])
							d[i] = min + graph[minindex][i];	
					i++;
				}			
				v[minindex] = 0;
			}
		} while (minindex < INF);

		return d;
	}

	vector<long> FB_alg(long first, bool &nc) {
		long iter = 0, i, j, tmp;
		vector<long> d(size, INF);
		bool ch = true;
		nc = true;
		d[first] = 0;

		while (ch && (iter < (size - 1))) {
			ch = false;
			i = 0;
			while(i < size){
				j = 0;
				while(j < size){
					if ((graph[i][j] != 0) && ((d[j] + graph[i][j]) < d[i])) {
						d[i] = d[j] + graph[i][j];
						ch = true;
					}
					j++;
				}
				i++;
			}
			++iter;
		}
		i = 0;
		while(i < size){
			j = 0;
			while(j < size){
				if ((graph[i][j] != 0) && ((d[j] + graph[i][j]) < d[i]))
					return d;
				j++;
			}
			i++;
		}
		nc = false;
		return d;
	}

	long Size() {
		return size;
	}

	void ErrorShow(long val) {	// Выводит ошибку с номером val
		cout << "Ошибка " << val << endl;
		switch (val) {
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


long main() {
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(NULL));
	Class_graph object1;
	unsigned long start_time, end_time;
	unsigned long first, fname;
	vector<long> res1, res2;
	long max, nmax;
	bool nc;
	while (1) {
		object1.minus = false;
		cout << "Введите № теста: ";
		cin >> fname;
		object1.Get_graph(fname);
		object1.Show_graph();

		cout << "Введите номер вершины, с которой начнём обход: ";
		cin >> first;
		if (first >= object1.Size())
			object1.ErrorShow(5);
		cout << endl;

		if (!object1.minus) {
			start_time = clock();
			res1 = object1.D_alg(first);
			end_time = clock();
			for (long i = 0; i < object1.Size(); i++)
				if (res1[i] == INF)
					cout << "INF ";
				else
					cout << res1[i] << " ";
			cout << endl << " Время работы алгоритма D: " << (float)(end_time - start_time) / 1000 << " сек." << endl;

		max = 0;
		nmax = first;
		for (unsigned long i = 0; i < res1.size(); i++)
			if ((res1[i] > max) && (res1[i] < INF)) {
				max = res1[i];
				nmax = i;
			}
		cout << endl << " Дальняя вершина от " << first << " это - " << nmax << ". Расстояние дo неё: " << max << endl;
		cout << endl << endl;
	}

		start_time = clock();
		res2 = object1.FB_alg(first, nc);
		end_time = clock();
		long i = 0;
		while(i < object1.Size()){
			if (res2[i] == INF)
				cout << "INF ";
			else
				cout << res2[i] << " ";
			i++;
		}
		cout << endl << " Время работы алгоритма FB: " << (float)(end_time - start_time) / 1000 << " сек." << endl;
		if (nc)
			cout << endl << "Есть цикл отрицательного веса" << endl;
		cout << endl << endl;

	}
	system("pause");
	return 0;
}

