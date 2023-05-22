//
// Created by David on 2023. 05. 15..
//

#include "hash_table.h"

int hashCode(int key){
    return key % CAPACITY;
}

HashItem createHashItem(int key, int data) {
    HashItem item = {key, data};
    return item;
}

void createHashArray(HashTable *pHashTable) {
    pHashTable->items = (HashItem*)calloc(CAPACITY, sizeof(HashItem));
    if(!pHashTable->items)
    {
        printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    for (int i = 0; i < CAPACITY; ++i) {
        pHashTable->items[i] = dummyData;
    }
    pHashTable->size = 0;
}

void insert(HashTable *hashTable, int key, int data) {
    if(hashTable->size == CAPACITY) return;
    int index = hashCode(key);
    int i = 0;
    while(hashTable->items[(index + i) % CAPACITY].key != dummyData.key){
        i++;
    }
    hashTable->items[(index + i) % CAPACITY] = createHashItem(key, data);
    hashTable->size++;
}

void delete(HashTable *hashTable, int key) {
    if(hashTable->size == 0) return;
    int index = hashCode(key);
    if(hashTable->items[index].key == key){
        hashTable->items[index] = dummyData;
    }
    int i = index + 1;
    while(hashTable->items[(index + i) % CAPACITY].key != key){
        i++;
    }
    hashTable->items[(index + i) % CAPACITY].data = 0;
    hashTable->items[(index + i) % CAPACITY].key = 0;
}

int search(HashTable hashTable, int key) {
    if(hashTable.size == 0) return 0;
    int index = hashCode(key);
    if(hashTable.items[index].key == key){
        return hashTable.items[index].data;
    }
    int i = index + 1;
    while(hashTable.items[(index + i) % CAPACITY].key != key){
        i++;
    }
    return hashTable.items[(index + i)].data;
}

void display(HashTable hashTable) {
    if(hashTable.size == 0) return;
    for (int i = 0; i < hashTable.size; ++i) {
        printf("%d: %d - %d\n", i, hashTable.items[i].key, hashTable.items[i].data);
    }
}

int size(HashTable hashTable) {
    return hashTable.size;
}

void destroyHashArray(HashTable *pHashTable) {
    for (int i = 0; i < pHashTable->size; ++i) {
        pHashTable->items[i] = dummyData;
    }
    pHashTable->size = 0;
    free(pHashTable->items);
}
