#include <stdio.h>

int My_Atoi(const char *string);
void print_dec_number(int arg);
void print_hex_number(int arg);

int main(int argc, char* argv[]){
	// 16775781
	print_dec_number(My_Atoi("0xFFFA65"));
	// 0x24f11
	print_hex_number(My_Atoi("151313"));

	return 0;
}

int My_Atoi(const char *string){

	int Atoi=0,j=0;
	if (string[0] == '0' && (string[1] == 'x' || string[1] == 'X')){
		j = 2;
		while (string[j] != 0){
			if ('0'<=string[j]&& string[j]<='9')
				Atoi = Atoi * 16 + (string[j] - '0');
			else if ('A' <= string[j] && string[j] <= 'F')
				Atoi = Atoi * 16 + (string[j] - 'A') + 10;
			else if ('a' <= string[j] && string[j] <= 'f')
				Atoi = Atoi * 16 + (string[j] - 'a') + 10;
			else
				return -1;
			++j;
		}
	}
	else{
		while (string[j] != '\0'){
			if ('0' <= string[j] && string[j] <= '9')
				Atoi = Atoi * 10 + (string[j] - '0');
			else
				return -1;
			++j;
		}
	}
	return Atoi;
}
void print_dec_number(int arg){
	
	char* str[32];
	int temp = arg, c, j = 0;;
	while (temp != 0){
		c = temp % 10;
		str[j] = c + '0';
		temp /= 10;
		++j;
	}
	while (j != 0){
		putchar(str[j-1]);
		--j;
	}
	putchar('\n');
	
	return;
}
void print_hex_number(int arg){
	
	char* str1[32] = { 0 };
	char* str = "0123456789ABCDEF";
	int temp = arg, c, j = -1;
	while (temp != 0){
		++j;
		c = temp % 16;
		str1[j] = str[c];
		temp /= 16;
	}
	putchar('0');
	putchar('x');
	while (j>-1){
		putchar(str1[j]);
		--j;
	}
	putchar('\n');
	
	return;
}