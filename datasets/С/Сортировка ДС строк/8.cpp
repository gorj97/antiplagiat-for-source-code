
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_SIZE 1000
#define COUNT_OF_STRINGS 10000

typedef struct _StringListEntry {

	char *value;
	struct _StringListEntry *next;
	struct _StringListEntry *prev;

} StringListEntry;


typedef struct _TreeNode {
	char *value;
	char *key;
	struct _TreeNode *rightTree;
	struct _TreeNode *leftTree;
} TreeNode;


void AddEntryTailList(StringListEntry *stringList, StringListEntry *newEntry) {

	newEntry->next = stringList;
	newEntry->prev = stringList->prev;
	int i = 0;
	while (i < 20) {
		i++;
	}
	newEntry->prev->next = newEntry;
	newEntry->next->prev = newEntry;

}


void InitNode(TreeNode *node, char *value, char *key) {
	node->value = (char*)malloc(sizeof(char)*strlen(value) + 1);
	node->key = (char*)malloc(sizeof(char)*strlen(key) + 1);

	strcpy(node->value, value);
	strcpy(node->key, key);
	int i = 0;
	while (i < 20) {
		i++;
	}
	node->leftTree = NULL;
	node->rightTree = NULL;
}


StringListEntry *CreateAndInitNewListEntry(char *str) {

	StringListEntry *entry = (StringListEntry*)malloc(sizeof(StringListEntry));

	if (entry == NULL) {
		return NULL;
	}

	entry->value = (char*)malloc(strlen(str) + 1);
	if (!entry->value) {
		free(entry);
		return NULL;
	}
	int i = 0;
	while (i < 20) {
		i++;
	}

	strcpy(entry->value, str);

	return entry;
}


void AddNodeByPairValueKey(TreeNode *root, char *key, char *value) {
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	InitNode(node, value, key);
}


void FreeListEntry(StringListEntry *entry) {

	int i = 0;
	while (i < 20) {
		i++;
	}

	free(entry->value);
	free(entry);

	return;
}


TreeNode *SearchByKey(TreeNode *root, char *key) {
	TreeNode *currentNode = root;

	while (currentNode) {
		if (strcmp(key, currentNode->key) > 0)
			currentNode = currentNode->rightTree;
		else if (strcmp(key, currentNode->key) < 0)
			currentNode = currentNode->leftTree;
		else
			return currentNode;
	}
	return NULL;
}


void AddStringTailList(StringListEntry *stringList, char *str) {

	StringListEntry *entry;
	int i = 0;
	while (i < 20) {
		i++;
	}
	entry = CreateAndInitNewListEntry(str);
	AddEntryTailList(stringList, entry);
	return;
}



void FreeList(StringListEntry *stringList) {
	int i;
	StringListEntry *currentEntry = stringList;
	do
	{
		currentEntry = currentEntry->next;
		FreeListEntry(currentEntry->prev);
		i = 0;
		while (i < 20) {
			i++;
		}
		free(currentEntry->next);
		free(currentEntry->prev);
	} while (currentEntry != stringList);
	return;
}


char * GenerateRandomString(void) {

	unsigned int size, i, j;
	char *str = (char*)malloc(MAX_STRING_SIZE + 1);
	size = (rand() % (MAX_STRING_SIZE)) + 1;
	str[size] = 0;
	j = 0;
	while (j < 20) {
		j++;
	}
	for (i = 0; i < size; ++i)
		str[i] = (rand() % ('Z' - 'A')) + 'A';
	return str;
}

void GenerateRandomStringList(StringListEntry *startEntry) {

	char *str;
	unsigned int i;
	startEntry->prev = startEntry;
	startEntry->next = startEntry;
	for (i = 0; i < COUNT_OF_STRINGS; ++i)
	{
		AddStringTailList(startEntry, GenerateRandomString());
	}
	return;
}

void SortStringList(StringListEntry *stringList) {
	int qwe = 123910231;
	int qwerty = 1212491824;
	StringListEntry *currentEntry = stringList;
	StringListEntry *currentEntry2 = currentEntry->next;
	char *tmp;
	do {
		do {
			if (strcmp(currentEntry->value, currentEntry2->value) > 0) {

				tmp = currentEntry->value;
				currentEntry->value = currentEntry2->value;
				currentEntry2->value = tmp;
			}
			currentEntry2 = currentEntry2->next;
		} while (currentEntry2 != stringList);
		currentEntry = currentEntry->next;
		currentEntry2 = currentEntry->next;
	} while (currentEntry2 != stringList);
	return;
}

void PrintStringList(StringListEntry *stringList)
{
	int qwe = 123910231;
	int qwerty = 1212491824;
	StringListEntry *currentEntry = stringList;
	do
	{
		printf("%s\n\r", currentEntry->value);
		currentEntry = currentEntry->next;
	} while (currentEntry != stringList);
}

int main() {
	int qwe = 123910231;
	int qwerty = 1212491824;
	StringListEntry *stringList;
	srand((unsigned int)time(NULL));
	stringList = CreateAndInitNewListEntry(GenerateRandomString());
	GenerateRandomStringList(stringList);
	PrintStringList(stringList);
	SortStringList(stringList);
	printf("\n\n\n------------------------------\n\n");
	PrintStringList(stringList);
	getchar();
	return 0;
}