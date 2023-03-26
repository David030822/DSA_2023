#include "headers/regular_queue.h"

int main() {
    Queue carQueue;
    createQueue(6, &carQueue);

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
                printf("%d\n", isEmpty(carQueue));
                break;
            }
            case 2: {
                printf("%d\n", isFull(carQueue));
                break;
            }
            case 3: {
                scanf("%s", newAuto);
                enqueue(&carQueue, newAuto);
                break;
            }
            case 4: {
                printf("%s\n", dequeue(&carQueue));
                break;
            }
            case 5: {
                display(carQueue);
                break;
            }
            case 0: {
                destroyQueue(&carQueue);
                exit(0);
            }
            default: {
                printf("Invalid option\n");
                exit(-1);
            }
        }
    }
}
