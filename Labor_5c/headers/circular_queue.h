//
// Created by David on 2023. 03. 22..
//

#ifndef LABOR_5C_CIRCULAR_QUEUE_H
#define LABOR_5C_CIRCULAR_QUEUE_H

#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int capacity;
    int front;
    int rear;
    int *elements;
}Queue;

typedef struct {
    int capacity;
    int front;
    int rear;
    char **elements;
}CarQueue;

void createQueue(int capacity, Queue *queue);
void createCarQueue(int capacity, CarQueue *queue);
void destroyQueue(Queue* queue);
void destroyCarQueue(CarQueue *queue);
bool isFull(Queue queue);
bool isCarFull(CarQueue queue);
bool isEmpty(Queue queue);
bool isCarEmpty(CarQueue queue);
void enqueue(Queue* queue, int item);
void carEnqueue(CarQueue* queue, char* item);
int dequeue(Queue* queue);
char* carDequeue(CarQueue* queue);
void display(Queue queue);
void carDisplay(CarQueue queue);

#endif //LABOR_5C_CIRCULAR_QUEUE_H
