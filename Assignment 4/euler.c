/*
 * Name: euler.c
 * Purpose: This file calculate the mathematical constant e.
 */

#include <stdio.h>

/*
 * Purpose: To calculate the factorial of a number.
 * Input: 'n' the number
 * Effect: recursively calculate the given number's factorial
 * Output: return the factorial
 */
double factorial(double n) {
    if(n == 0.0) return 1.0;
    return n * factorial(n - 1.0);
}

/*
 * Purpose: To calculate the mathematical constant e.
 * Input: 'epsilon' a small number less than or equal to 1/n!
 * Effect: using the small number, calculate e
 * Output: return the matematical constant e
 */
double euler(double epsilon) {
    double eulerVal = 1.0;
    int n = 1.0;
    int factorialVal = factorial(n);

    while((1.0/factorialVal) >= epsilon) {
        eulerVal += 1.0/factorialVal;
        n++;
        factorialVal = factorial(n);
    }

    return eulerVal;
}

int main() {
    double epsilonValue = 0.0;

    printf("Enter a small number:");
    scanf("%lf", &epsilonValue);

    printf("\nThe Mathematical constant e: %.15lf", euler(epsilonValue));

    return 0;
}