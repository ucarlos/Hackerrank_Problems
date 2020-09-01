//
// Created by ulysses on 7/5/19.
//
#include "../common_header.h"
int cloud_jump(int *array, int array_len){

    int *pointer = &array[0];
    int path_length = 0;
    for (int i = 0; i < array_len - 1;){
        // Condensed form of below:
        i = (array[i + 2] != 1) ? i + 2 : i + 1;

        /*
        if (array[i + 2] != 1) // If can Increment by 2, do it
            i +=2;
        else // Otherwise increment by 1.
            ++i;
        */

        path_length++;
    }

    return path_length;
}

int main(void){
    int array_length;
    scanf("%d", &array_length);
    int array[array_length];
    for (int i = 0; i < array_length; i++)
        scanf("%d", &array[i]);

    printf("%d", cloud_jump(array, array_length));
}
