#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

int hash_function(int key) {
    return key % TABLE_SIZE;
}

HashNode* create_hashnode(int key, int value) {
    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void insert_hash(HashNode* hash_table[], int key, int value) {
    int hash_index = hash_function(key);
    HashNode* new_node = create_hashnode(key, value);

    if (hash_table[hash_index] == NULL) {
        hash_table[hash_index] = new_node;
    }
    else {
        HashNode* temp = hash_table[hash_index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int search_hash(HashNode* hash_table[], int key) {
    int hash_index = hash_function(key);
    HashNode* temp = hash_table[hash_index];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Not found
}

void print_hash_table(HashNode* hash_table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        HashNode* temp = hash_table[i];
        while (temp != NULL) {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
