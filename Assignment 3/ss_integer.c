/*
 * Name: ss_integer.c
 * Purpose: This file displays an integer in seven-segment display format.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    char userChoice = 'Y'; // control if the user wants to continue the program or not
    int userNum; // the number the user entered
    int tempNum = 0;
    int numDigits = 0; // number of digits in the user's number
    char negative = ' '; // used to check if the user entered a negative number
    // the array used to display an integer in seven-segment display
    const char segments [10][3][3] = {{{' ', '_',' '}, {'|', ' ', '|'}, {'|', '_', '|'}},
                                     {{' ',' ' ,' ' },{' ', '|', ' '},{' ', '|', ' '}},
                                     {{' ', '_', ' '},{' ', '_', '|'},{'|', '_', ' '}},
                                     {{' ', '_', ' '},{' ', '_', '|'},{' ', '_', '|'}},
                                     {{' ', ' ', ' '},{'|', '_', '|'},{' ', ' ', '|'}},
                                     {{' ', '_', ' '},{'|', '_', ' '},{' ', '_', '|'}},
                                     {{' ', '_', ' '},{'|', '_', ' '},{'|', '_', '|'}},
                                     {{' ', '_', ' '},{' ', ' ', '|'},{' ', ' ', '|'}},
                                     {{' ', '_', ' '},{'|', '_', '|'},{'|', '_', '|'}},
                                     {{' ', '_', ' '},{'|', '_', '|'},{' ', '_', '|'}}};

    // control the actual program
    while(userChoice == 'Y' || userChoice == 'y') {
        printf("Enter an integer: ");
        scanf("%d", &userNum);

        // check if the user's number is negative
        if(userNum < 0) {
            negative = 'T';
            userNum = abs(userNum);
        } else {
            negative = 'F';
        }

        tempNum = userNum;
        numDigits = 0;

        // find out the amount of digits stored in a number
        while(tempNum != 0) {
            tempNum = tempNum/10;
            numDigits++;
        }

        if(numDigits != 0) {
            // the array that will store all the digits
            int numbers[numDigits];

            // store each digit of the integer in reverse order into the array
            for (int i = 0; i < numDigits; ++i) {
                numbers[i] = userNum % 10;
                userNum = userNum / 10;
            }

            // these nested for loops will be used to display the top part of an integer
            printf("  ");
            for (int j = numDigits - 1; j >= 0; j--) {
                int row = numbers[j];
                for (int i = 0; i < 3; i++) {
                    printf("%c", segments[row][0][i]);
                }
                printf(" ");
            }
            printf("\n");

            // if the number is a negative, put a negative sign in front of it
            if(negative == 'T') {
                printf("--");
            } else {
                printf("  ");
            }
            // these nested for loops will be used to display the middle part of an integer
            for (int j = numDigits - 1; j >= 0; j--) {
                int row = numbers[j];
                for (int i = 0; i < 3; i++) {
                    printf("%c", segments[row][1][i]);
                }
                printf(" ");
            }
            printf("\n");

            // these nested for loops will be used to display the bottom part of an integer
            printf("  ");
            for (int j = numDigits - 1; j >= 0; j--) {
                int row = numbers[j];
                for (int i = 0; i < 3; i++) {
                    printf("%c", segments[row][2][i]);
                }
                printf(" ");
            }

            printf("\nWould you like to continue, Y/N? ");
            scanf(" %c", &userChoice);
            printf("\n");
        } else {
            printf("\nThat is not a valid input.");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}