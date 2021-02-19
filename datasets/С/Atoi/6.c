#include <stdio.h>

int MyAtoi(const char *str);
void print_dec(int arg);
void print_hex(int arg);

int main(int argc, char* argv[]) {
	// 16775781
	print_dec(MyAtoi("0xFFFA65"));
	// 0x24f11
	print_hex(MyAtoi("151313"));

	return 0;
}

int MyAtoi(const char *str) {

	long atoi = 0, i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
		i = 2;
		for (i = 2; str[i] != 0; i++) {
			if ('0' <= str[i] && str[i] <= '9')
				atoi = atoi * 16 + (str[i] - '0');
			else if ('A' <= str[i] && str[i] <= 'F')
				atoi = atoi * 16 + (str[i] - 'A') + 10;
			else if ('a' <= str[i] && str[i] <= 'f')
				atoi = atoi * 16 + (str[i] - 'a') + 10;
			else
				return -1;
		}
	}
	else {
		for (i = 0; str[i] != '\0'; i++) {
			if ('0' <= str[i] && str[i] <= '9')
				atoi = atoi * 10 + (str[i] - '0');
			else
				return -1;
		}
	}
	return atoi;
}
void print_dec(long arg) {

	char* string[32];
	long tmp = arg, c, i = 0;
	for (i = 0; tmp != 0; i++) {
		c = tmp % 10;
		string[i] = c + '0';
		tmp /= 10;
	}
	while (i != 0) {
		putchar(string[i - 1]);
		--i;
	}
	putchar('\n');

	return;
}
void print_hex(int arg) {

	char* string1[32] = { 0 };
	char* string = "0123456789ABCDEF";
	long tmp = arg, c, i = -1;
	for (i = 0; tmp != 0; i++) {
		c = tmp % 16;
		string1[i] = string[c];
		tmp /= 16;
	}
	i--;
	putchar('0');
	putchar('x');
	while (i > -1) {
		putchar(string1[i]);
		--i;
	}
	putchar('\n');

	return;
}