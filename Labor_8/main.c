#include "headers/single_linked_list.h"

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

    int m = 0;
    while (!(isEmpty(node1) || isEmpty(node2))) {
        insertAtEnd(&node3, (node1->data + node2->data + m) % 10);
        m = (node1->data + node2->data) / 10;
        deleteFromBeginning(&node1);
        deleteFromBeginning(&node2);
    }
    if (m)
        insertAtEnd(&node3, m);
    printList(node3);

    Node* node4 = NULL;
   char character;
    do {
        scanf("%c", &character);
        if(strchr("aeiou", character)){
            insertAtBeginning(node4, );
        }
        else
        {
            insertAtEnd(node4, );
        }
    }while(character != 'x');

    printList(node4);

    return 0;
}
