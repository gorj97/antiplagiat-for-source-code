
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// Random comment
// struct String_List_Entry
typedef struct struct1 {
	// initialization vars
	struct struct1 *sleduushiy;
	char *val;
	// Random comment
	struct struct1 *predidushiy;

} String_List_Entry;



// Function fun3
String_List_Entry *fun3(char *str) {

	String_List_Entry *entry = (String_List_Entry*)malloc(sizeof(String_List_Entry));
	// NULL?
	if (entry == NULL) {
		return NULL;
	}

	entry->val = (char*)malloc(strlen(str) + 1);
	if (!entry->val) {
		// Random comment
		free(entry);
		return NULL;
	}
	// Copy
	strcpy(entry->val, str);

	return entry;
}


// Function Add_Entry_Tai_lList
void Add_Entry_Tai_lList(String_List_Entry *list_string, String_List_Entry *new_Entry) {

	new_Entry->predidushiy = list_string->predidushiy;
	new_Entry->sleduushiy = list_string;
	// Random comment
	// Random comment
	new_Entry->sleduushiy->predidushiy = new_Entry;
	new_Entry->predidushiy->sleduushiy = new_Entry;

}


// Function fun5
void fun5(String_List_Entry *list_string, char *str) {

	String_List_Entry *entry;
	entry = fun3(str);
	// Plus
	Add_Entry_Tai_lList(list_string, entry);
	return;
}


// Function fun4
void fun4(String_List_Entry *entry) {

	free(entry->val);
	// Random comment
	free(entry);

	return;
}


// Function fun_999
long siz, j;
char *str;
char * fun_999(void) {
	int MAX_STRING_SIZE = 1000;
	int COUNT_OF_STRINGS = 10000;
	
	siz = (rand() % (MAX_STRING_SIZE)) + 1;
	str = (char*)malloc(MAX_STRING_SIZE + 1);
	// Random comment
	str[siz] = 0;
	j = 0;
	while(j < siz){
		str[j] = (rand() % ('Z' - 'A')) + 'A';
		j++;
	}
	return str;
}


// Function Free_List
void Free_List(String_List_Entry *list_string) {

	String_List_Entry *cur_entry = list_string;
	do
	{
		cur_entry = cur_entry->sleduushiy;
		// Random comment
		fun4(cur_entry->predidushiy);
		free(cur_entry->sleduushiy);
		free(cur_entry->predidushiy);
	} while (list_string != cur_entry);
	return;
}


char *temp;
// Function func456
void func456(String_List_Entry *list_string) {
	// Random comment
	String_List_Entry *cur_entry = list_string;
	String_List_Entry *currentEntry2 = cur_entry->sleduushiy;
	// Random comment
	do {
		do {
			if (strcmp(cur_entry->val, currentEntry2->val) > 0) {
				// Random comment
				temp = currentEntry2->val;
				currentEntry2->val = cur_entry->val;
				cur_entry->val = temp;
			}
			// Random comment
			currentEntry2 = currentEntry2->sleduushiy;
		} while (list_string != currentEntry2);
		currentEntry2 = cur_entry->sleduushiy;
		cur_entry = cur_entry->sleduushiy;
		// Random comment
	} while (list_string != currentEntry2);
	return;
}


// Random comment
// Function fnc_123
void fnc_123(String_List_Entry *nachalniy_Entry) {
	int MAX_STRING_SIZE = 1000;
	int COUNT_OF_STRINGS = 10000;

	nachalniy_Entry->sleduushiy = nachalniy_Entry;
	nachalniy_Entry->predidushiy = nachalniy_Entry;
	j = 0;
	while(COUNT_OF_STRINGS > j)
	{		
		fun5(nachalniy_Entry, fun_999());
		j++;
	}
	return;
}

// Function Print_String_List
void Print_String_List(String_List_Entry *list_string)
{
	String_List_Entry *cur_entry = list_string;
	do
	{
		// Random comment
		printf("%s\n\r", cur_entry->val);
		cur_entry = cur_entry->sleduushiy;
	} while (list_string != cur_entry);
}

int main() {
	// Random comment
	String_List_Entry *list_string;
	srand((unsigned int)time(NULL));
	list_string = fun3(fun_999());
	fnc_123(list_string);
	Print_String_List(list_string);
	// Random comment
	func456(list_string);
	printf("\n\n\n------------------------------\n\n");
	Print_String_List(list_string);
	// Stop
	getchar();
	return 0;
}