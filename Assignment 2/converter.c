/*
 * Name: converter.c
 * Purpose: This file does conversions depending on what the
 * user wants.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * kiloMileConversion function converts from either kilometers to miles or miles to kilometers.
 * @param num the number that will be converted
 * @param choice specifies which conversion the user wants to do
 * @return the conversion
 */
float kiloMileConversion(float num, char choice)
{
    if (choice == 'K') {
        return num/1.609344;
    } else {
        return num*1.609344;
    }
}

/*
 * meterFeetConversion function converts from either meter to feet or feet to meter.
 * @param num the number that will be converted
 * @param choice specifies which conversion the user wants to do
 * @return the conversion
 */
float meterFeetConversion(float num, char choice)
{
    if (choice == 'M') {
        return num/0.3048;
    } else {
        return num*0.3048;
    }
}

/*
 * centimetreInchConversion function converts from either centimetre to inch or inch to centimetre.
 * @param num the number that will be converted
 * @param choice specifies which conversion the user wants to do
 * @return the conversion
 */
float centimetreInchConversion(float num, char choice)
{
    if (choice == 'C') {
        return num/2.54;
    } else {
        return num*2.54;
    }
}

/*
 * celsiusFahrenheitConversion function converts from either celsius to fahrenheit or inch to centimetre.
 * @param num the number that will be converted
 * @param choice specifies which conversion the user wants to do
 * @return the conversion
 */
float celsiusFahrenheitConversion(float num, char choice)
{
    if (choice == 'C') {
        return ((num*(9.0/5.0)) + 32.0);
    } else {
        return ((num-32.0) * (5.0/9.0));
    }
}

int main()
{
    int option = -1; // Counter variable to control the while loop
    char conversion; // Store the user choice of conversion
    float userNum; // Store the number the user wants to convert

    // Continue to ask the user for which conversion they would like to do until they want to quit
    while(option != 5) {
        printf("Hello! What would you like to do?\n");
        printf("1 for conversion between Kilometer and Mile.\n");
        printf("2 for conversion between Meter and Feet.\n");
        printf("3 for conversion between Centimetre and Inch.\n");
        printf("4 for conversion between Celsius and Fahrenheit.\n");
        printf("5 for quit.\n");
        printf("Enter a number: ");
        scanf("%d", &option);
        printf("\n");

        // Convert from kilometer to mile or mile to kilometer
        if (option == 1) {
            printf("Please enter a character, K for conversion from Kilometer to Mile, M for conversion from Mile to Kilometer: ");
            scanf(" %c", &conversion);
            printf("\n");

            while((conversion != 'K') && (conversion != 'M')) {
                printf("That is not a valid choice, please select a correct character.\n");
                printf("Please enter a character, K for conversion from Kilometer to Mile, M for conversion from Mile to Kilometer: ");
                scanf(" %c", &conversion);
                printf("\n");
            }

            printf("Please enter a number: ");
            scanf("%f", &userNum);
            if(conversion == 'K') {
                printf("\nResult: %f mi\n\n", kiloMileConversion(userNum, conversion));
            } else {
                printf("\nResult: %f km\n\n", kiloMileConversion(userNum, conversion));
            }
         // Convert from meter to feet or feet to meter
        } else if (option == 2) {
            printf("Please enter a character, M for conversion from Meter to Feet, F for conversion from Feet to Meter: ");
            scanf(" %c", &conversion);
            printf("\n");

            while((conversion != 'M') && (conversion != 'F')) {
                printf("That is not a valid choice, please select a correct character.\n");
                printf("Please enter a character, M for conversion from Meter to Feet, F for conversion from Feet to Meter: ");
                scanf(" %c", &conversion);
                printf("\n");
            }

            printf("Please enter a number: ");
            scanf("%f", &userNum);
            if(conversion == 'M') {
                printf("\nResult: %f ft\n\n", meterFeetConversion(userNum, conversion));
            } else {
                printf("\nResult: %f m\n\n", meterFeetConversion(userNum, conversion));
            }
        // Convert from centimetre to inch or inch to centimetre
        } else if (option == 3) {
            printf("Please enter a character, C for conversion from Centimetre to Inch, I for conversion from Inch to Centimetre: ");
            scanf(" %c", &conversion);
            printf("\n");

            while((conversion != 'C') && (conversion != 'I')) {
                printf("That is not a valid choice, please select a correct character.\n");
                printf("Please enter a character, C for conversion from Centimetre to Inch, I for conversion from Inch to Centimetre: ");
                scanf(" %c", &conversion);
                printf("\n");
            }

            printf("\n");
            printf("Please enter a number: ");
            scanf("%f", &userNum);
            if(conversion == 'C') {
                printf("\nResult: %f \"\n\n", centimetreInchConversion(userNum, conversion));
            } else {
                printf("\nResult: %f cm\n\n", centimetreInchConversion(userNum, conversion));
            }
        // Convert from celsius to fahrenheit or fahrenheit to celsius
        } else if (option == 4) {
            printf("Please enter a character, C for conversion from Celsius to Fahrenheit, F for conversion from Fahrenheit to Celsius: ");
            scanf(" %c", &conversion);
            printf("\n");

            while((conversion != 'C') && (conversion != 'F')) {
                printf("That is not a valid choice, please select a correct character.\n");
                printf("Please enter a character, C for conversion from Celsius to Fahrenheit, F for conversion from Fahrenheit to Celsius: ");
                scanf(" %c", &conversion);
                printf("\n");
            }

            printf("\n");
            printf("Please enter a number: ");
            scanf("%f", &userNum);
            if(conversion == 'C') {
                printf("\nResult: %f fahrenheit\n\n", celsiusFahrenheitConversion(userNum, conversion));
            } else {
                printf("\nResult: %f celsius\n\n", celsiusFahrenheitConversion(userNum, conversion));
            }
        }
    }

    return 0;
}
