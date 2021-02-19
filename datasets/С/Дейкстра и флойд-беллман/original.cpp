#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <iomanip>

#define INF			100000000

using namespace std;

class Class_graph {
public:
	int **graph;	
	bool minus = false;	//���� �������������� �����
	int	size;

	void Get_graph(int fname) {	
		int i, j;
		string names[6] = { "in.txt","test1.txt","test2.txt","test3.txt","test4.txt", "test5.txt" };
		ifstream in(names[fname]);
		if (in) {
			in >> size;
			graph = (int**)malloc(size * sizeof(int*));
			for (i = 0; i < size; ++i)
				graph[i] = (int*)calloc(size, sizeof(int));

			for (i = 0; i < size; ++i)
				for (j = 0; j < size; ++j) {
					
					in >> graph[i][j];
					if (graph[i][j] < 0)
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
		in.close();
		//Check_graph();
	};

	void Check_graph() {
		int i, j, tempsize = 1;
		for (i = 0; i < size; ++i) {
			for (j = 0; j < tempsize; ++j)
				if ((graph[i][j] != graph[j][i]) || (graph[i][i] != 0))
					ErrorShow(3);
			tempsize++;
		}
	}

	void Show_graph() {
		if (size > 60) return;			// ������ ������ � ������� ����� � 60+ ��������� ���
		int i, j;
		for (i = 0; i < size; ++i, cout << endl)
			for (j = 0; j < size; ++j)
				cout << " " << setw(2) << graph[i][j];
		cout << endl;
	}

	vector<int> D_alg(int first) {

		int i, tmp, min, minindex;
		vector<int> v(size, 1);
		vector<int> d(size, INF);

		d[first] = 0;

		do {
			min = INF;
			minindex = INF;
			for (i = 0;i < size; i++) {
				if ((v[i] == 1) && (d[i] < min)) {
					min = d[i];
					minindex = i;
				}
			}
			if (minindex != INF) {
				for (i = 0;i < size; i++) 
					if (graph[minindex][i] != 0) 
						if (min + graph[minindex][i] < d[i])
							d[i] = min + graph[minindex][i];				
				v[minindex] = 0;
			}
		} while (minindex < INF);

		return d;
	}

	vector<int> FB_alg(int first, bool &nc) {
		int iter = 0, i, j, tmp;
		vector<int> d(size, INF);
		bool ch = true;
		nc = true;
		d[first] = 0;

		while (ch && (iter < (size - 1))) {
			ch = false;
			for (i = 0;i < size; i++) {
				for (j = 0;j < size; j++) {
					if ((graph[i][j] != 0) && ((d[j] + graph[i][j]) < d[i])) {
						d[i] = d[j] + graph[i][j];
						ch = true;
					}
				}
			}
			++iter;
		}
		for (i = 0;i < size; i++) 
			for (j = 0;j < size; j++)
				if ((graph[i][j] != 0) && ((d[j] + graph[i][j]) < d[i]))
					return d;
		nc = false;
		return d;
	}

	int Size() {
		return size;
	}

	void ErrorShow(int val) {	// ������� ������ � ������� val
		cout << "������ " << val << endl;
		switch (val) {
		case 1:
			cout << " �� ������� ������� ����\n" << endl;
			break;
		case 2:
			cout << " �������� ������ �����. ��������� ����� ��� ������������ ������\n" << endl;
			break;
		case 3:
			cout << " �������� ������ �����. ������� ��������� �����\n" << endl;
			break;
		case 4:
			cout << " ���� ������\n" << endl;
			break;
		case 5:
			cout << " ������� � ����� ������� ��� � �����\n" << endl;
			break;
		case 6:
			cout << " ���������� ���� � ������������� �����\n" << endl;
			break;
		default:
			cout << " ����������� ������.\n" << endl;
			break;
		}
		system("pause");
		exit(1);
	}
};


int main() {
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(NULL));
	Class_graph object1;
	unsigned int start_time, end_time;
	unsigned int first, fname;
	vector<int> res1, res2;
	int max, nmax;
	bool nc;
	while (1) {
		object1.minus = false;
		cout << "������� � �����: ";
		cin >> fname;
		object1.Get_graph(fname);
		object1.Show_graph();

		cout << "������� ����� �������, � ������� ������ �����: ";
		cin >> first;
		if (first >= object1.Size())
			object1.ErrorShow(5);
		cout << endl;

		if (!object1.minus) {
			start_time = clock();
			res1 = object1.D_alg(first);
			end_time = clock();
			for (int i = 0; i < object1.Size(); i++)
				if (res1[i] == INF)
					cout << "INF ";
				else
					cout << res1[i] << " ";
			cout << endl << " ����� ������ ��������� D: " << (float)(end_time - start_time) / 1000 << " ���." << endl;

		max = 0;
		nmax = first;
		for (unsigned int i = 0; i < res1.size(); i++)
			if ((res1[i] > max) && (res1[i] < INF)) {
				max = res1[i];
				nmax = i;
			}
		cout << endl << " ������� ������� �� " << first << " ��� - " << nmax << ". ���������� �o ��: " << max << endl;
		cout << endl << endl;
	}

		start_time = clock();
		res2 = object1.FB_alg(first, nc);
		end_time = clock();
		for (int i = 0; i < object1.Size(); i++)
			if (res2[i] == INF)
				cout << "INF ";
			else
				cout << res2[i] << " ";
		cout << endl << " ����� ������ ��������� FB: " << (float)(end_time - start_time) / 1000 << " ���." << endl;
		if (nc)
			cout << endl << "���� ���� �������������� ����" << endl;
		cout << endl << endl;

	}
	system("pause");
	return 0;
}

