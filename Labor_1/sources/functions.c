//
// Created by David on 2023. 02. 13..
//

#include "../headers/functions.h"

float sum(float number1, float number2)
{
    return number1 + number2;
}

float minimum(float number1, float number2, float number3)
{
    if(number1 < number2 && number1 < number3)
    {
        return number1;
    }
    if(number2 < number1 && number2 < number3)
    {
        return number2;
    }
    return number3;
}

void allocateMemoryForArray2(int n, int **dpArray)
{
    *dpArray = (int *) calloc(n, sizeof (int));
    if(!*dpArray)
    {
        printf("Error allocating array!\n");
        exit(-1);
    }
}
