//
// Created by David on 2023. 02. 26..
//

#ifndef LABOR2_FUNCTIONS_H
#define LABOR2_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>

void allocateMemoryForArray2(int n, int **dpArray);
void beolvas(int *n, int **a, char *s);
void kiir(int n, int *a);
int numberOfEvenNumbers(int n, int *pArray);
void allocateMemoryForMatrix2(int rows, int cols, float ***dpMatrix);
void readMatrix(int *pRows, int *pCols, float ***dpArray, const char *input);
void printMatrix(int rows, int cols, float **pMatrix, const char *output);
void deallocateMemoryForMatrix(int rows, float ***dpMatrix);
float averageOfMatrixElements(int rows, int cols, float **pMatrix);
void negToPos(int rows, int cols, float **pMatrix);

#endif //LABOR2_FUNCTIONS_H
