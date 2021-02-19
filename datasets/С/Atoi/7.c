#include <stdio.h>

void print_dec(int arg);
void print_hex(int arg);
int MyAtoi(const char *str);

int MyAtoi(const char *str){

	int atoi=0,i=0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')){
		i = 2;
		while (str[i] != 0){
			if ('0'<=str[i]&& str[i]<='9')
				atoi = atoi * 16 + (str[i] - '0');
			else if ('a' <= str[i] && str[i] <= 'f')
				atoi = atoi * 16 + (str[i] - 'a') + 10;
			else if ('A' <= str[i] && str[i] <= 'F')
				atoi = atoi * 16 + (str[i] - 'A') + 10;
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
void print_dec(int arg){
	
	int tmp = arg, c, i = 0;
	char* string[32];
	while (tmp != 0){
		c = tmp % 10;
		tmp /= 10;
		string[i] = c + '0';
		++i;
	}
	while (i != 0){
		putchar(string[i-1]);
		--i;
	}
	putchar('\n');
	
	return;
}
void print_hex(int arg){
	
	int tmp = arg, c, i = -1;
	char* string = "0123456789ABCDEF";
	char* string1[32] = { 0 };
	
	while (tmp != 0){
		++i;
		c = tmp % 16;
		tmp /= 16;
		string1[i] = string[c];
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

int main(int argc, char* argv[]){
	// 16775781
	print_dec(MyAtoi("0xFFFA65"));
	// 0x24f11
	print_hex(MyAtoi("151313"));

	return 0;
}