//
// Created by David on 2023. 04. 24..
//

#include "../headers/single_linked_list.h"

Node *newNode(int new_data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

bool isEmpty(Node *head) {
    return head == NULL;
}

void insertAtEnd(Node **head_ref, int new_data) {
    Node *new_node = newNode(new_data);
    Node *last = *head_ref;
    if (isEmpty(*head_ref)) {
        *head_ref = new_node;
        new_node->next = *head_ref;
        return;
    }
    while (last->next != *head_ref) {
        last = last->next;
    }
    last->next = new_node;
    new_node->next = *head_ref;
}

void printList(Node *node) {
    Node *first = node;
    while (node->next != first) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("%c\n", node->data);
}

void deleteFromBeginning(Node **head_ref) {
    Node *temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
}

void insertAtBeginning(Node **head_ref, int new_data) {
    Node *new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
