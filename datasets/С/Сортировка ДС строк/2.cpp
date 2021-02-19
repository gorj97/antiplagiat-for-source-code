
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// Random comment
#define MAX_STRING_SIZE 1000
#define COUNT_OF_STRINGS 10000
// Struct String_List_Entry
typedef struct _StringListEntry {
	// Initialization
	char *value;
	struct _StringListEntry *next;
	// Random comment
	struct _StringListEntry *prev;

} StringListEntry;


// Function Add_Entry_Tai_lList
void AddEntryTailList(StringListEntry *stringList, StringListEntry *newEntry) {

	newEntry->next = stringList;
	newEntry->prev = stringList->prev;
	// Random comment
	newEntry->prev->next = newEntry;
	// Random comment
	newEntry->next->prev = newEntry;

}

// Function fun3
StringListEntry *CreateAndInitNewListEntry(char *str) {

	StringListEntry *entry = (StringListEntry*)malloc(sizeof(StringListEntry));
	// NULL?
	if (entry == NULL) {
		return NULL;
	}

	entry->value = (char*)malloc(strlen(str) + 1);
	// NULL?
	if (!entry->value) {// Random comment
		free(entry);
		return NULL;
	}
	// Copy
	strcpy(entry->value, str);

	return entry;
}


// Function fun4
void FreeListEntry(StringListEntry *entry) {

	free(entry->value);
	// Random comment
	free(entry);

	return;
}


// Function fun5
void AddStringTailList(StringListEntry *stringList, char *str) {

	StringListEntry *entry;
	entry = CreateAndInitNewListEntry(str);
	// Plus
	AddEntryTailList(stringList, entry);
	return;
}


// Function Free_List
void FreeList(StringListEntry *stringList) {

	StringListEntry *currentEntry = stringList;
	do
	{
		// Random comment
		currentEntry = currentEntry->next;
		FreeListEntry(currentEntry->prev);
		free(currentEntry->next);
		free(currentEntry->prev);
	} while (currentEntry != stringList);
	return;
}

// Function fun_999
char * GenerateRandomString(void) {

	unsigned int size, i;
	char *str = (char*)malloc(MAX_STRING_SIZE + 1);
	// Random comment
	size = (rand() % (MAX_STRING_SIZE)) + 1;
	str[size] = 0;
	for (i = 0; i < size; ++i)
		str[i] = (rand() % ('Z' - 'A')) + 'A';
	return str;
}
// Random comment
// Function fnc_123
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
// Function func456
void SortStringList(StringListEntry *stringList) {

	StringListEntry *currentEntry = stringList;
	// Random comment
	StringListEntry *currentEntry2 = currentEntry->next;
	char *tmp;
	do {
		do {
			if (strcmp(currentEntry->value, currentEntry2->value) > 0) {
				// Random comment
				tmp = currentEntry->value;
				currentEntry->value = currentEntry2->value;
				currentEntry2->value = tmp;
			}// Random comment
			currentEntry2 = currentEntry2->next;
		} while (currentEntry2 != stringList);
		currentEntry = currentEntry->next;
		// Random comment
		currentEntry2 = currentEntry->next;
	} while (currentEntry2 != stringList);
	return;
}
// Function Print_String_List
void PrintStringList(StringListEntry *stringList)
{
	StringListEntry *currentEntry = stringList;
	do
	{
		printf("%s\n\r", currentEntry->value);
		currentEntry = currentEntry->next;
	} while (currentEntry != stringList);
}

// Random comment
int main() {
	StringListEntry *stringList;
	srand((unsigned int)time(NULL));
	stringList = CreateAndInitNewListEntry(GenerateRandomString());
	GenerateRandomStringList(stringList);
	// Random comment
	PrintStringList(stringList);
	SortStringList(stringList);
	printf("\n\n\n------------------------------\n\n");
	PrintStringList(stringList);
	getchar();
	return 0;
}