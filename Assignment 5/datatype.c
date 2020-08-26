/*
 * Name: datatype.c
 * Purpose: This file will be used in the binary search tree and the
 * linked lists to specify the data types.
 */

#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"

// Input:	’key1’ and ’key2’ are two Keys
// Output: if return value < 0, then key1 < key2,
// 				 if return value = 0, then key1 = key2,
//				 if return value > 0, then key1 > key2,
int key_comp(Key key1, Key key2) {
    if(key1 == key2) {
        return 0;
    } else if (key1 < key2) {
        return -1;
    }
    return 1;
}

// Input:	’data1’ and ’data2’ are two Data
// Output: if return value < 0, then data1 < data2,
// 				 if return value = 0, then data1 = data2,
//				 if return value > 0, then data1 > data2,
int data_comp(Data data1, Data data2) {
    if(data1 == data2) {
        return 0;
    } else if (data1 < data2) {
        return -1;
    }
    return 1;
}

//	Input: ’key’: a Key
//	Effect: key is printed
void key_print(Key key) {
    printf("%d\t ", key);
}

//	Input: ’data’: a Data
//	Effect: data is printed
void data_print(Data data) {
    printf("%d\n", data);
}

//	Input: ’node’: a Node
//	Effect: node.key is printed and then the node.data is printed
void print_node(Node node) {
    key_print(node.key);
    data_print(node.data);
}

//	Input: ’node’: a pointer to List_node
//	Effect: node->key is printed and then the node->data is printed
void print_list_node(List_node *node) {
    key_print(node->key);
    data_print(node->data);
}
