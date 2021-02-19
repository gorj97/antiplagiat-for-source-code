
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


char * GenerateRandomString(void) {

	long size, i;
	char *str = (char*)malloc(MAX_STRING_SIZE + 1);
	size = (rand() % (MAX_STRING_SIZE)) + 1;
	str[size] = 0;
	i = 0;
	while(i < size){
		str[i] = (rand() % ('Z' - 'A')) + 'A';
		i++;
	}	
	return str;
}

void GenerateRandomStringList(StringListEntry *startEntry) {

	char *str;
	long i;
	startEntry->prev = startEntry;
	startEntry->next = startEntry;
	i = 0;
	while(i < COUNT_OF_STRINGS)
	{		
		AddStringTailList(startEntry, GenerateRandomString());
		i++;
	}
	return;
}

void SortStringList(StringListEntry *stringList) {

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