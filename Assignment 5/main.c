/*
 * Name: main.c
 * Purpose: This file is the main program.
 */

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "list.h"

int main(void) {
    int memorySize = 0;
    printf("Enter a size for dynamic memory allocation and deallocation system: ");
    scanf("%d", &memorySize);
    printf("\n");

    mem_ini(memorySize);
    List list = list_ini();

    int key = 0;

    // Continue to ask the user for input until end of line
    while(scanf("%d", &key) != EOF) {
        if(list_search(list, key) == NULL) {
            list_add(list, key, 1);
        } else {
            list_add(list, key, ++(*list_search(list, key)));
        }
    }

    printf("\nInteger\tOccurrence\n");
    list_print(list);
    list_free(list);
    mem_free();

    return 0;
}