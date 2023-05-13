//
// Created by David on 2023. 05. 08..
//

#ifndef LABOR_10_BIN_TREE_H
#define LABOR_10_BIN_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include <stdbool.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node* newNode(int new_data);
Node *insertLeft(Node *root, int newData);
Node *insertRight(Node *root, int newData);
void preorderTraversal(Node *root);
void inorderTraversal(Node *root);
void postorderTraversal(Node *root);


#endif //LABOR_10_BIN_TREE_H
