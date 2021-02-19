#include <stdio.h>

int MyAtoi(const char *str);
void print_dec(int arg);
void print_hex(int arg);

// main
int main(int argc, char* argv[]){
	print_dec(MyAtoi("0xFFFA65"));
	print_hex(MyAtoi("151313"));

	return 0;
}
// Функция переводящая 16-ричное число в 10-ричное и наоборот
int MyAtoi(const char *str){
	
	int atoi=0,i=0;
	// Проверка на 16-ричность
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')){
		i = 2;
		// Перевод
		while (str[i] != 0){
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
// Печать 10-ричного числа
void print_dec(int arg){
	
	char* string[32];
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
// Печать 16-ричного числа
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