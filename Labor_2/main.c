#include "headers/functions.h"

int main()
{
    int n, *array;
    int oszlop, sor;
    float **matrix;

    /*beolvas(&n, &array, "be.txt");
    kiir(n, array);
    printf("numberOfEvenNumbers: %d \n",numberOfEvenNumbers(n, array));*/

    readMatrix(&sor, &oszlop, &matrix, "bematrix.txt");
    printMatrix(sor, oszlop, matrix, "CON");
    negToPos(sor, oszlop, matrix);
    printMatrix(sor, oszlop, matrix, "kimenet.txt");
    printf("avg matrix: %f \n", averageOfMatrixElements(sor, oszlop, matrix));
    deallocateMemoryForMatrix(sor, &matrix);

    return 0;
}