/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/15/2021 at 02:55 PM
 * 
 * Students_Marks_Sum.c
 * 
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

int marks_summation(int *mark_list, int number_of_students, char gender) {

	char ch = tolower(gender);
	gender = ch;

	if (!(gender == 'b' || gender == 'g'))
		return -1;

	int sum = 0;
	int index = (gender == 'b')? 0 : 1;

	for (index; index < number_of_students; index += 2)
		sum += mark_list[index];

	return sum;
}


int main(void) {
	int number_of_students;
	char gender;
	int sum;

	scanf("%d", &number_of_students);
	int *marks = (int *) malloc(number_of_students * sizeof (int));

	for (int student = 0; student < number_of_students; student++) {
		scanf("%d", (marks + student));
	}

	for (int i = 0; i < number_of_students; i++)
		printf("%d ", marks[i]);

	scanf(" %c", &gender);
	sum = marks_summation(marks, number_of_students, gender);
	printf("%d", sum);
	free(marks);

	return 0;
}

	
