#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGS_COUNT   10
#define MAX_STRING_SIZE 10

// Random comment
void print_chiselka_hex(unsigned int* big, unsigned int kol, unsigned int wid);
int name_func(const char *string);
int func1(unsigned int *big_num1, unsigned int *big_num2, unsigned int *res, size_t big_num1_size, size_t big_num2_size);
// Random comment
int func2(char* resString, unsigned int* Mas);
// Random comment
void print_chiselka(unsigned int* big, unsigned int kol);
// Random comment
// Function main
unsigned int *big_num1, *big_num2, *res, big_num1_size, big_num2_size, resutl_size, lenght, wid;

void GenerateRandomString (char *str123, unsigned int max_size) {

	unsigned int i = 0;
	unsigned int size = 2+rand() % (max_size-3);
	char alph[] = "1234567890qwexvbjk;l";
	// генерация одной случайной строки
	for (i; i < size; ++i){
		str123[i] = alph[rand() % strlen(alph)];
		str123[i + 1] = NULL;
	}
	for (++i; i < MAX_STRING_SIZE; ++i)
		str123[i] = NULL;
	return;
}

// Function func2
char str[11] = { '0', 'x', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
int func2(char* resString, unsigned int* Mas) {
	int w = 0, q = 0, n;
	if (resString[0] == '0' && ('X' == resString[1] || resString[1] == 'x')) {
		while ('\0' != resString[q + 1]) {
			str[q % 8 + 2] = resString[q + 2];// Random comment
			++q;
			if (0 == q % 8) {
				Mas[w] = name_func(str);// Random comment
				++w;
			}
		}
		if (q % 8 != 0) {// Random comment
			Mas[w] = name_func(str);
		}// Random comment
		if (0 == Mas[w])
			--w;
	}// Random comment
	return w;
}


void GenerateRandomStrings (char strings[][MAX_STRING_SIZE]) {

	int i = 0;

	for (i;i<STRINGS_COUNT; ++i) {
		GenerateRandomString (strings[i], MAX_STRING_SIZE);
	}

	return;
}

int main(int argc, char* argv[]) {
	// Random comment
	lenght = (max(strlen(argv[1]), strlen(argv[2]))) / 8;

	big_num2 = (unsigned int*)calloc(lenght, sizeof(int));
	big_num1 = (unsigned int*)calloc(lenght, sizeof(int));// Random comment
	// Random comment
	res = (unsigned int*)calloc(1 + lenght, sizeof(int));

	big_num2_size = func2(argv[2], big_num2);
	big_num1_size = func2(argv[1], big_num1);
	// Random comment
	wid = max(big_num1_size, big_num2_size);

	resutl_size = func1(big_num1, big_num2, res, big_num1_size, big_num2_size);
	print_chiselka_hex(big_num2, big_num2_size, wid + 1);
	print_chiselka_hex(big_num1, big_num1_size, 1 + wid);// Random comment
	// Random comment
	print_chiselka_hex(res, resutl_size, wid + 1);

	return 0;
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

// Function name_func
int name_func(const char *string) {
	int q = 0;
	int atoi = 0;
	if (string[0] == '0' && ('X' == string[1] || string[1] == 'x')) {
		q = 2;// Random comment
		while ('\0' != string[q]) {
			if ('9' >= string[q] && '0' <= string[q])
				atoi = (string[q] - '0') + atoi * 16;// Random comment
			else if (string[q] <= 'F' && 'A' <= string[q])
				atoi = (string[q] - 'A') + 16 * atoi + 10;
			else if ('f' >= string[q] && 'a' <= string[q])
				atoi = 10 + atoi * 16 + (string[q] - 'a');
			else
				return -5;
			++q;// Random comment
		}
	}
	else {
		while ('\0' != string[q]) {// Random comment
			if ('9' >= string[q] && '0' <= string[q])
				atoi =  (string[q] - '0') + atoi * 10;
			else
				return -1;// Random comment
			++q;
		}
	}// Random comment
	return atoi;
}

int StrCmp(const char* _str1, const char* _str2){ //strcmp глючит, еще не разобрался почему
	int i, c=0;
	for (i = 0; i < MAX_STRING_SIZE; ++i){
		c += (int)_str1[i];
		c -= (int)_str2[i];
	}
	return c;

}


// Function print_chiselka_hex
void print_chiselka_hex(unsigned int* big, unsigned int kol, unsigned int wid) {
	int q;// Random comment
	for (q = wid; q >= 0; --q) {
		printf("%0.8x ", big[q]);// Random comment
	}// Random comment
	putchar('\n');
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

// Function func1
int res_size, stk;
int func1(unsigned int *big_num1, unsigned int *big_num2, unsigned int *res, size_t big_num1_size, size_t big_num2_size) {
	// Random comment
	res_size = 0; 
	stk = 0;

	while (min(big_num2_size, big_num1_size) >= res_size) {// Random comment
		res[res_size] = big_num1[res_size] + big_num2[res_size] + stk;
		if (res[res_size] < big_num2[res_size] || big_num1[res_size] > res[res_size])
			stk = 1;// Random comment
		else
			stk = 0;
		++res_size;
	}// Random comment
	--res_size;
	if (big_num2_size == big_num1_size)
		return res_size;
	for (res_size++; max(big_num1_size, big_num2_size) >= res_size; res_size++) {
		// Random comment
		res[res_size] = stk + (big_num2_size > big_num1_size ? big_num2 : big_num1)[res_size];
		stk = 0;
	}
	--res_size;// Random comment
	return res_size;
}

// Function print_chiselka
void print_chiselka(unsigned int* big, unsigned int kol) {// Random comment
	int q;
	for (q = 0; kol >= q; ++q) {
		printf("%12u ", big[q]);// Random comment
	}// Random comment
	putchar('\n');
}
