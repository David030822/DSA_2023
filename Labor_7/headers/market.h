//
// Created by David on 2023. 03. 27..
//

#ifndef PARCIALIS_MARKET_H
#define PARCIALIS_MARKET_H

#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    double feherje;
    double zsir;
    double szenhidrat;
}Calorie;

enum Colour{
    ZOLD = 0,
    PIROS,
    SARGA,
    LILA,
    FEHER,
    ROZSASZIN,
    NARANCS
};

typedef struct{
    char name[16];
    double weight;
    Calorie tapertek;
    enum Colour colour;
}Vegetable;

typedef struct{
    int capacity;
    int front;
    int rear;
    Vegetable *elements;
}MarketManager;

char *enumToChar(Vegetable vegetable);
void printToFile(Vegetable vegetable);

void createMarket(int capacity, MarketManager *market);
void destroyMarket(MarketManager *market);
bool isEmpty(MarketManager market);
bool isFull(MarketManager market);
void enqueue(MarketManager *market, Vegetable item);
Vegetable dequeue(MarketManager *market);
void display(MarketManager market);

#endif //PARCIALIS_MARKET_H
