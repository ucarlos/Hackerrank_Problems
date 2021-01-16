/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/15/2021 at 02:30 PM
 * 
 * C_Recursion.c
 * 
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int64_t recursion(int32_t num, int32_t a, int32_t b, int32_t c) {
	if (num == 1)
		return a;
	else if (num == 2)
		return b;
	else if (num == 3)
		return c;
	else return recursion(num - 1, a, b, c) + recursion(num - 2, a, b, c)
			 + recursion(num - 3, a, b, c);

}

int main(void) {
	int32_t num, a, b, c;
	scanf("%d", &num);
	scanf("%d %d %d", &a, &b, &c);

	int64_t result = recursion(num, a, b, c);
	/* printf("Result: %ld\n", result); */
	printf("%ld\n", result);
	return 0;
}
