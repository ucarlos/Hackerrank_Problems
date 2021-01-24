/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/24/2021 at 05:21 PM
 *
 * Digit_Frequency.c
 * This is essentially a map, that contains a-z, and 0-9, so create a struct
 * called pair(char first, int second), and make an array of that.
 *
 * what you can do is make an array of pairs, index 0 - 9 are numbers, while
 * 9 - 36 are letters.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Size of a-z plus 0-9
const unsigned int list_length = 36;

typedef struct pair {
	int freq;
	char letter;	
} Pair;


void initialize_list(Pair *list) {
	for (int i = 0; i <= 9; i++) {
		list[i].letter = i + '0';
		list[i].freq = 0;
	}

	// Now the letters:
	// a starts at 97, and z ends at 122.
	for (int i = 0; i < 26; i++) {
		list[10 + i].letter = 'a' + i;
		list[10 + i].freq = 0;
	}
		
}

void print_list(Pair *list) {
	for (int i = 0; i < list_length; i++) {
		printf("Pair %d: (Letter: %c, Freq: %d)\n", i,
			   list[i].letter,
			   list[i].freq);

	}
}

void increment_pair_freq(Pair *list, char item) {
	// Check if item is alphanumerical or not
	// Lowercase item
	item = tolower(item);
	if (!isalnum(item)) return;

	if (isdigit(item))
		list[(item - '0')].freq++;
	else
		// Subtract alphabet characters by 87 to access index.	 
		list[(int)item - 87].freq++;


}

int return_pair_freq(Pair *list, char item) {
	if (!isalnum(item))
		return -1; // For not found;

	item = tolower(item);
	if (isdigit(item))
		return list[(item - '0')].freq;
	else
		return list[(int)item - 87].freq;
}


int main(void) {
	// Initialize all data to zero
	char string[1024];
	Pair *list = calloc(list_length, sizeof(Pair));
	initialize_list(list);

	
	fgets(string, 1024, stdin);
	int length = strlen(string);
	for (int i = 0; i < length; i++) {
		increment_pair_freq(list, string[i]);
	}

	for (int i = 0; i <= 9; i++) {
		printf("%d ", list[i].freq);
	}
	puts("");	
	/* print_list(list); */

	free(list);
}
