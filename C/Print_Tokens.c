/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/24/2021 at 01:04 AM
 * 
 * Print_Tokens.c
 * 
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE (1024)

char * skip_space(char *str) {
	while (isspace(*str))
		str++;
	return str;
}

int main(void) {
	char string[MAX_SIZE];
	char temp[MAX_SIZE];
	fgets(string, MAX_SIZE, stdin);

	// Now print out each line.
	// Given a pointer to the first char in the string,

	// J
	int result;
	int size;
	char *begin = string;

	/* printf("Size of string: %lu\n", strlen(string)); */
	while ((result = sscanf(begin, "%s", temp) != EOF)) {
		size = strlen(temp);
		/* printf("Printing %s (Size: %d)\n", temp, size); */
		
		printf("%s\n", temp);
		begin += size;
		begin = skip_space(begin);
		/* printf("Begin now points to %lu\n", (begin - string)); */
	}
	
	
}
