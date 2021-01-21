/*
 * -----------------------------------------------------------------------------
 * Created by Ulysses Carlos on 01/20/2021 at 10:10 PM
 * 
 * Sum_Of_Digits_Five_Digit_Number.c
 * Assume that any number sent to main is b/w [10000:99999]
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>

long digit_sum(long val) {
	long sum = 0;
	
	sum += ((val / 10000) % 10);
	sum += ((val / 1000) % 10);
	sum += ((val / 100) % 10);
	sum += ((val / 10) % 10);
	sum += ((val % 10));
	
	return sum;

}


int main(void) {
	long val;
	scanf("%ld", &val);
	/* printf("Sum of digits in %ld: %ld\n", val, digit_sum(val)); */
	printf("%ld\n", digit_sum(val))
	
}
