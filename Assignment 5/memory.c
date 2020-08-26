/*
 * Name: memory.c
 * Purpose: This file will be represented as a dynamic memory allocation
 * and deallocation system to simulate system malloc() and free() functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

static unsigned char *memory;
static BStree bst;

// Input : 'size': the size of the unsigned char array
// Effect: to initialize an unsigned char array of size elements and
//         initialize a binary search tree.
void mem_ini(unsigned int size) {
	memory = (unsigned char *) malloc(size);
	bst = bstree_ini(size/5); // size/5 is large enough
	bstree_insert(bst, 0, size);
}

// Effect: free memory used for the array and the binary search tree
void mem_free(void) {
    bstree_free(bst);
    free(memory);
}

// Effect: print all the free memory blocks
void mem_print(void) {
    bstree_traversal(bst);
}

// Input : 'size': the size of the bytes to be allocated
// Output: a pointer to the first byte allocated
// Effect: a position in the memory array
void *simu_malloc(unsigned int size) {
    Key *key = bstree_data_search(bst, size+4);
    Data *data = bstree_search(bst, *key);
    bstree_delete(bst, *key);
    unsigned char *memVal = &memory[*key];
    *memVal = size;
    if(data - (size+4) > 0) {
        bstree_insert(bst, *key+size+4, *data - (size+4));
    }
    return &memory[*key+4];
}

// Input : 'ptr': a pointer
// Effect: put the allocated memory pointed by ptr back to be
//         free memory
void simu_free(void *ptr) {
    bstree_insert(bst, ptr-(void*)(memory)-sizeof(int), *(int*)ptr);
}
