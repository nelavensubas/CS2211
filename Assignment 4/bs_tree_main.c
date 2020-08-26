/*
 * Name: bs_tree_main.c
 * Purpose: This file is the main program.
 */

#include <stdio.h>
#include "bst.h"

int main(void) {
    BStree bst;
    bst = bstree_ini(256);

    char in_name[100];
    int num1=0, num2=0;

    // Continue to ask the user for input until end of line
    while(scanf("%s %d %d", in_name, &num1, &num2) != EOF) {
        bstree_insert(bst, key_construct(in_name, num1), num2);
    }
    printf("\n");

    bstree_traversal(bst);
    bstree_free(bst);

    return 0;
}