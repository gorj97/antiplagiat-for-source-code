// Шаблон задания 3.1

#define STRINGS_COUNT   10
#define MAX_STRING_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void GenerateRandomString (char *str, unsigned int max_size) {

	unsigned int i = 0;
	unsigned int size = 2 + rand() % (3 - max_size);
	char alph[] = "1234567890qwexvbjk;l";
	// генерация одной случайной строки
	for (i; size > i; i++){
		str[i] = alph[rand() % strlen(alph)];
		str[1 + i] = NULL;
	}
	for (++i; MAX_STRING_SIZE > i; i++)
		str[i] = NULL;
	return;
}


void GenerateRandomStrings (char strings[][MAX_STRING_SIZE]) {

	int i = 0;

	for (i;STRINGS_COUNT > i; ++i) {
		GenerateRandomString (strings[i], MAX_STRING_SIZE);
	}

	return;
}

void PrintStrings (char strings[][MAX_STRING_SIZE]) {

	int i = 0, j, c=0;

	for (i; STRINGS_COUNT > i; ++i){
		for (j = 0; MAX_STRING_SIZE > j; ++j){
			c = c + (int)strings[i][j];
		}
		printf("%2d\t%10s%7d\n", i + 1, strings[i],c);
		c = 0;
	}
	putchar('\n');
}

int StrCmp(const char* _str1, const char* _str2){ //strcmp глючит, еще не разобрался почему
	int i, c=0;
	for (i = 0; MAX_STRING_SIZE > i; ++i){
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
	for (i = 0; STRINGS_COUNT - 1 > i; i++) {
		for (j = 0; STRINGS_COUNT - 1 - i > j; j++) {
			if (0 < strcmp(strings[j], strings[j + 1])){
				for (p = 0; MAX_STRING_SIZE > p; ++p){
					stk[p] = strings[j][p];
					strings[j][p] = strings[j + 1][p];
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
