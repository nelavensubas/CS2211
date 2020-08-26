/*
 * Name: list.c
 * Purpose: This file will be used to create a list structure to test
 * the dynamic memory allocation and deallocation system.
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "memory.h"

// Output: a pointer to a dynamically allocated and initialized list
// Effect: to initialize a list that is dynamically allocated and to
//         give back a pointer
List list_ini(void) {
	List_node *head= (List_node *) simu_malloc( sizeof(List_node) ); 
	head->next = NULL;
	return head;
}

// Input : 'list': a List
//         'key': a Key
// Output: the address of the key's associated data if it exists
// Effect: to figure out the pointer of where the key's associated
//         data is located
Data *list_search(List list, Key key) {
    list = list->next;
    // go through the entire list to see if the key exists
    while(list != NULL) {
        if(list->key == key) {
            // key exists so give the the address of the key's data
            return &list->data;
        }
        list = list->next;
    }
    // key doesn't exist
    return NULL;
}

// Input : 'list': a List
//         'key': a Key
//         'data': a Data
// Effect: add a key with its associated data to the front of the list
//         only if key doesn't exist already
void list_add(List list, Key key, Data data) {
    // check to see if key already exists
    if(list_search(list, key) != NULL) {
        return;
    } else {
        // key doesn't exist so create a new node
        List_node *newNode = simu_malloc(sizeof(List_node));
        newNode->key = key;
        newNode->data = data;
        newNode->next = list->next;
        list->next = newNode;
    }
}

// Input : 'list': a List
//         'key': a Key
// Effect: to delete the node in list
void list_delete(List list, Key key) {
    // check to see if the key exists in the list
    if(list_search(list, key) != NULL) {
        List predecessor = list;
        while(list->next != NULL) {
            if(list->key == key) {
                predecessor->next = list->next;
            }
            predecessor = list;
            list = list->next;
        }
    }
}

// Input : 'list': a List
// Effect: to linearly traversal the list and print each node's key
//         and data
void list_print(List list) {
    while(list->next != NULL) {
        print_list_node(list->next);
        list = list->next;
    }
}

// Input : 'list': a List
// Effect: free all the dynamically allocated memory of list
void list_free(List list) {
    simu_free(list);
}