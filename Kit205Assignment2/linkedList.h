#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data);
void insert(Node** head, int data);
void print_list(Node* head);

#endif // LINKEDLIST_H
