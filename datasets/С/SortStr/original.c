// Шаблон задания 3.1

#define STRINGS_COUNT   10
#define MAX_STRING_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void GenerateRandomString (char *str, unsigned int max_size) {

	unsigned int i = 0;
	unsigned int size = 2+rand() % (max_size-3);
	char alph[] = "1234567890qwexvbjk;l";
	// генерация одной случайной строки
	for (i; i < size; ++i){
		str[i] = alph[rand() % strlen(alph)];
		str[i + 1] = NULL;
	}
	for (++i; i < MAX_STRING_SIZE; ++i)
		str[i] = NULL;
	return;
}


void GenerateRandomStrings (char strings[][MAX_STRING_SIZE]) {

	int i = 0;

	for (i;i<STRINGS_COUNT; ++i) {
		GenerateRandomString (strings[i], MAX_STRING_SIZE);
	}

	return;
}

void PrintStrings (char strings[][MAX_STRING_SIZE]) {

	int i = 0, j, c=0;

	for (i; i < STRINGS_COUNT; ++i){
		for (j = 0; j < MAX_STRING_SIZE; ++j){
			c += (int)strings[i][j];
		}
		printf("%2d\t%10s%7d\n", i+1, strings[i],c);
		c = 0;
	}
	putchar('\n');
}

int StrCmp(const char* _str1, const char* _str2){ //strcmp глючит, еще не разобрался почему
	int i, c=0;
	for (i = 0; i < MAX_STRING_SIZE; ++i){
		c += (int)_str1[i];
		c -= (int)_str2[i];
	}
	return c;

}
void SortStrings (char strings[][MAX_STRING_SIZE]) {

// пузырьковая сортировка двумерного массива строк
// strcmp
	int i , j, p;
	char stk[MAX_STRING_SIZE];
	for (i = 0; i < STRINGS_COUNT-1 ; i++) {
		for (j = 0; j < STRINGS_COUNT - i-1 ; j++) {
			if (strcmp(strings[j], strings[j+1])>0){
				for (p = 0; p < MAX_STRING_SIZE; ++p){
					stk[p] = strings[j][p];
					strings[j][p] = strings[j+1][p];
					strings[j+1][p] = stk[p];
				}
			}
		}
	}

}


int main (int argc, char *argv[]) {

	char strings[STRINGS_COUNT][MAX_STRING_SIZE];

    GenerateRandomStrings (strings);
    PrintStrings (strings);
    SortStrings (strings);
    PrintStrings (strings);

    return 0;
}
