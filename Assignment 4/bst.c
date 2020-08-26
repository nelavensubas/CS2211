/*
 * Name: bst.c
 * Purpose: This file is the binary search tree file.
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void traversalHelper(BStree bst, int index);

void bst_insert(BStree bst, int root, Key *key, Data data);

int new_node(BStree bst, Key *key, Data data);

void freeHelper(BStree bst, int root);

// Input: 'size': size of an array
// Output: a pointer of type BStree,
//         i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
//         allocate memory for a Node array of size+1 for member tree_nodes
//         allocate memory for an unsigned int array of size+1 for member free_nodes
//         set member size to 'size';
//         set entry free_nodes[i] to i
//         set member top to 1;
//         set member root to 0;
BStree bstree_ini(int size) {
    BStree bst = (BStree) malloc(sizeof(BStree_struct));
    bst->tree_nodes = (Node *) malloc((size + 1) * sizeof(Node));
    bst->free_nodes = (unsigned int *) malloc((size + 1) * sizeof(unsigned int));
    bst->size = size;
    for (int i = 0; i < size + 1; i++) {
        bst->free_nodes[i] = i;
        bst->tree_nodes[i].key = NULL;
    }
    bst->top = 1;
    bst->root = 0;
    return bst;
}

// Input: 'bst': a binary search tree
//        'node_index': an integer that starts at 1 when first called
//        'key': a pointer to Key
//        'data': an integer
// Effect: 'data' with 'key' is inserted into 'bst'
//         if 'key' is already is 'bst', do nothing
void bstree_insert(BStree bst, Key *key, Data data) {
    bst_insert(bst, bst->root, key, data);
}

/*
 * Purpose: To insert a key into the binary search tree
 * Input: 'bst': a binary search tree
 *        'node_index': the index
 *        'key': a pointer to key
 *        'data': an integer
 * Effect: 'data' with 'key' is inserted into 'bst'
 *          if 'key' is already is 'bst', do nothing
 */
void bst_insert(BStree bst, int node_index, Key *key, Data data) {
    if(bst->top > bst->size) {
        printf("Array index out of bounds.\n");
        return;
    } else {
        // Check to see if the binary search tree is empty
        if(node_index == 0 && bst->root == 0) {
            bst->root = new_node(bst, key, data);
            return;
        }

        int keyCompare = key_comp(key, bst->tree_nodes[node_index].key);
        // In this case, the key has already been inserted into the binary search tree
        if(keyCompare == 0) {
            free(key->name);
            free(key);
        // Go to the left subtree
        } else if(keyCompare < 0) {
            // If the left subtree has a leaf, then insert the key there
            if(bst->tree_nodes[node_index].left == 0) {
                bst->tree_nodes[node_index].left = new_node(bst, key, data);
            } else {
                bst_insert(bst, bst->tree_nodes[node_index].left, key, data);
            }
        // Go to the right subtree
        } else {
            // If the right subtree has a leaf, then insert the key there
            if(bst->tree_nodes[node_index].right == 0) {
                bst->tree_nodes[node_index].right = new_node(bst, key, data);
            } else {
                bst_insert(bst, bst->tree_nodes[node_index].right, key, data);
            }
        }
    }
}

/*
 * Purpose: To create a new node
 * Input: 'bst': a binary search tree
 *        'key': a pointer to key
 *        'data': an integer
 * Effect: a place to put the new node in bst
 * Output: return the index for new node
 */
int new_node(BStree bst, Key *key, Data data) {
    int index = bst->top;
    bst->tree_nodes[index].key = key;
    bst->tree_nodes[index].data = data;
    bst->tree_nodes[index].left = 0;
    bst->tree_nodes[index].right = 0;
    bst->top = bst->top+1;
    return index;
}

// Input: 'bst': a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
    traversalHelper(bst, bst->root);
}

/*
 * Purpose: To traverse through the binary search tree using in order traversal
 * Input: 'bst': a binary search tree
 *        'i': an index
 * Effect: print all the nodes in bst using in order traversal
 */
void traversalHelper(BStree bst, int i) {
    if(i == 0) {
        return;
    } else {
        traversalHelper(bst, bst->tree_nodes[i].left);
        print_node(bst->tree_nodes[i]);
        traversalHelper(bst, bst->tree_nodes[i].right);
    }
}

// Input: 'bst': a binary search tree
// Effect: all dynamic memory used by bst are freed
void bstree_free(BStree bst) {
    freeHelper(bst, bst->root);
    free(bst->tree_nodes);
    free(bst->free_nodes);
    free(bst);
}

/*
 * Purpose: To free all memory for each key
 * Input: 'bst': a binary search tree
 *        'index': an index
 * Effect: all dynamic memory for each key in tree nodes are freed
 */
void freeHelper(BStree bst, int index) {
    if(index == 0) {
        return;
    }
    // Free all keys in the left subtree
    freeHelper(bst, bst->tree_nodes[index].left);
    free(bst->tree_nodes[index].key->name);
    free(bst->tree_nodes[index].key);
    // Free all keys in the right subtree
    freeHelper(bst, bst->tree_nodes[index].right);
}
