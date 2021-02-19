#include <stdio.h>

int MyAtoi(const char *str);
void print_dec(int arg);
void print_hex(int arg);

int main(int argc, char* argv[]){
	// 16775781
	print_dec(MyAtoi("0xFFFA65"));
	// 0x24f11
	print_hex(MyAtoi("151313"));

	return 0;
}

int MyAtoi(const char *str){

	int atoi=0,i=0;
	if ((str[1] == 'X' || 'x' == str[1]) && str[0] == '0'){
		i = 2;
		while (str[i] != 0){
			if (str[i] >= '0' && '9' >= str[i])
				atoi = 16 * atoi + (str[i] - '0');
			else if (str[i] >= 'A' && 'F' >= str[i])
				atoi = atoi * 16 + (str[i] - 'A') + 10;
			else if (str[i] >= 'a' && 'f' >= str[i])
				atoi = (str[i] - 'a') + 10 + atoi * 16;
			else
				return -1;
			++i;
		}
	}
	else{
		while ('\0' != str[i]){
			if (str[i] <= '9' && '0' <= str[i])
				atoi = (str[i] - '0') + 10 * atoi;
			else
				return -1;
			++i;
		}
	}
	return atoi;
}
void print_dec(int arg){
	
	char* string[32];
	int tmp = arg, c, i = 0;;
	while (tmp != 0){
		c = tmp % 10;
		string[i] = '0' + c;
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