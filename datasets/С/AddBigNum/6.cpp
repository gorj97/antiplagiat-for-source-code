#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long AddBigNum(unsigned long *big1, unsigned long *big2, unsigned long *res, size_t big1Size, size_t big2Size);
long StrToHex(char* resString, unsigned long* Mas);
long MyAtoi(const char *str);
void PrintBigNumDec(unsigned long* big, unsigned long kol);
void PrintBigNumHex(unsigned long* big, unsigned long kol, unsigned long wid);

long main(long argc, char* argv[]) {

	unsigned long *big1, *big2, *res, big1Size, big2Size, resSize, lenght = (max(strlen(argv[1]), strlen(argv[2]))) / 8, wid;

	big1 = (unsigned long*)calloc(lenght, sizeof(long));
	big2 = (unsigned long*)calloc(lenght, sizeof(long));
	res = (unsigned long*)calloc(lenght + 1, sizeof(long));

	big1Size = StrToHex(argv[1], big1);
	big2Size = StrToHex(argv[2], big2);

	wid = max(big1Size, big2Size);

	resSize = AddBigNum(big1, big2, res, big1Size, big2Size);
	PrintBigNumHex(big1, big1Size, wid + 1);
	PrintBigNumHex(big2, big2Size, wid + 1);
	PrintBigNumHex(res, resSize, wid + 1);

	return 0;
}

long AddBigNum(unsigned long *big1, unsigned long *big2, unsigned long *res, size_t big1Size, size_t big2Size) {

	long resSize, stk = 0;
	for(resSize = 0; resSize <= min(big1Size, big2Size); resSize++){
		res[resSize] = big1[resSize] + big2[resSize] + stk;
		if (res[resSize] < big1[resSize] || res[resSize] < big2[resSize])
			stk = 1;
		else
			stk = 0;
	}
	if (big1Size == big2Size)
		return resSize;
	while(resSize <= max(big1Size, big2Size)){
		res[resSize] = stk + (big1Size < big2Size ? big2 : big1)[resSize];
		stk = 0;
		resSize++;
	}
	--resSize;
	return resSize;
}

long StrToHex(char* resString, unsigned long* Mas) {
	long i = 0, k = 0, n;
	char str[11] = { '0', 'x', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
	if (resString[0] == '0' && (resString[1] == 'x' || resString[1] == 'X')) {
		for(i = 0; resString[i + 1] != '\0';){
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
long MyAtoi(const char *str) {
	long atoi = 0, i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
		for(i = 2; str[i] != '\0'; i++){
			if ('0' <= str[i] && str[i] <= '9')
				atoi = atoi * 16 + (str[i] - '0');
			else if ('A' <= str[i] && str[i] <= 'F')
				atoi = atoi * 16 + (str[i] - 'A') + 10;
			else if ('a' <= str[i] && str[i] <= 'f')
				atoi = atoi * 16 + (str[i] - 'a') + 10;
			else
				return -5;
		}
	}
	else {
		for(i = 0; str[i] != '\0'; i++){
			if ('0' <= str[i] && str[i] <= '9')
				atoi = atoi * 10 + (str[i] - '0');
			else
				return -1;
		}
	}
	return atoi;
}
void PrintBigNumDec(unsigned long* big, unsigned long kol) {
	long i = 0;
	while(i <= kol){
		printf("%12u ", big[i]);
		i++;
	}
	putchar('\n');
}
void PrintBigNumHex(unsigned long* big, unsigned long kol, unsigned long wid) {
	long i = wid;
	while(i >= 0){
		printf("%0.8x ", big[i]);
		i++;
	}
	putchar('\n');
}