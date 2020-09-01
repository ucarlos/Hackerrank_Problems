//
// Created by ulysses on 7/5/19.
//
#include "../common_header.h"
#define STR_LEN (100)

char *s_gets(char *string, int len) {
    char *return_val, *find;
    return_val = fgets(string, len, stdin);
    if (return_val) {
        find = strchr(string, '\n'); //Look for newline
        if (find) //if the address is not NULL
            *find = '\0';// place a null character there
        else
            while (getchar() != '\n')
                continue; //dispose of rest of line-- clear buffer
    }
    return return_val;
}
int traverse_array(char *string, int str_len, char find){
    int count = 0;
    for (int i = 0; i < str_len; i++)
        if (string[i] == find)
            count++;
    return count;
    
}
unsigned long int repeated_string(char *string, int str_len, unsigned long long int n){
    unsigned long int recurrences = 0;
    int string_recurrences = traverse_array(string, str_len, 'a');
    // Divide to find out how many times the string repeats, and then multiply by the
    // recurrences of the character.
    recurrences += string_recurrences * (n / (str_len));

    int remainder = n % (str_len);
    // Then count the number of times the character appears in this substring
    recurrences += traverse_array(string, remainder, 'a');

    return recurrences;

}

int main(void){
    char *string = calloc(STR_LEN + 1, sizeof(char));
    unsigned long long int n;
    
    s_gets(string, STR_LEN + 1);
    scanf("%llu", &n);
    
    int string_length = strlen(string);
    unsigned long int result = repeated_string(string, string_length, n);
    printf("%lu\n", result);

}
