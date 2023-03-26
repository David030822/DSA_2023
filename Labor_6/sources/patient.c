//
// Created by David on 2023. 03. 26..
//

#include "../headers/patient.h"

void readPatient(Patient_t *patient, FILE *fin) {
    char disease[30];
    fscanf(fin, "%[^\n]", patient->nev);
    fscanf(fin, "\n%s", patient->cnp);
    fscanf(fin, "\n%s", disease);
    fscanf(fin, "\n%i%i%i", &patient->birthdate.year, &patient->birthdate.month, &patient->birthdate.day);
    patient->disease = getDiseaseByChar(disease);
}

void printPatient(Patient_t patient, FILE *fin) {
    printf("%s %s %d %d %d %s\n",
           patient.nev,
           patient.cnp,
           patient.birthdate.year, patient.birthdate.month, patient.birthdate.day,
           getDiseaseByEnum(patient.disease));
}

char *getDiseaseByEnum(enum Disease disease) {
    switch (disease) {
        case INFLUENZA:
            return "INFLUENZA";
        case DIABETES:
            return "DIABETES";
        case CANCER:
            return "CANCER";
        case HYPERTENSION:
            return "HYPERTENSION";
        case ASTHMA:
            return "ASTHMA";
        case HEPATITIS:
            return "HEPATITIS";
        case DEPRESSION:
            return "DEPRESSION";
        case MIGRAINES:
            return "MIGRAINES";
        case ANEMIA:
            return "ANEMIA";
        case OBESITY:
            return "OBESITY";
        case ALLERGIES:
            return "ALLERGIES";
    }
}

enum Disease getDiseaseByChar(char *disease) {
    for (int i = 0; i <= 11; i++)
        if (strcmp(disease, getDiseaseByEnum(i)) == NULL)
            return i;
}

bool isFull(Queue queue) {
    return queue.front == 0 && queue.rear == queue.capacity - 1 || queue.rear == queue.front - 1;
}

bool isEmpty(Queue queue) {
    return queue.front == -1;
}

void createQueue(int capacity, Queue *queue) {
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->elements = (Patient_t *) calloc(queue->capacity, sizeof(Patient_t));
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

void enqueue(Queue *queue, Patient_t item) {
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

Patient_t dequeue(Queue *queue) {

    Patient_t save = queue->elements[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return save;
}

void display(Queue queue, FILE *fout) {
    if (isEmpty(queue)) {
        printf("The queue is ");
        printf(EMPTY_MESSAGE);
        return;
    }
    printf("The items of the queue:\n");
    int i = queue.front;
    do {
        printPatient(queue.elements[i], fout);
        i = (i + 1) % queue.capacity;
    } while (i != queue.rear);
    //printPatient(queue.elements[i], fout);
    printf("\n");
}
