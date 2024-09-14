#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 10

typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;

HashNode* create_hashnode(int key, int value);
void insert_hash(HashNode* hash_table[], int key, int value);
int search_hash(HashNode* hash_table[], int key);
void print_hash_table(HashNode* hash_table[]);

#endif // HASHTABLE_H
