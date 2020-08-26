/*
 * Name: bst.h
 * Purpose: This is the header file for data.
 */

typedef struct {
    char *name;
    int id;
} Key;

typedef int Data;

typedef struct {
    Key *key;
    Data data;
    int left, right;
} Node;

Key *key_construct(char *in_name, int in_id);

int key_comp(Key *key1, Key *key2);

void print_key(Key *key);

void print_node(Node node);
