//
// Created by David on 2023. 03. 22..
//

#ifndef LABOR_5B_REGULAR_QUEUE_H
#define LABOR_5B_REGULAR_QUEUE_H

#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int capacity;
    int front;
    int rear;
    char **elements;
}Queue;

void createQueue(int capacity, Queue *queue);
void destroyQueue(Queue* queue);
bool isFull(Queue queue);
bool isEmpty(Queue queue);
void enqueue(Queue* queue, char* item);
char* dequeue(Queue* queue);
void display(Queue queue);

#endif //LABOR_5B_REGULAR_QUEUE_H
