//
// Created by David on 2023. 03. 13..
//

#ifndef LABOR_5_STACK_H
#define LABOR_5_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "constants.h"

typedef struct {
    int capacity;
    int top;
    int *elements;
}Stack;

void createStack(int capacity, Stack * stack);
void destroyStack(Stack* stack);
bool isFull(Stack stack);
bool isEmpty(Stack stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack stack);
int size(Stack stack);

#endif //LABOR_5_STACK_H
