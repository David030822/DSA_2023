#include "headers/linked_list.h"

int main() {
    int num1 = 234, num2 = 987;
    Node *node1 = NULL, *node2 = NULL, *node3 = NULL;
    while (num1) {
        insertAtEnd(&node1, num1 % 10);
        num1 /= 10;
    }
    while (num2) {
        insertAtEnd(&node2, num2 % 10);
        num2 /= 10;
    }
    printList(node1);
    printList(node2);

    return 0;
}
