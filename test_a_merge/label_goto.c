#include <stdio.h>
#include <string.h>

// https://www.tutorialspoint.com/cprogramming/c_goto_statement.htm
// https://www.geeksforgeeks.org/local-labels-in-c/
// https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1042_les-bases-du-langage-c/4610_les-sauts/

//Function macro using local labels
#define IS_STR_EMPTY(str)									 \
do {														 \
		__label__ empty, not_empty, exit;					 \
		if (strlen(str))									 \
				goto not_empty;								 \
		else												 \
				goto empty;									 \
															 \
		not_empty:											 \
				printf("string = %s\n", str);				 \
				goto exit;									 \
		empty:												 \
				printf("string is empty\n");				 \
		exit: ;												 \
} while(0);													 \

int main()
{
		char string[20] = {'\0'};

		//Pass empty string to Macro function
		IS_STR_EMPTY(string);


		//Pass non-empty string to Macro function
		strcpy(string, "geeksForgeeks");
		IS_STR_EMPTY(string);

		return 0;
}				
