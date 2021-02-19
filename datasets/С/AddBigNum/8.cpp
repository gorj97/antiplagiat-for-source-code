#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRINGS_COUNT   10
#define MAX_STRING_SIZE 10

int AddBigNum(unsigned int *big1, unsigned int *big2, unsigned int *res, size_t big1Size, size_t big2Size);
int StrToHex(char* resString, unsigned int* Mas);
int MyAtoi(const char *str);
void PrintBigNumDec(unsigned int* big, unsigned int kol);
void PrintBigNumHex(unsigned int* big, unsigned int kol, unsigned int wid);

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

int main(int argc, char* argv[]) {

	unsigned int *big1, *big2, *res, big1Size, big2Size, resSize, lenght = (max(strlen(argv[1]), strlen(argv[2]))) / 8, wid;

	big1 = (unsigned int*)calloc(lenght, sizeof(int));
	big2 = (unsigned int*)calloc(lenght, sizeof(int));
	res = (unsigned int*)calloc(lenght + 1, sizeof(int));

	big1Size = StrToHex(argv[1], big1);
	big2Size = StrToHex(argv[2], big2);

	wid = max(big1Size, big2Size);

	resSize = AddBigNum(big1, big2, res, big1Size, big2Size);
	PrintBigNumHex(big1, big1Size, wid + 1);
	PrintBigNumHex(big2, big2Size, wid + 1);
	PrintBigNumHex(res, resSize, wid + 1);

	return 0;
}

void GenerateRandomStrings (char strings[][MAX_STRING_SIZE]) {

	int i = 0;

	for (i;i<STRINGS_COUNT; ++i) {
		GenerateRandomString (strings[i], MAX_STRING_SIZE);
	}

	return;
}

int AddBigNum(unsigned int *big1, unsigned int *big2, unsigned int *res, size_t big1Size, size_t big2Size) {

	int resSize = 0, stk = 0;

	while (resSize <= min(big1Size, big2Size)) {
		res[resSize] = big1[resSize] + big2[resSize] + stk;
		if (res[resSize] < big1[resSize] || res[resSize] < big2[resSize])
			stk = 1;
		else
			stk = 0;
		++resSize;
	}
	--resSize;
	if (big1Size == big2Size)
		return resSize;
	for (resSize++; resSize <= max(big1Size, big2Size); resSize++) {
		res[resSize] = stk + (big1Size < big2Size ? big2 : big1)[resSize];
		stk = 0;
	}
	--resSize;
	return resSize;
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

int StrToHex(char* resString, unsigned int* Mas) {
	int i = 0, k = 0, n;
	char str[11] = { '0', 'x', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
	if (resString[0] == '0' && (resString[1] == 'x' || resString[1] == 'X')) {
		while (resString[i + 1] != '\0') {
			str[i % 8 + 2] = resString[i + 2];
			++i;
			if (i % 8 == 0) {
				Mas[k] = MyAtoi(str);
				++k;
			}
		}
		if (i % 8 != 0) {
			Mas[k] = MyAtoi(str);
		}
		if (Mas[k] == 0)
			--k;
	}


	return k;
}

int StrCmp(const char* _str1, const char* _str2){ //strcmp глючит, еще не разобрался почему
	int i, c=0;
	for (i = 0; i < MAX_STRING_SIZE; ++i){
		c += (int)_str1[i];
		c -= (int)_str2[i];
	}
	return c;

}

int MyAtoi(const char *str) {
	int atoi = 0, i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
		i = 2;
		while (str[i] != '\0') {
			if ('0' <= str[i] && str[i] <= '9')
				atoi = atoi * 16 + (str[i] - '0');
			else if ('A' <= str[i] && str[i] <= 'F')
				atoi = atoi * 16 + (str[i] - 'A') + 10;
			else if ('a' <= str[i] && str[i] <= 'f')
				atoi = atoi * 16 + (str[i] - 'a') + 10;
			else
				return -5;
			++i;
		}
	}
	else {
		while (str[i] != '\0') {
			if ('0' <= str[i] && str[i] <= '9')
				atoi = atoi * 10 + (str[i] - '0');
			else
				return -1;
			++i;
		}
	}
	return atoi;
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

void PrintBigNumDec(unsigned int* big, unsigned int kol) {
	int i;
	for (i = 0; i <= kol; ++i) {
		printf("%12u ", big[i]);
	}
	putchar('\n');
}
void PrintBigNumHex(unsigned int* big, unsigned int kol, unsigned int wid) {
	int i;
	for (i = wid; i >= 0; --i) {
		printf("%0.8x ", big[i]);
	}
	putchar('\n');
}