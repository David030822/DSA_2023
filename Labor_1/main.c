#include "headers/functions.h"

int main()
{
    printf("The sum of 3.5 and 6.7 is: %f\n", sum(3.5, 6.7));
    printf("The minimum of 7.1, 3.3 and 6.8 is: %f\n", minimum(7.1, 3.3, 6.8));

    int n, *pArray;
    scanf("%d", &n);
    allocateMemoryForArray2(n, &pArray);

    return 0;
}
