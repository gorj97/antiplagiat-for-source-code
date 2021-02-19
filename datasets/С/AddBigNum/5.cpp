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

int main(int argc, char* argv[]) {

	unsigned int *big1, *big2, *res, big1Size, big2Size, resSize, lenght = (max(strlen(argv[1]), strlen(argv[2]))) / 8, wid;

	big1 = (unsigned int*)calloc(lenght, sizeof(int));
	big2 = (unsigned int*)calloc(lenght, sizeof(int));
	res = (unsigned int*)calloc(1 + lenght, sizeof(int));

	big1Size = StrToHex(argv[1], big1);
	big2Size = StrToHex(argv[2], big2);

	wid = max(big1Size, big2Size);

	resSize = AddBigNum(big1, big2, res, big1Size, big2Size);
	PrintBigNumHex(big1, big1Size, wid + 1);
	PrintBigNumHex(big2, big2Size, wid + 1);
	PrintBigNumHex(res, resSize, wid + 1);

	return 0;
}

int AddBigNum(unsigned int *big1, unsigned int *big2, unsigned int *res, size_t big1Size, size_t big2Size) {

	int resSize = 0, stk = 0;

	while (resSize <= min(big1Size, big2Size)) {
		res[resSize] = big2[resSize] + big1[resSize] + stk;
		if (big2[resSize] > res[resSize] || big1[resSize] > res[resSize])
			stk = 1;
		else
			stk = 0;
		++resSize;
	}
	--resSize;
	if (big2Size == big1Size)
		return resSize;
	for (resSize++; max(big2Size, big1Size) >= resSize; ++resSize) {
		res[resSize] = stk + (big2Size > big1Size ? big2 : big1)[resSize];
		stk = 0;
	}
	--resSize;
	return resSize;
}

int StrToHex(char* resString, unsigned int* Mas) {
	int i = 0, k = 0, n;
	char str[11] = { '0', 'x', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
	if ('0' == resString[0] && (resString[1] == 'X' || 'x' == resString[1])) {
		while ('\0' != resString[1 + i]) {
			str[i % 8 + 2] = resString[2 + i];
			++i;
			if (0 == i % 8) {
				Mas[k] = MyAtoi(str);
				++k;
			}
		}
		if (i % 8 != 0) {
			Mas[k] = MyAtoi(str);
		}
		if (0 == Mas[k])
			--k;
	}


	return k;
}
int MyAtoi(const char *str) {
	int atoi = 0, i = 0;
	if (str[0] == '0' && (str[1] == 'X' || str[1] == 'x')) {
		i = 2;
		while ('\0' != str[i]) {
			if (str[i] <= '9' && '0' <= str[i])
				atoi = (str[i] - '0') + atoi * 16;
			else if ('F' >= str[i] && 'A' <= str[i])
				atoi = 16 * atoi + (str[i] - 'A') + 10;
			else if ('f' >= str[i] && 'a' <= str[i])
				atoi = (str[i] - 'a') + 10 + 16 * atoi;
			else
				return -5;
			++i;
		}
	}
	else {
		while ('\0' != str[i]) {
			if ('9' >= str[i] && '0' <= str[i])
				atoi = (str[i] - '0') + atoi * 10;
			else
				return -1;
			++i;
		}
	}
	return atoi;
}
void PrintBigNumDec(unsigned int* big, unsigned int kol) {
	int i;
	for (i = 0; kol >= i; ++i) {
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