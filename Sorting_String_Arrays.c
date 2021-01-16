/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/14/2021 at 11:11 PM
 * 
 * Sorting_String_Arrays.c
 * 
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lexicographic_sort(const char *a, const char *b) {
	//printf("Comparing %s and %s\n", a, b);
	return strcmp(*(const char **)a, *(const char **)b);
}

int lexicographic_sort_reverse(const char *a, const char *b) {
	//printf("Comparing %s and %s\n", a, b);
	return -1 * strcmp(*(const char **)a, *(const char **)b);
}

int char_sort(const char *a, const char *b) {
	return (*a < *b)? -1 : ((*a > *b)? 1 : 0);
}

int number_of_distinct_characters(const char *string, int str_len) {
	if (string == NULL || str_len < 1)
		return 0;

	int count = 1;
	for (int i = 1; i < str_len; i++){
		if (string[i] != string[i - 1])
			count++;
	}

	return count;
}

int sort_by_number_of_distinct_characters(const char *a, const char *b) {
	int len_a = strlen(*(const char **)a);
	int len_b = strlen(*(const char **)b);
	
	char copy_a[len_a];
	char copy_b[len_b];

	// Sort the characters in each string so that you can compare the number
	// of distinct characters
	strncpy(copy_a, *(const char **)a, len_a);
	strncpy(copy_b, *(const char **)b, len_b);
	
	// Now sort each string
	qsort(copy_a, len_a, sizeof(char), (__compar_fn_t) char_sort);
	qsort(copy_b, len_b, sizeof(char), (__compar_fn_t) char_sort);
	
	int dist_a = number_of_distinct_characters(copy_a, len_a);
	int dist_b = number_of_distinct_characters(copy_b, len_b);

	if (dist_a == dist_b)
		return strcmp(*(const char **)a, *(const char **)b);
	else
		return (dist_a > dist_b)? 1 : -1;
		
}

int sort_by_length(const char *a, const char *b) {
	int len_a = strlen(*(const char **)a);
	int len_b = strlen(*(const char **)b);

	if (len_a == len_b)
		return strcmp(*(const char **)a, *(const char **)b);
	else
		return (len_a > len_b)? 1 : -1;
}


void string_sort(char **arg, const int count,
				 int(*cmpr_func)(const void *a, const void *b)) {

	qsort(arg, count, sizeof(char *), (__compar_fn_t) cmpr_func);
}

int main(void) {
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for (int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

	printf("\n\n\n\n");
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

}
