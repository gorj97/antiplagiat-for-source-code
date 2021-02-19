
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

	if (entry == NULL) {
		return NULL;
	}

	entry->value = (char*)malloc(strlen(str) + 1);
	if (!entry->value) {
		free(entry);
		return NULL;
	}

	strcpy(entry->value, str);

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
	} while (currentEntry != stringList);
	return;
}

unsigned int size, i;
char *str;
char * GenerateRandomString(void) {
	int MAX_STRING_SIZE = 1000;
	int COUNT_OF_STRINGS = 10000;

	str = (char*)malloc(MAX_STRING_SIZE + 1);
	size = (rand() % (MAX_STRING_SIZE)) + 1;
	str[size] = 0;
	for (i = 0; i < size; ++i)
		str[i] = (rand() % ('Z' - 'A')) + 'A';
	return str;
}

void GenerateRandomStringList(StringListEntry *startEntry) {
	int MAX_STRING_SIZE = 1000;
	int COUNT_OF_STRINGS = 10000;
	
	startEntry->prev = startEntry;
	startEntry->next = startEntry;
	for (i = 0; i < COUNT_OF_STRINGS; ++i)
	{		
		AddStringTailList(startEntry, GenerateRandomString());
	}
	return;
}

char *tmp;
void SortStringList(StringListEntry *stringList) {

	StringListEntry *currentEntry = stringList;
	StringListEntry *currentEntry2 = currentEntry->next;
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
	StringListEntry *currentEntry = stringList;
	do
	{
		printf("%s\n\r", currentEntry->value);
		currentEntry = currentEntry->next;
	} while (currentEntry != stringList);
}

StringListEntry *stringList;
int main() {
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