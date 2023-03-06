#include "headers/array.h"

int main()
{
    IntArray array;
    createIntArray(10, &array);
    printArray(array);

    for (int i = 0; i < array.capacity / 2; ++i) {
        insertAt(&array, i, i + 1);
    }
    printArray(array);

    for (int i = array.capacity / 2 + 1; i <= array.capacity; ++i) {
        if(i % 2 == 0)
        {
            insertFirst(&array, i);
        }
        else
        {
            insertLast(&array, i);
        }
    }
    printArray(array);

    printf("Give me a number:\n");
    int n;
    scanf("%d", &n);
    if(search(array, n) != -1)
    {
        printf("I found the requested number at the %d. position\n", search(array, n));
        int m;
        printf("Give me another number:\n");
        scanf("%d", &m);
        update(&array, search(array, n), m);
        printArray(array);
    }
    else
    {
        printf("I didn't find the requested number\n");
    }

    srand(time(NULL));
    int counter = 0;
    while(!isEmpty(array))
    {
        int r = rand() % array.capacity;
        if(r < 0)
        {
            r *= -1;
        }
        deleteItemAt(&array, r);
        if(r >= 0 && r <= array.size)
        {
            printf("Successful deletion\n");
        }
        ++counter;
    }
    printArray(array);
    printf("Number of tries: %d\n", counter);

    deallocateIntArray(&array);

    return 0;
}
