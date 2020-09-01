//
// Created by ulysses on 7/5/19.
//
#include "../common_header.h"
int sock(int *array, int array_length);

int main(void){
	int input;
	scanf("%d", &input);
	int *array = calloc(input, sizeof(int));

	for (int i = 0; i < input; i++)
	    scanf("%d", &array[i]);

}	

int sock(int *array, int array_length){
    /*
     * Shitty solution, for every array[i], search the array for array[i] and incremement temp.
     * add temp/2 to pairs, and remove each pair.
     */
}