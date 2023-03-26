//
// Created by David on 2023. 03. 22..
//

#include "../headers/circular_queue.h"

bool isFull(Queue queue) {
    return queue.front == 0 && queue.rear == queue.capacity - 1 || queue.rear == queue.front - 1;
}
bool isCarFull(CarQueue queue) {
    return queue.front == 0 && queue.rear == queue.capacity - 1 || queue.rear == queue.front - 1;
}
bool isEmpty(Queue queue) {
    return queue.front == -1;
}

bool isCarEmpty(CarQueue queue){
    return queue.front == -1;
}

void createQueue(int capacity, Queue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (int *) calloc(queue->capacity,sizeof(int));
    if (queue->elements == NULL) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void createCarQueue(int capacity, CarQueue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (char **) calloc(queue->capacity, sizeof(char *));
    if (queue->elements == NULL) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
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
    free(queue->elements);
    queue->front = queue->rear = -1;
    queue->capacity = 0;
    queue = NULL;
}

void destroyCarQueue(CarQueue *queue) {
    for (int i = 0; i < queue->capacity; i++)
        free(queue->elements[i]);
    free(queue->elements);
    queue->front = queue->rear = -1;
    queue->capacity = 0;
    queue = NULL;
}

void enqueue(Queue *queue, int item) {
    if (isFull(*queue)) {
        printf(FULL_MESSAGE);
        return;
    }
    if (isEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = item;
}

void carEnqueue(CarQueue *queue, char *item) {
    if (isCarFull(*queue)) {
        printf(FULL_MESSAGE);
        return;
    }
    if (isCarEmpty(*queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    strcpy(queue->elements[queue->rear], item);
}

int dequeue(Queue *queue) {
    if (isEmpty(*queue)) {
        printf(EMPTY_MESSAGE);
        return INT_MIN;
    }
    int save = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return save;
}

char *carDequeue(CarQueue *queue) {
    if (isCarEmpty(*queue)) {
        printf(EMPTY_MESSAGE);
        return NULL;
    }
    char *save = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return save;
}

void display(Queue queue) {
    if (isEmpty(queue)) {
        printf("The queue is ");
        printf(EMPTY_MESSAGE);
        return;
    }
    printf("The items of the queue:");
    int i = queue.front;
    do {
        printf("%i ", queue.elements[i]);
        i = (i + 1) % queue.capacity;
    } while (i != queue.rear);
    printf("%i ", queue.elements[i]);
    printf("\n");
}

void carDisplay(CarQueue queue) {
    if (isCarEmpty(queue)) {
        printf("The queue is ");
        printf(EMPTY_MESSAGE);
        return;
    }
    printf("The items of the queue:");
    int i = queue.front;
    do {
        printf("%s ", queue.elements[i]);
        i = (i + 1) % queue.capacity;
    } while (i != queue.rear);
    printf("%s ", queue.elements[i]);
    printf("\n");
}
