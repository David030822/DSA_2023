//
// Created by David on 2023. 03. 27..
//

#include "../headers/market.h"

char *enumToChar(Vegetable vegetable) {
    char colour[15];
    switch (vegetable.colour) {
        case 0: {
            return strcpy(colour, "ZOLD");
        }
        case 1: {
            return strcpy(colour, "PIROS");
        }
        case 2: {
            return strcpy(colour, "SARGA");
        }
        case 3: {
            return strcpy(colour, "LILA");
        }
        case 4: {
            return strcpy(colour, "FEHER");
        }
        case 5: {
            return strcpy(colour, "ROZSASZIN");
        }
        case 6: {
            return strcpy(colour, "NARANCS");
        }
        default: {
            printf("Invalid colour\n");
            exit(-1);
        }
    }
}

void printToFile(Vegetable vegetable) {
    char fileName[30];
    char nameCopy[16];
    strcpy(nameCopy, strupr(vegetable.name));
    strcpy(fileName, nameCopy);
    strcat(fileName, "_");
    strcat(fileName, enumToChar(vegetable));
    FILE *fout = fopen(strcat(fileName, ".txt"), "w");
    if (!fout) {
        printf(FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    fprintf(fout, "%s, ", vegetable.name);
    fprintf(fout, "%lf, ", vegetable.weight);
    fprintf(fout, "%lf, %lf, %lf, ", vegetable.tapertek.feherje, vegetable.tapertek.zsir,
            vegetable.tapertek.szenhidrat);
    char colour[15];
    strcpy(colour, enumToChar(vegetable));
    fprintf(fout, "%s", colour);
}

void createMarket(int capacity, MarketManager *market) {
    market->capacity = capacity;
    market->front = market->rear = -1;
    market->elements = (Vegetable *) calloc(market->capacity, sizeof(Vegetable));
    /*for (int i = 0; i < market -> capacity; ++i) {
        market -> elements[i] = (Vegetable) calloc(16, sizeof (char));
    }*/
    if (!market->elements) {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}

void destroyMarket(MarketManager *market) {
    /*for (int i = 0; i < market -> capacity; ++i) {
        free(market -> elements[i]);
    }*/
    free(market->elements);
    market->front = market->rear = -1;
    market->capacity = 0;
    market = NULL;
}

bool isEmpty(MarketManager market) {
    return market.front == -1;
}

bool isFull(MarketManager market) {
    return market.rear == market.capacity - 1;
}

void enqueue(MarketManager *market, Vegetable item) {
    if (isFull(*market)) {
        printf(FULL_MESSAGE);
        return;
    }
    if (isEmpty(*market)) {
        market->front = 0;
    }
    market->elements[++market->rear] = item;
}

Vegetable dequeue(MarketManager *market) {
    if (isEmpty(*market)) {
        printf(EMPTY_MESSAGE);
        exit(-4);
    }
    int pos = market->front;
    if (market->front == market->rear) {
        market->front = market->rear = -1;
    } else {
        market->front++;
    }
    return market->elements[pos];
}

void display(MarketManager market) {
    if(isEmpty(market)){
        printf(EMPTY_MESSAGE);
        return;
    }
    printf("The elements of the queue are: ");
    /*for (int i = market.front; i < market . rear; ++i) {

    }*/
}
