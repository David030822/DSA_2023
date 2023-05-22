#include "hash_table.h"

int main() {
    HashTable hashTable;
    createHashArray(&hashTable);

    srand(time(0));
    int data, key;
    bool ok;

    while(size(hashTable) != CAPACITY){
        data = rand();
        key = hashCode(data);
        ok = true;
        for (int i = 0; i < hashTable.size; ++i) {
            if(hashTable.items[i].key == key){
                ok = false;
                break;
            }
        }
        if(ok){
            insert(&hashTable, key, data);
        }
    }

    display(hashTable);
    printf("\n");

    printf("Give me a key to delete:\n");
    int deleteKey;
    scanf("%d", &deleteKey);

    if(deleteKey >= CAPACITY){
        printf("Invalid key!\n");
    }
    else
    {
        if(search(hashTable, deleteKey)){
            delete(&hashTable, deleteKey);
        }
        else
            printf("No item with such key!\n");
    }

    display(hashTable);

    //destroyHashArray(&hashTable);

    return 0;
}
