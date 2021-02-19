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

int MyAtoi(const char *str){
	int atoi=0,i=0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')){
		i = 2;
		while (str[i] != '\0'){
			if ('0'<=str[i]&& str[i]<='9')
				atoi = atoi * 16 + (str[i] - '0');
			else if ('A' <= str[i] && str[i] <= 'F')
				atoi = atoi * 16 + (str[i] - 'A') + 10;
			else if ('a' <= str[i] && str[i] <= 'f')
				atoi = atoi * 16 + (str[i] - 'a') + 10;
			else
				return -1;
			++i;
		}
	}
	else{
		while (str[i] != '\0'){
			if ('0' <= str[i] && str[i] <= '9')
				atoi = atoi * 10 + (str[i] - '0');
			else
				return -1;
			++i;
		}
	}
	return atoi;
}

void GenerateRandomStrings (char strings[][MAX_STRING_SIZE]) {

	int i = 0;

	for (i;i<STRINGS_COUNT; ++i) {
		GenerateRandomString (strings[i], MAX_STRING_SIZE);
	}

	return;
}

void print_dec(int arg){
	char* string[32] = { 0 };
	int tmp = arg, c, i = 0;;
	while (tmp != 0){
		c = tmp % 10;
		string[i] = c + '0';
		tmp /= 10;
		++i;
	}
	while (i != 0){
		putchar(string[i-1]);
		--i;
	}
	putchar('\n');
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

void print_hex(int arg){
	char* string1[32] = { 0 };
	char* string = "0123456789ABCDEF";
	int tmp = arg, c, i = -1;
	while (tmp != 0){
		++i;
		c = tmp % 16;
		string1[i] = string[c];
		tmp /= 16;
	}
	putchar('0');
	putchar('x');
	while (i>-1){
		putchar(string1[i]);
		--i;
	}
	putchar('\n');
	return;
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
