//
// Created by David on 2023. 05. 15..
//

#ifndef LABOR12A_HASH_TABLE_H
#define LABOR12A_HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define CAPACITY 31

typedef struct {
    int key;
    int data;
} HashItem;

typedef struct {
    HashItem *items;
    int size;
}HashTable;

static HashItem dummyData = {-1, 0};

int hashCode(int key);
HashItem createHashItem(int key, int data);
void createHashArray(HashTable *pHashTable);
void insert(HashTable *hashTable, int key, int data);
void delete(HashTable *hashTable, int key);
int search(HashTable hashTable, int key);
void display(HashTable hashTable);
int size(HashTable hashTable);
void destroyHashArray(HashTable *pHashTable);

#endif //LABOR12A_HASH_TABLE_H
