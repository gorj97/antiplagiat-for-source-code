
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_SIZE 1000
#define COUNT_OF_STRINGS 10000

typedef struct struct1 {

	char *val;
	struct struct1 *sleduushiy;
	struct struct1 *predidushiy;

} String_List_Entry;



void Add_Entry_Tai_lList(String_List_Entry *list_string, String_List_Entry *new_Entry) {

	new_Entry->sleduushiy = list_string;
	new_Entry->predidushiy = list_string->predidushiy;
	new_Entry->predidushiy->sleduushiy = new_Entry;
	new_Entry->sleduushiy->predidushiy = new_Entry;

}


String_List_Entry *fun3(char *str) {

	String_List_Entry *entry = (String_List_Entry*)malloc(sizeof(String_List_Entry));

	if (entry == NULL) {
		return NULL;
	}

	entry->val = (char*)malloc(strlen(str) + 1);
	if (!entry->val) {
		free(entry);
		return NULL;
	}

	strcpy(entry->val, str);

	return entry;
}



void fun4(String_List_Entry *entry) {

	free(entry->val);
	free(entry);

	return;
}



void fun5(String_List_Entry *list_string, char *str) {

	String_List_Entry *entry;
	entry = fun3(str);
	Add_Entry_Tai_lList(list_string, entry);
	return;
}



void Free_List(String_List_Entry *list_string) {

	String_List_Entry *cur_entry = list_string;
	do
	{
		cur_entry = cur_entry->sleduushiy;
		fun4(cur_entry->predidushiy);
		free(cur_entry->sleduushiy);
		free(cur_entry->predidushiy);
	} while (cur_entry != list_string);
	return;
}


char * fun_999(void) {

	unsigned int siz, j;
	char *str = (char*)malloc(MAX_STRING_SIZE + 1);
	siz = (rand() % (MAX_STRING_SIZE)) + 1;
	str[siz] = 0;
	for (j = 0; j < siz; ++j)
		str[j] = (rand() % ('Z' - 'A')) + 'A';
	return str;
}

void fnc_123(String_List_Entry *nachalniy_Entry) {

	char *str;
	unsigned int j;
	nachalniy_Entry->predidushiy = nachalniy_Entry;
	nachalniy_Entry->sleduushiy = nachalniy_Entry;
	for (j = 0; j < COUNT_OF_STRINGS; ++j)
	{		
		fun5(nachalniy_Entry, fun_999());
	}
	return;
}

void func456(String_List_Entry *list_string) {

	String_List_Entry *cur_entry = list_string;
	String_List_Entry *currentEntry2 = cur_entry->sleduushiy;
	char *temp;
	do {
		do {
			if (strcmp(cur_entry->val, currentEntry2->val) > 0) {

				temp = cur_entry->val;
				cur_entry->val = currentEntry2->val;
				currentEntry2->val = temp;
			}
			currentEntry2 = currentEntry2->sleduushiy;
		} while (currentEntry2 != list_string);
		cur_entry = cur_entry->sleduushiy;
		currentEntry2 = cur_entry->sleduushiy;
	} while (currentEntry2 != list_string);
	return;
}

void Print_String_List(String_List_Entry *list_string)
{
	String_List_Entry *cur_entry = list_string;
	do
	{
		printf("%s\n\r", cur_entry->val);
		cur_entry = cur_entry->sleduushiy;
	} while (cur_entry != list_string);
}

int main() {
	String_List_Entry *list_string;
	srand((unsigned int)time(NULL));
	list_string = fun3(fun_999());
	fnc_123(list_string);
	Print_String_List(list_string);
	func456(list_string);
	printf("\n\n\n------------------------------\n\n");
	Print_String_List(list_string);
	getchar();
	return 0;
}