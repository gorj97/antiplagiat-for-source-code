#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int AddBigNum(unsigned int *big1, unsigned int *big2, unsigned int *res, size_t big1Size, size_t big2Size);
int StrToHex(char* resString, unsigned int* Mas);
int MyAtoi(const char *str);
void PrintBigNumDec(unsigned int* big, unsigned int kol);
void PrintBigNumHex(unsigned int* big, unsigned int kol, unsigned int wid);

unsigned int *big1, *big2, *res, big1Size, big2Size, resSize, lenght, wid;

int main(int argc, char* argv[]) {

	lenght = (max(strlen(argv[1]), strlen(argv[2]))) / 8;

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

int result_size, stk;
int AddBigNum(unsigned int *big1, unsigned int *big2, unsigned int *res, size_t big1Size, size_t big2Size) {

	result_size = 0; 
	stk = 0;

	while (result_size <= min(big1Size, big2Size)) {
		res[result_size] = big1[result_size] + big2[result_size] + stk;
		if (res[result_size] < big1[result_size] || res[result_size] < big2[result_size])
			stk = 1;
		else
			stk = 0;
		++result_size;
	}
	--result_size;
	if (big1Size == big2Size)
		return result_size;
	for (result_size++; result_size <= max(big1Size, big2Size); result_size++) {
		res[result_size] = stk + (big1Size < big2Size ? big2 : big1)[result_size];
		stk = 0;
	}
	--result_size;
	return result_size;
}

char string[11] = { '0', 'x', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
int StrToHex(char* resString, unsigned int* Mas) {
	int i = 0, k = 0, n;
	if (resString[0] == '0' && (resString[1] == 'x' || resString[1] == 'X')) {
		while (resString[i + 1] != '\0') {
			string[i % 8 + 2] = resString[i + 2];
			++i;
			if (i % 8 == 0) {
				Mas[k] = MyAtoi(string);
				++k;
			}
		}
		if (i % 8 != 0) {
			Mas[k] = MyAtoi(string);
		}
		if (Mas[k] == 0)
			--k;
	}


	return k;
}

int MyAtoi(const char *str) {
	int i = 0;
	int atoi = 0;
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