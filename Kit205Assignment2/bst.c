#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BSTNode* create_bst_node(int data) {
    BSTNode* new_node = (BSTNode*)malloc(sizeof(BSTNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

BSTNode* insert_bst(BSTNode* root, int data) {
    if (root == NULL) {
        return create_bst_node(data);
    }
    if (data < root->data) {
        root->left = insert_bst(root->left, data);
    }
    else {
        root->right = insert_bst(root->right, data);
    }
    return root;
}

void inorder_bst(BSTNode* root) {
    if (root != NULL) {
        inorder_bst(root->left);
        printf("%d ", root->data);
        inorder_bst(root->right);
    }
}
