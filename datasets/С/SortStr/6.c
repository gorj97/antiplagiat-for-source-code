// Шаблон задания 3.1

#define STRINGS_COUNT   10
#define MAX_STRING_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void GenerateRandomString (char *str, unsigned long max_size) {

	unsigned long i = 0;
	unsigned long size = 2+rand() % (max_size-3);
	char alph[] = "1234567890qwexvbjk;l";
	// генерация одной случайной строки
	while(i < size){
		str[i] = alph[rand() % strlen(alph)];
		str[i + 1] = NULL;
		i++;
	}
	while(i < MAX_STRING_SIZE){
		str[i] = NULL;
		i++;
	}
	return;
}


void GenerateRandomStrings (char strings[][MAX_STRING_SIZE]) {

	long i = 0;

	while(i < STRINGS_COUNT){
		GenerateRandomString (strings[i], MAX_STRING_SIZE);
		i++;
	}
	return;
}

void PrintStrings (char strings[][MAX_STRING_SIZE]) {

	long i = 0, j, c=0;
	while(i < STRINGS_COUNT){
		j = 0;
		while(j < MAX_STRING_SIZE){
			c += (long)strings[i][j];
			j++;
		}
		printf("%2d\t%10s%7d\n", i+1, strings[i],c);
		c = 0;
		i++;
	}
	putchar('\n');
}

long StrCmp(const char* _str1, const char* _str2){ //strcmp глючит, еще не разобрался почему
	long i = 0, c=0;
	while(i < MAX_STRING_SIZE){
		c += (long)_str1[i];
		c -= (long)_str2[i];
		i++;
	}
	return c;

}
void SortStrings (char strings[][MAX_STRING_SIZE]) {

// пузырьковая сортировка двумерного массива строк
// strcmp
	long i = 0 , j, p;
	char stk[MAX_STRING_SIZE];
	while(i < STRINGS_COUNT-1){
		j = 0;
		while(j < STRINGS_COUNT - i-1){
			if (strcmp(strings[j], strings[j+1])>0){
				p = 0;
				while(p < MAX_STRING_SIZE){
					stk[p] = strings[j][p];
					strings[j][p] = strings[j+1][p];
					strings[j+1][p] = stk[p];
					p++;
				}
			}
			j++;
		}
		i++;
	}
}


long main (long argc, char *argv[]) {

	char strings[STRINGS_COUNT][MAX_STRING_SIZE];

    GenerateRandomStrings (strings);
    PrintStrings (strings);
    SortStrings (strings);
    PrintStrings (strings);

    return 0;
}
