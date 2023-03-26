#include "headers/circular_queue.h"

int main() {
    CarQueue carQueue;
    createCarQueue(3, &carQueue);

    char *newAuto;
    newAuto = calloc(20, sizeof(char));

    while (1) {
        printf("Choose from the following options:"
               "\n\t- Check if queue is empty: 1"
               "\n\t- Check if queue is full: 2"
               "\n\t- Add a new car to the queue: 3"
               "\n\t- Remove a car from the queue: 4"
               "\n\t- Display the cars waiting in the queue: 5"
               "\n\t- Exit: 0"
               "\n\nChoose an option:");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1: {
                printf("%d\n", isCarEmpty(carQueue));
                break;
            }
            case 2: {
                printf("%d\n", isCarFull(carQueue));
                break;
            }
            case 3: {
                scanf("%s", newAuto);
                carEnqueue(&carQueue, newAuto);
                break;
            }
            case 4: {
                printf("%s\n", carDequeue(&carQueue));
                break;
            }
            case 5: {
                carDisplay(carQueue);
                break;
            }
            case 0: {
                destroyCarQueue(&carQueue);
                exit(0);
            }
            default: {
                printf("Invalid operator\n");
                exit(-1);
            }
        }
    }
}
