#include <stdio.h>
#include "linkedlist.h"
#include "bst.h"
#include "hashtable.h"
#include "heap.h"

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

    // Heap Example
    MinHeap* heap = create_minheap();
    insert_heap(heap, 50);
    insert_heap(heap, 10);
    insert_heap(heap, 30);
    printf("\nHeap: ");
    print_heap(heap);

    return 0;
}
