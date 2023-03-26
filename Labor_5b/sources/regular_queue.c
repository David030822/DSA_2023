//
// Created by David on 2023. 03. 22..
//

#include "../headers/regular_queue.h"

void createQueue(int capacity, Queue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (char **) calloc(queue->capacity, sizeof(char *));
    if (!queue->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < capacity; i++)
        queue->elements[i] = (char *) calloc(20, sizeof(char));
    if (queue->elements == NULL) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyQueue(Queue *queue) {
    for (int i = 0; i < queue->capacity; i++)
        free(queue->elements[i]);
    free(queue->elements);
    queue->front = queue->rear = -1;
    queue->capacity = 0;
    queue = NULL;
}

bool isFull(Queue queue) {
    return queue.rear == queue.capacity - 1;
}

bool isEmpty(Queue queue) {
    return queue.front == -1;
}

void enqueue(Queue *queue, char *item) {
    if (isFull(*queue)) {
        printf(FULL_MESSAGE);
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    strcpy(queue->elements[++queue->rear], item);
}

char *dequeue(Queue *queue) {
    if (isEmpty(*queue)) {
        printf(EMPTY_MESSAGE);
        return NULL;
    }
    int pos = queue->front;
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return queue->elements[pos];
}

void display(Queue queue) {
    if (isEmpty(queue)) {
        printf("The queue is ");
        printf(EMPTY_MESSAGE);
        return;
    }
    printf("The elements of the queue are the following:\n");
    for (int i = queue.front; i <= queue.rear; ++i) {
        printf("%s\n", queue.elements[i]);
    }
}
