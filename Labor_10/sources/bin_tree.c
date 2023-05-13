//
// Created by David on 2023. 05. 08..
//

#include "../headers/bin_tree.h"

Node *newNode(int new_data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

    new_node->data = new_data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node *insertLeft(Node *root, int newData){
    root->left = newNode(newData);
    return root->left;
}

Node *insertRight(Node *root, int newData) {
    root->right = newNode(newData);
    return root->right;
}

void preorderTraversal(Node *root) {
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
    if(root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if(root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}
