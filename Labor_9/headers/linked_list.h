//
// Created by David on 2023. 05. 08..
//

#ifndef LABOR_9_LINKED_LIST_H
#define LABOR_9_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include <stdbool.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* newNode(int new_data);
bool isEmpty(Node *head);
void insertAtEnd(Node** head_ref, int new_data);
void printList(Node* node);
void deleteFromBeginning(Node** head_ref);
void insertAtBeginning(Node **head_ref, int new_data);
void insert(Node **, int);

#endif //LABOR_9_LINKED_LIST_H
