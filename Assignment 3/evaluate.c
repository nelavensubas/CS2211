/*
 * Name: evaluate.c
 * Purpose: This file evaluates simple arithmetic expressions.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Purpose: Used to represent numeric value.
 * Input: none, read from stdin
 * Effect: get the next numeric value of the expression
 * Output: return the next numeric value of the expression.
 */
float get_num() {
    float num = ' ';
    while(num == ' ') {
        scanf("%f", &num);
    }
    return num;
}

/*
 * Input: none, read from stdin
 * Effect: get the next operator of the expression
 *         this operator can be +, -, *, /, or ’\n’
 *         ’\n’ indicates the end of the expression input
 *         leading spaces should skipped
 * Output: return the next operator of the expression.
 */
char get_op() {
    char operator = ' ';
    while(operator == ' ') {
        scanf("%c", &operator);
    }
    return operator;
}

/*
 * Purpose: Use to represent simple arithmetic expression in which all operators
 *          are * or /.
 * Input: ’sub_exp’: the value of the current sub m_expression to the left of ’op’
 *         location in stdin.
 *         ’op’ : an operator, ’*’ or ’/’. ’op’ could also be ’+’, ’-’, or ’\n’
 *         indicating the end of the m_expression. "+’, ’-’, or ’\n’ should be pushed
 *         back to stdin.
 *         the rest of the m_expression will be read in from stdin
 * Effect: the m_expression is evaluated using recursion:
 *         get next_num with get_num() and then get next_op with get_op()
 *         use ’sub_exp op next_num’ and ’next_op’ to do recursive call
 * Output: this function returns the value of the current m_expression.
 */
float m_exp(float sub_exp, char op) {
    float next_num;
    char next_op;
    float next_sub_exp;

    // since m_exp only looks at operators that are either * or /, we will ignore other chars and move back
    // through the expression to looks at previous operators
    if (op == '+' || op == '-' || op == '\n') {
        ungetc(op, stdin);
        return sub_exp;
    } else {
        next_num = get_num();
        next_op = get_op();

        // divide the number on the left side of the division symbol by the number on the right side
        if(op == '/') {
            // terminate the program if a division by zero is attempted
            if(next_num == 0.0) {
                printf("Division by 0 is invalid.");
                exit(EXIT_FAILURE);
            } else {
                next_sub_exp = sub_exp / next_num;
            }
        // multiply the number on the left side of multiplication symbol by the number on the right side
        } else if(op == '*') {
            next_sub_exp = sub_exp * next_num;
        } else {
            printf("This is an invalid operator.");
            exit(EXIT_FAILURE);
        }

        return  m_exp(next_sub_exp, next_op);
    }
}

/*
 * Purpose: Use to represent simple arithmetic expression.
 * Input: none, the s_expression will be read in from stdin
 * Effect: the s_expression is evaluated using
 *         a while loop or a do while loop:
 *         repeatedly get num with m_exp() and then get op with
 *         get_op() while op is ’+’ or ’-’; when op is ’\n’, exit loop.
 * Output: this function returns the value of the s_expression
 */
float s_exp(void) {
    float num = get_num();
    char operator = get_op();

    // end of the expression
    if(operator == '\n') {
        return num;
    } else {
        // used to calculate the result of numbers with / or * symbols as those
        // take precedence
        float exp = m_exp(num, operator);
        operator = get_op();

        while(operator!= '\n') {
            // add the number on the left side of the plus symbol by the number on the right side
            if(operator == '+') {
                num = get_num();
                operator = get_op();
                exp = exp + m_exp(num, operator);
            // subtract the number on the left side of the minus symbol by the number on the right side
            } else if (operator == '-') {
                num = get_num();
                operator = get_op();
                exp = exp - m_exp(num, operator);
            } else {
                exp = m_exp(num, operator);
            }
            operator = get_op();
        }

        return exp;
    }
}

int main() {
    char userChoice = 'Y';

    while(userChoice == 'Y' || userChoice == 'y') {
        printf("Enter a simple arithmetic expression: ");
        // calculation of the arithmetic expression begins with s_exp()
        float calculation = s_exp();
        printf("\nThe result is %g\n", calculation);

        printf("Would you like to continue, Y/N? ");
        scanf(" %c", &userChoice);
        printf("\n");
    }

    return 0;
}