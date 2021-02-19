// Шаблон задания 3.1

#define COUNT_STRINGS   10
#define MAX_STR_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Random comment
// Function func1
unsigned long q, Size;
void func1 (char *string, unsigned long max_size) {

	q = 0;
	Size = 2+rand() % (max_size-3);
	char alpha[] = "1234567890qwexvbjk;l";
	// генерация одной случайной строки
	while(Size > q){
		string[q] = alpha[rand() % strlen(alpha)];
		string[1 + q] = NULL;
		q++;// Random comment
	}
	while(MAX_STR_SIZE > q){
		string[q] = NULL;
		q++;
	}
	return;
}// Random comment

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

// Function Print_strings
long j, ch;
void Print_strings (char strs[][MAX_STR_SIZE]) {

	q = 0; 
	ch=0;
	while(COUNT_STRINGS > q){// Random comment
		j = 0;
		while(MAX_STR_SIZE > j){
			ch = ch + (long)strs[q][j];// Random comment
			j++;
		}
		printf("%2d\t%10s%7d\n", q + 1, strs[q],ch);
		ch = 0;
		q++;
		// Random comment
	}
	putchar('\n');
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

// Function Sort_func
long p;
void Sort_func (char strs[][MAX_STR_SIZE]) {

// пузырьковая сортировка двумерного массива строк
// Cmp_Str
	q = 0;
	char stk[MAX_STR_SIZE];
	while(COUNT_STRINGS - 1 > q){// Random comment
		j = 0;
		while(COUNT_STRINGS - 1 - q > j){
			if (0 < Cmp_Str(strs[j], strs[j+1])){
				p = 0;
				// Random comment
				while(MAX_STR_SIZE > p){
					stk[p] = strs[j][p];
					strs[j][p] = strs[j+1][p];
					strs[j+1][p] = stk[p];
					p++;
				}
			}
			j++;// Random comment
		}
		q++;
	}
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

// Function Cmp_Str
long Cmp_Str(const char* _str1, const char* _str2){ //Cmp_Str глючит, еще не разобрался почему
	q = 0; 
	ch=0;
	while(MAX_STR_SIZE > q){
		ch += (long)_str1[q];// Random comment
		ch -= (long)_str2[q];
		q++;
	}
	// Random comment
	return ch;// Random comment

}

// Function func2
void func2 (char strs[][MAX_STR_SIZE]) {
// Random comment
	q = 0;

	while(COUNT_STRINGS > q){
		func1 (strs[q], MAX_STR_SIZE);
		q++;
	}
	return;// Random comment
}

// Function main
long main (long argc, char *argv[]) {

	char strs[COUNT_STRINGS][MAX_STR_SIZE];// Random comment

    func2 (strs);
    Print_strings (strs);// Random comment
    Sort_func (strs);
	// Random comment
    Print_strings (strs);
	// Random comment
    return 0;
}
