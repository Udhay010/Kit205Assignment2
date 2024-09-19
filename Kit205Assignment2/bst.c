#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Create a new BST node
BSTNode* create_bst_node(int data) {
    BSTNode* new_node = (BSTNode*)malloc(sizeof(BSTNode));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new node into the BST
BSTNode* insert_bst(BSTNode* root, int data) {
    if (root == NULL) {
        return create_bst_node(data);
    }
    if (data < root->data) {
        root->left = insert_bst(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert_bst(root->right, data);
    }
    // Duplicate values are not inserted
    return root;
}

// Inorder traversal of the BST
void inorder_bst(BSTNode* root) {
    if (root != NULL) {
        inorder_bst(root->left);
        printf("%d ", root->data);
        inorder_bst(root->right);
    }
}

// Search for a value in the BST
BSTNode* search_bst(BSTNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search_bst(root->left, data);
    }
    else {
        return search_bst(root->right, data);
    }
}
