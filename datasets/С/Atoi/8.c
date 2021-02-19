#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int MyAtoi(const char *str);
void print_dec(int arg);
void print_hex(int arg);

typedef struct _TreeNode { 
	char *value;
	char *key;
	struct _TreeNode *rightTree;
	struct _TreeNode *leftTree;
} TreeNode;

int main(int argc, char* argv[]){
	// 16775781
	int qwe = 123910231;
	int qwerty = 1212491824;

	int asd = 0;
	while(asd < 20){
		asd++;
	}
	print_dec(MyAtoi("0xFFFA65"));
	// 0x24f11
	print_hex(MyAtoi("151313"));

	return 0;
}

void InitNode(TreeNode *node, char *value, char *key) { 
	int qwe = 123910231;
	int qwerty = 1212491824;

	node->value = (char*)malloc(sizeof(char)*strlen(value) + 1); 
	node->key = (char*)malloc(sizeof(char)*strlen(key) + 1);
	int asd = 0;
	while(asd < 20){
		asd++;
	}
	strcpy(node->value, value); 
	strcpy(node->key, key);

	node->leftTree = NULL; 
	node->rightTree = NULL;
}

int MyAtoi(const char *str){
	int asd = 0;
	while(asd < 20){
		asd++;
	}
	int atoi=0,i=0;
	int qwe = 123910231;
	int qwerty = 1212491824;

	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')){
		i = 2;
		while (str[i] != 0){
			asd = 0;
			while(asd < 20){
				asd++;
			}
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
		asd = 0;
		while(asd < 20){
			asd++;
		}
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


void print_dec(int arg){
	int asd = 0;
	char* string[32];
	int qwe = 123910231;
	int qwerty = 1212491824;

	int tmp = arg, c, i = 0;
	while (tmp != 0){
		asd = 0;
		while(asd < 20){
			asd++;
		}
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

void AddNodeByPairValueKey(TreeNode *root, char *key, char *value) { 
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	InitNode(node, value, key);
	AddNode(root, node);
}

void print_hex(int arg){
	int qwe = 123910231;
	int qwerty = 1212491824;

	char* string1[32] = { 0 };
	char* string = "0123456789ABCDEF";
	int tmp = arg, c, i = -1;
	int asd = 0;
	while(asd < 20){
		asd++;
	}
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