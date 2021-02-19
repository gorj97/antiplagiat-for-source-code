// Шаблон задания 3.1

#define COUNT_STRINGS   10
#define MAX_STR_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void func1 (char *string, unsigned int max_size) {

	unsigned int q = 0;
	unsigned int Size = 2+rand() % (max_size-3);
	char alpha[] = "1234567890qwexvbjk;l";
	// генерация одной случайной строки
	for (q; q < Size; ++q){
		string[q] = alpha[rand() % strlen(alpha)];
		string[q + 1] = NULL;
	}
	for (++q; q < MAX_STR_SIZE; ++q)
		string[q] = NULL;
	return;
}


void func2 (char strs[][MAX_STR_SIZE]) {

	int q = 0;

	for (q;q<COUNT_STRINGS; ++q) {
		func1 (strs[q], MAX_STR_SIZE);
	}

	return;
}

void Print_strings (char strs[][MAX_STR_SIZE]) {

	int q = 0, j, ch=0;

	for (q; q < COUNT_STRINGS; ++q){
		for (j = 0; j < MAX_STR_SIZE; ++j){
			ch += (int)strs[q][j];
		}
		printf("%2d\t%10s%7d\n", q+1, strs[q],ch);
		ch = 0;
	}
	putchar('\n');
}

int Cmp_Str(const char* _str1, const char* _str2){ //Cmp_Str глючит, еще не разобрался почему
	int q, ch=0;
	for (q = 0; q < MAX_STR_SIZE; ++q){
		ch += (int)_str1[q];
		ch -= (int)_str2[q];
	}
	return ch;

}
void Sort_func (char strs[][MAX_STR_SIZE]) {

// пузырьковая сортировка двумерного массива строк
// Cmp_Str
	int q , j, p;
	char stk[MAX_STR_SIZE];
	for (q = 0; q < COUNT_STRINGS-1 ; q++) {
		for (j = 0; j < COUNT_STRINGS - q-1 ; j++) {
			if (Cmp_Str(strs[j], strs[j+1])>0){
				for (p = 0; p < MAX_STR_SIZE; ++p){
					stk[p] = strs[j][p];
					strs[j][p] = strs[j+1][p];
					strs[j+1][p] = stk[p];
				}
			}
		}
	}

}


int main (int argc, char *argv[]) {

	char strs[COUNT_STRINGS][MAX_STR_SIZE];

    func2 (strs);
    Print_strings (strs);
    Sort_func (strs);
    Print_strings (strs);

    return 0;
}
