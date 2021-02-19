#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func1(unsigned int *big_num1, unsigned int *big_num2, unsigned int *res, size_t big_num1_size, size_t big_num2_size);
int func2(char* resString, unsigned int* Mas);
int name_func(const char *string);
void print_chiselka(unsigned int* big, unsigned int kol);
void print_chiselka_hex(unsigned int* big, unsigned int kol, unsigned int wid);

int main(int argc, char* argv[]) {

	unsigned int *big_num1, *big_num2, *res, big_num1_size, big_num2_size, resutl_size, lenght = (max(strlen(argv[1]), strlen(argv[2]))) / 8, wid;

	big_num1 = (unsigned int*)calloc(lenght, sizeof(int));
	big_num2 = (unsigned int*)calloc(lenght, sizeof(int));
	res = (unsigned int*)calloc(lenght + 1, sizeof(int));

	big_num1_size = func2(argv[1], big_num1);
	big_num2_size = func2(argv[2], big_num2);

	wid = max(big_num1_size, big_num2_size);

	resutl_size = func1(big_num1, big_num2, res, big_num1_size, big_num2_size);
	print_chiselka_hex(big_num1, big_num1_size, wid + 1);
	print_chiselka_hex(big_num2, big_num2_size, wid + 1);
	print_chiselka_hex(res, resutl_size, wid + 1);

	return 0;
}

int func1(unsigned int *big_num1, unsigned int *big_num2, unsigned int *res, size_t big_num1_size, size_t big_num2_size) {

	int resutl_size = 0, stk = 0;

	while (resutl_size <= min(big_num1_size, big_num2_size)) {
		res[resutl_size] = big_num1[resutl_size] + big_num2[resutl_size] + stk;
		if (res[resutl_size] < big_num1[resutl_size] || res[resutl_size] < big_num2[resutl_size])
			stk = 1;
		else
			stk = 0;
		++resutl_size;
	}
	--resutl_size;
	if (big_num1_size == big_num2_size)
		return resutl_size;
	for (resutl_size++; resutl_size <= max(big_num1_size, big_num2_size); resutl_size++) {
		res[resutl_size] = stk + (big_num1_size < big_num2_size ? big_num2 : big_num1)[resutl_size];
		stk = 0;
	}
	--resutl_size;
	return resutl_size;
}

int func2(char* resString, unsigned int* Mas) {
	int q = 0, w = 0, n;
	char string[11] = { '0', 'x', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
	if (resString[0] == '0' && (resString[1] == 'x' || resString[1] == 'X')) {
		while (resString[q + 1] != '\0') {
			string[q % 8 + 2] = resString[q + 2];
			++q;
			if (q % 8 == 0) {
				Mas[w] = name_func(string);
				++w;
			}
		}
		if (q % 8 != 0) {
			Mas[w] = name_func(string);
		}
		if (Mas[w] == 0)
			--w;
	}


	return w;
}
int name_func(const char *string) {
	int atoi = 0, q = 0;
	if (string[0] == '0' && (string[1] == 'x' || string[1] == 'X')) {
		q = 2;
		while (string[q] != '\0') {
			if ('0' <= string[q] && string[q] <= '9')
				atoi = atoi * 16 + (string[q] - '0');
			else if ('A' <= string[q] && string[q] <= 'F')
				atoi = atoi * 16 + (string[q] - 'A') + 10;
			else if ('a' <= string[q] && string[q] <= 'f')
				atoi = atoi * 16 + (string[q] - 'a') + 10;
			else
				return -5;
			++q;
		}
	}
	else {
		while (string[q] != '\0') {
			if ('0' <= string[q] && string[q] <= '9')
				atoi = atoi * 10 + (string[q] - '0');
			else
				return -1;
			++q;
		}
	}
	return atoi;
}
void print_chiselka(unsigned int* big, unsigned int kol) {
	int q;
	for (q = 0; q <= kol; ++q) {
		printf("%12u ", big[q]);
	}
	putchar('\n');
}
void print_chiselka_hex(unsigned int* big, unsigned int kol, unsigned int wid) {
	int q;
	for (q = wid; q >= 0; --q) {
		printf("%0.8x ", big[q]);
	}
	putchar('\n');
}