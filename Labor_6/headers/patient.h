//
// Created by David on 2023. 03. 26..
//

#ifndef LABOR_6_PATIENT_H
#define LABOR_6_PATIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "constants.h"

enum Disease {
    INFLUENZA, DIABETES, CANCER,
    HYPERTENSION, ASTHMA, HEPATITIS, DEPRESSION, MIGRAINES,
    ANEMIA, OBESITY, ALLERGIES
};

typedef struct {
    int year, month, day;
} Date_t;

typedef struct {
    char nev[40], cnp[14];
    enum Disease disease;
    Date_t birthdate;
} Patient_t;

void readPatient(Patient_t *patient, FILE *fin);

void printPatient(Patient_t patient, FILE *fin);

char *getDiseaseByEnum(enum Disease disease);

enum Disease getDiseaseByChar(char *disease);

typedef struct {
    int capacity;
    int front;
    int rear;
    Patient_t *elements;
} Queue;

void createQueue(int capacity, Queue *queue);

void destroyQueue(Queue *queue);

bool isFull(Queue queue);

bool isEmpty(Queue queue);

void enqueue(Queue *queue, Patient_t item);

Patient_t dequeue(Queue *queue);

void display(Queue queue, FILE *fout);

#endif //LABOR_6_PATIENT_H
