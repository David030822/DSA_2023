//
// Created by demeter.david on 3/6/2023.
//

#ifndef LABOR4_ARRAY_H
#define LABOR4_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int capacity;
    int size;
    int *elements;
}IntArray;

void createIntArray(int capacity, IntArray* pArray);
bool isEmpty(IntArray array);
bool isFull(IntArray array);
void printArray(IntArray array);
void insertFirst(IntArray* pArray, int item);
void insertLast(IntArray* pArray, int item);
void insertAt(IntArray* pArray, int position, int item);
void deleteItemAt(IntArray* pArray, int position);
int search(IntArray pArray, int item);
bool update(IntArray* pArray, int position, int newItem);
int getItemAt(IntArray array, int position);
void deallocateIntArray(IntArray *pArray);

#endif //LABOR4_ARRAY_H
