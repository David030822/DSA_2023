//
// Created by David on 2023. 04. 24..
//

#ifndef LABOR_8_SINGLE_LINKED_LIST_H
#define LABOR_8_SINGLE_LINKED_LIST_H

#include "constants.h"
#include <stdlib.h>
#include <stdio.h>
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

#endif //LABOR_8_SINGLE_LINKED_LIST_H
