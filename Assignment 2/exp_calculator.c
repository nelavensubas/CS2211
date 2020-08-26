/*
 * Name: exp_calculator.c
 * Purpose: This file implements an exponential number calculator.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * exponentialNum function calculates the exponential number using recursion in logarithmic time.
 * @param base the base number the user chose
 * @param exponent the exponent number the user chose
 * @return the exponential number
 */
float exponentialNum(float base, int exponent) {
    // Base Case
    if(exponent == 0) {
        return 1;
    // If the exponent is even
    } else if (exponent % 2 == 0) {
        return exponentialNum(base, exponent/2) * exponentialNum(base, exponent/2);
    // If the exponent is odd
    } else {
        return base * exponentialNum(base, (exponent-1)/2) * exponentialNum(base, (exponent-1)/2);
    }
}

int main()
{
    float baseNum; // Store the base the user enters
    int exponentNum; // Store the exponent the user enters

    printf("Enter a base: ");
    scanf("%f", &baseNum);
    printf("\n");

    // This while loop ensures the user enters a positive base
    while(baseNum <= 0) {
        printf("Please enter a positive number for the base.\n");
        printf("Enter a base: ");
        scanf("%f", &baseNum);
        printf("\n");
    }

    printf("Enter an exponent: ");
    scanf("%d", &exponentNum);
    printf("\n");

    // This while loop ensures the user enters a non-negative exponent
    while(baseNum < 0) {
        printf("Please enter a non-negative number for the exponent.\n");
        printf("Enter am exponent: ");
        scanf("%d", &exponentNum);
        printf("\n");
    }

    printf("Result: %f\n", exponentialNum(baseNum, exponentNum));

    return 0;
}

