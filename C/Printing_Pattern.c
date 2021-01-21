/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/20/2021 at 11:31 PM
 *
 * Printing_Pattern.c
 * The box dimension is (2 * n - 1) x (2 * n - 1)
 * First and last lines are the number n,
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

void set_list_value(int *begin, int *end, int val) {
	for (int *p = begin; p <= end; p++)
		*p = val;

}

void print_list(int *list, int length) {
	if (length <= 0) return;

	for (int i = 0; i < length; i++)
		printf("%2d ", list[i]);
	printf("\n");
}

void print_pattern(int val) {
	if (val <= 0) return;
	
	int row, column;
	row = column = 2 * val - 1;
	int *list = calloc(row, sizeof(int));
	if (list == NULL) {
		unsigned long long size = sizeof(int) * val;
		fprintf(stderr, "Cannot allocate %lld bytes of memory.\n", size);
		exit(EXIT_FAILURE);
	}
	
	int top_section = (row / 2);
	/* int middle_section = row - 2 * top_section; */
	int bottom_section = (row / 2);

	int *begin = &list[0];
	int *end = &list[row - 1];

	
	for (int i = 0; i < top_section + 1; i++) {
		set_list_value(begin, end, val - i);
		begin++; end--;
		print_list(list, column);
	}

	// Now Set the pointers back a index
	begin--; end++;
	
	for (int i = 1; i <= bottom_section; i++) {
		set_list_value(begin, end, i + 1);
		begin--; end++;		
		print_list(list, column);

	}

	/* puts("Additional Information:"); */
	/* printf("Top Section: %d\n", top_section); */
	/* printf("Middle Section: %d\n", middle_section); */
	/* printf("Bottom Section: %d\n", bottom_section); */

	// Now free the list:
	free(list);
}

int main(void) {
	int val;
	scanf("%d", &val);
	print_pattern(val);
	

}
