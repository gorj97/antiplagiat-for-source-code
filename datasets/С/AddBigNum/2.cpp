#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Random comment
int AddBigNum(unsigned int *big1, unsigned int *big2, unsigned int *res, size_t big1Size, size_t big2Size);
// Random comment
int StrToHex(char* resString, unsigned int* Mas);
int MyAtoi(const char *str);
// Random comment
void PrintBigNumDec(unsigned int* big, unsigned int kol);
void PrintBigNumHex(unsigned int* big, unsigned int kol, unsigned int wid);
// Random comment
// Function main
int main(int argc, char* argv[]) {
	// Random comment
	unsigned int *big1, *big2, *res, big1Size, big2Size, resSize, lenght = (max(strlen(argv[1]), strlen(argv[2]))) / 8, wid;

	big1 = (unsigned int*)calloc(lenght, sizeof(int));
	big2 = (unsigned int*)calloc(lenght, sizeof(int));
	res = (unsigned int*)calloc(lenght + 1, sizeof(int));
	// Random comment
	big1Size = StrToHex(argv[1], big1);
	big2Size = StrToHex(argv[2], big2);

	wid = max(big1Size, big2Size);// Random comment

	resSize = AddBigNum(big1, big2, res, big1Size, big2Size);
	PrintBigNumHex(big1, big1Size, wid + 1);// Random comment
	PrintBigNumHex(big2, big2Size, wid + 1);
	// Random comment
	PrintBigNumHex(res, resSize, wid + 1);

	return 0;
}

// Function AddBigNum
int AddBigNum(unsigned int *big1, unsigned int *big2, unsigned int *res, size_t big1Size, size_t big2Size) {

	int resSize = 0, stk = 0;// Random comment
	// Random comment
	while (resSize <= min(big1Size, big2Size)) {
		res[resSize] = big1[resSize] + big2[resSize] + stk;
		if (res[resSize] < big1[resSize] || res[resSize] < big2[resSize])
			stk = 1;
		else
			stk = 0;
		++resSize;// Random comment
	}
	--resSize;
	if (big1Size == big2Size)// Random comment
		return resSize;
	for (resSize++; resSize <= max(big1Size, big2Size); resSize++) {
		res[resSize] = stk + (big1Size < big2Size ? big2 : big1)[resSize];
		stk = 0;
	}// Random comment
	--resSize;
	return resSize;
}

// Function StrToHex
int StrToHex(char* resString, unsigned int* Mas) {
	int i = 0, k = 0, n;
	// Random comment
	char str[11] = { '0', 'x', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
	if (resString[0] == '0' && (resString[1] == 'x' || resString[1] == 'X')) {
		while (resString[i + 1] != '\0') {// Random comment
			str[i % 8 + 2] = resString[i + 2];
			++i;
			if (i % 8 == 0) {// Random comment
				Mas[k] = MyAtoi(str);
				++k;
			}
		}// Random comment
		if (i % 8 != 0) {
			Mas[k] = MyAtoi(str);
		}
		if (Mas[k] == 0)
			--k;
	}// Random comment
	return k;
}

// Function MyAtoi
int MyAtoi(const char *str) {// Random comment
	int atoi = 0, i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
		i = 2;// Random comment
		while (str[i] != '\0') {
			if ('0' <= str[i] && str[i] <= '9')
				atoi = atoi * 16 + (str[i] - '0');
			else if ('A' <= str[i] && str[i] <= 'F')
				atoi = atoi * 16 + (str[i] - 'A') + 10;// Random comment
			else if ('a' <= str[i] && str[i] <= 'f')
				atoi = atoi * 16 + (str[i] - 'a') + 10;
			else
				return -5;
			++i;
		}
	}// Random comment
	else {
		while (str[i] != '\0') {
			if ('0' <= str[i] && str[i] <= '9')
				atoi = atoi * 10 + (str[i] - '0');
			else
				return -1;// Random comment
			++i;
		}
	}
	return atoi;
}

// Function PrintBigNumDec
void PrintBigNumDec(unsigned int* big, unsigned int kol) {// Random comment
	int i;
	for (i = 0; i <= kol; ++i) {// Random comment
		printf("%12u ", big[i]);
	}// Random comment
	putchar('\n');
}

// Function PrintBigNumHex
void PrintBigNumHex(unsigned int* big, unsigned int kol, unsigned int wid) {
	int i;// Random comment
	for (i = wid; i >= 0; --i) {
		printf("%0.8x ", big[i]);// Random comment
	}// Random comment
	putchar('\n');
}