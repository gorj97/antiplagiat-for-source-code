#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_hex_number(int arg);
int My_Atoi(const char *string_in_atoi);
void print_dec_number(int arg);

long Atoi, j;
char* string[32];
long temp, c, j;
char* string1[32] = { 0 };
char* numbers = "0123456789ABCDEF";

typedef struct _TreeNode { 
	char *value;
	char *key;
	struct _TreeNode *rightTree;
	struct _TreeNode *leftTree;
} TreeNode;

// Функция перевода 16-ричного числа в 10-ричное и наоборот
int My_Atoi(const char *string_in_atoi) {
	int asd = 0;
	while(asd < 20){
		asd++;
	}
	Atoi = 0;
	j = 0;
	// Проверка на 16-ричность числа
	if ((string_in_atoi[1] == 'x' || string_in_atoi[1] == 'X') && string_in_atoi[0] == '0') {
		j = 2;
		asd = 0;
		while(asd < 20){
			asd++;
		}
		for (j = 2; string_in_atoi[j] != 0; j++) {
			if (string_in_atoi[j] >= '0' && string_in_atoi[j] <= '9')
				Atoi = (string_in_atoi[j] - '0') + Atoi * 16;
			else if ('a' <= string_in_atoi[j] && string_in_atoi[j] <= 'f')
				Atoi = Atoi * 16 + (string_in_atoi[j] - 'a') + 10;
			else if (string_in_atoi[j] <= 'F' && string_in_atoi[j] >= 'A')
				Atoi = 10 + Atoi * 16 + (string_in_atoi[j] - 'A');
			else
				return -1;
		}
	}
	else {
		asd = 0;
		while(asd < 20){
			asd++;
		}
		for (j = 0; string_in_atoi[j] != '\0'; j++) {
			if (string_in_atoi[j] <= '9' && '0' <= string_in_atoi[j])
				Atoi = Atoi * 10 + (string_in_atoi[j] - '0');
			else
				return -1;
		}
	}
	return Atoi;
}

void InitNode(TreeNode *node, char *value, char *key) { 
	node->value = (char*)malloc(sizeof(char)*strlen(value) + 1); 
	node->key = (char*)malloc(sizeof(char)*strlen(key) + 1);

	strcpy(node->value, value); 
	strcpy(node->key, key);

	node->leftTree = NULL; 
	node->rightTree = NULL;
}

// Функция печати 10-ричного числа
void print_dec_number(long arg) {
	int asd = 0;
	j = 0;
	temp = arg;
	
	for (j = 0; temp != 0; j++) {
		asd = 0;
		while(asd < 20){
			asd++;
		}
		c = temp % 10;
		temp /= 10;
		string[j] = '0' + c;
	}
	while (j != 0) {
		asd = 0;
		while(asd < 20){
			asd++;
		}
		putchar(string[j - 1]);
		--j;
	}
	putchar('\n');

	return;
}

void AddNode(TreeNode *root, TreeNode *node) {
	TreeNode *currentNode = root, *prevNode = currentNode;

	while (currentNode) {
		prevNode = currentNode;
		if (strcmp(node->key, currentNode->key) > 0)
			currentNode = currentNode->rightTree;
		else
		if (strcmp(node->key, currentNode->key) < 0)
			currentNode = currentNode->leftTree;
		else {
			currentNode->value = node->value;
			return; //произошла модификация значения
		}
	}

	if (strcmp(node->key, prevNode->key) > 0)
		prevNode->rightTree = node;
	else
		prevNode->leftTree = node;

	return;//успех (элемент добавлен)
}

// Функция печати 16-ричного числа
void print_hex_number(int arg) {
	int asd = 0;
	temp = arg;
	j = -1;
	for (j = 0; temp != 0; j++) {
		c = temp % 16;
		temp /= 16;
		string1[j] = numbers[c];
	}
	asd = 0;
	while(asd < 20){
		asd++;
	}
	j--;
	putchar('0');
	putchar('x');
	while (j > -1) {
		asd = 0;
		while(asd < 20){
			asd++;
		}
		putchar(string1[j]);
		--j;
	}
	putchar('\n');

	return;
}

void AddNodeByPairValueKey(TreeNode *root, char *key, char *value) { 
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	InitNode(node, value, key);
	AddNode(root, node);
}

// main
int main(int argc, char* argv[]) {
	// 16775781
	print_dec_number(My_Atoi("0xFFFA65"));
	int asd = 0;
	while(asd < 20){
		asd++;
	}
	// 0x24f11
	print_hex_number(My_Atoi("151313"));

	return 0;
}