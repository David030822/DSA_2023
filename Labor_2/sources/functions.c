//
// Created by David on 2023. 02. 26..
//
#include "../headers/functions.h"

void allocateMemoryForArray2(int n, int **dpArray)
{
    *dpArray = (int *) calloc(n, sizeof(int));
    if (*dpArray == NULL)
        exit(-1);
}

void beolvas(int *n, int **a, char *s)
{
    FILE *fin = fopen(s, "r");
    if (!fin)
        exit(-500);
    fscanf(fin, "%d", n);
    allocateMemoryForArray2(*n, a);
    for (int i = 0; i < *n; i++)
    {
        fscanf(fin, "%d", &(*a)[i]);
    }
}

void kiir(int n, int *a)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int numberOfEvenNumbers(int n, int *pArray)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += !(pArray[i] & 1);
    }
    return count;
}

void allocateMemoryForMatrix2(int rows, int cols, float ***dpMatrix)
{
    **dpMatrix = (float **) malloc(rows * sizeof(float *));
    if (dpMatrix == NULL)
        exit(-200);
    for (int i = 0; i < rows; i++)
    {
        (*dpMatrix)[i] = (float *) malloc(cols * sizeof(float));
        if (dpMatrix[i] == NULL)
            exit(-200);
    }
}

void readMatrix(int *pRows, int *pCols, float ***dpArray, const char *input)
{
    FILE *fin = fopen(input, "r");
    if (!fin)
        exit(-500);
    fscanf(fin, "%d %d", pRows, pCols);
    allocateMemoryForMatrix2(*pRows, *pCols, dpArray);
    for (int i = 0; i < *pRows; i++) {
        for (int j = 0; j < *pCols; j++)
            fscanf(fin, "%f", &(*dpArray)[i][j]);
    }
}

void printMatrix(int rows, int cols, float **pMatrix, const char *output)
{
    FILE *fin = fopen(output, "w");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            fprintf(fin, "%6.2f ", pMatrix[i][j]);
        fprintf(fin, "\n");
    }
}

void deallocateMemoryForMatrix(int rows, int ***dpMatrix)
{
    for (int i = 0; i < rows; i++)
        free(dpMatrix[i]);
    free(dpMatrix);
}

float averageOfMatrixElements(int rows, int cols, int **pMatrix)
{
    float sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            sum += (float)pMatrix[i][j];
    }
    return (float ) sum/(float)(rows*cols);
}

void negToPos(int rows, int cols, int ***pMatrix)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if(*pMatrix[i] < 0)
            {
                //*pMatrix[i] = *pMatrix[i] - (2 * (*pMatrix[i]));
            }
        }
    }
}
