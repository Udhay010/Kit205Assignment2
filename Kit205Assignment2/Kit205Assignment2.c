#include <stdio.h>
#include "linkedlist.h"
#include "bst.h"
#include "hashtable.h"

int main() {
    // Linked List Example
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    printf("Linked List: ");
    print_list(head);

    // Binary Search Tree Example
    BSTNode* bst_root = NULL;
    bst_root = insert_bst(bst_root, 30);
    bst_root = insert_bst(bst_root, 20);
    printf("\nBST Inorder Traversal: ");
    inorder_bst(bst_root);

    // Hash Table Example
    HashNode* hash_table[TABLE_SIZE] = { NULL };
    insert_hash(hash_table, 1, 100);
    insert_hash(hash_table, 11, 200);
    printf("\nHash Table: \n");
    print_hash_table(hash_table);



    return 0;
}
