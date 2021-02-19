
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



void AddEntryTailList(StringListEntry *stringList, StringListEntry *newEntry) {

	newEntry->next = stringList;
	newEntry->prev = stringList->prev;
	newEntry->prev->next = newEntry;
	newEntry->next->prev = newEntry;

}


StringListEntry *CreateAndInitNewListEntry(char *str) {

	StringListEntry *entry = (StringListEntry*)malloc(sizeof(StringListEntry));

	if (NULL == entry) {
		return NULL;
	}

	entry->value = (char*)malloc(strlen(str) + 1);
	if (entry->value) {
		strcpy(entry->value, str);
	}
	else{
		free(entry);
		return NULL;
	}

	return entry;
}



void FreeListEntry(StringListEntry *entry) {

	free(entry->value);
	free(entry);

	return;
}



void AddStringTailList(StringListEntry *stringList, char *str) {

	StringListEntry *entry;
	entry = CreateAndInitNewListEntry(str);
	AddEntryTailList(stringList, entry);
	return;
}



void FreeList(StringListEntry *stringList) {

	StringListEntry *currentEntry = stringList;
	do
	{
		currentEntry = currentEntry->next;
		FreeListEntry(currentEntry->prev);
		free(currentEntry->next);
		free(currentEntry->prev);
	} while (stringList != currentEntry);
	return;
}


char * GenerateRandomString(void) {

	unsigned int size, i;
	char *str = (char*)malloc(1 + MAX_STRING_SIZE);
	size = 1 + (rand() % (MAX_STRING_SIZE));
	str[size] = 0;
	for (i = 0; size > i; i++)
		str[i] = (rand() % ('Z' - 'A')) + 'A';
	return str;
}

void GenerateRandomStringList(StringListEntry *startEntry) {

	char *str;
	unsigned int i;
	startEntry->prev = startEntry;
	startEntry->next = startEntry;
	for (i = 0; COUNT_OF_STRINGS > i; ++i)
	{		
		AddStringTailList(startEntry, GenerateRandomString());
	}
	return;
}

void SortStringList(StringListEntry *stringList) {

	StringListEntry *currentEntry = stringList;
	StringListEntry *currentEntry2 = currentEntry->next;
	char *tmp;
	do {
		do {
			if (0 < strcmp(currentEntry2->value, currentEntry->value)) {

				tmp = currentEntry->value;
				currentEntry->value = currentEntry2->value;
				currentEntry2->value = tmp;
			}
			currentEntry2 = currentEntry2->next;
		} while (stringList != currentEntry2);
		currentEntry = currentEntry->next;
		currentEntry2 = currentEntry->next;
	} while (stringList != currentEntry2);
	return;
}

void PrintStringList(StringListEntry *stringList)
{
	StringListEntry *currentEntry = stringList;
	do
	{
		printf("%s\n\r", currentEntry->value);
		currentEntry = currentEntry->next;
	} while (stringList != currentEntry);
}

int main() {
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