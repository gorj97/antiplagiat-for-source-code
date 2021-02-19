
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_SIZE 1000
#define COUNT_OF_STRINGS 10000

typedef struct _StringListEntry {

	struct _StringListEntry *next;
	char *value;
	struct _StringListEntry *prev;

} StringListEntry;


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


void AddEntryTailList(StringListEntry *stringList, StringListEntry *newEntry) {

	newEntry->prev = stringList->prev;
	newEntry->next = stringList;
	newEntry->next->prev = newEntry;
	newEntry->prev->next = newEntry;

}


void AddStringTailList(StringListEntry *stringList, char *str) {

	StringListEntry *entry;
	entry = CreateAndInitNewListEntry(str);
	AddEntryTailList(stringList, entry);
	return;
}


void FreeListEntry(StringListEntry *entry) {

	free(entry->value);
	free(entry);

	return;
}


char * GenerateRandomString(void) {

	unsigned int size, i;
	char *str = (char*)malloc(MAX_STRING_SIZE + 1);
	size = (rand() % (MAX_STRING_SIZE)) + 1;
	str[size] = 0;
	for (i = 0; i < size; ++i)
		str[i] = (rand() % ('Z' - 'A')) + 'A';
	return str;
}


void FreeList(StringListEntry *stringList) {

	StringListEntry *currentEntry = stringList;
	do
	{
		currentEntry = currentEntry->next;
		FreeListEntry(currentEntry->prev);
		free(currentEntry->prev);
		free(currentEntry->next);
	} while (currentEntry != stringList);
	return;
}

void GenerateRandomStringList(StringListEntry *startEntry) {

	unsigned int i;
	char *str;
	startEntry->next = startEntry;
	startEntry->prev = startEntry;
	for (i = 0; i < COUNT_OF_STRINGS; ++i)
	{
		AddStringTailList(startEntry, GenerateRandomString());
	}
	return;
}

void SortStringList(StringListEntry *stringList) {

	char *tmp;

	StringListEntry *currentEntry = stringList;
	StringListEntry *currentEntry2 = currentEntry->next;

	do {
		do {
			if (strcmp(currentEntry->value, currentEntry2->value) > 0) {

				tmp = currentEntry2->value;
				currentEntry2->value = currentEntry->value;
				currentEntry->value = tmp;
			}
			currentEntry2 = currentEntry2->next;
		} while (currentEntry2 != stringList);
		currentEntry2 = currentEntry->next;
		currentEntry = currentEntry->next;
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