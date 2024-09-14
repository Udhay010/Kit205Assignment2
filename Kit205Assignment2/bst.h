#ifndef BST_H
#define BST_H

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* create_bst_node(int data);
BSTNode* insert_bst(BSTNode* root, int data);
void inorder_bst(BSTNode* root);

#endif // BST_H
