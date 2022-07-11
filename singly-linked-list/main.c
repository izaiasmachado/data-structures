#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

int main() {
    SinglyLinkedListNode* head = createSinglyLinkedListNode();
    head = insertSinglyLinkedListNode(head, 1);
    head = insertSinglyLinkedListNode(head, 2);
    head = insertSinglyLinkedListNode(head, 3);
    head = insertSinglyLinkedListNode(head, 4);
    head = insertSinglyLinkedListNode(head, 5);
    head = removeSinglyLinkedListNode(head, 4);

    printSinglyLinkedList(head); // 5 3 2 1

    head = searchSinglyLinkedListNode(head, 3); // set as head node with date 3
    head = removeSinglyLinkedListRecursive(head, 2); // removes node with date 2
    
    head = invertSinglyLinkedList(head);
    printSinglyLinkedList(head); // 1 3
    head = invertSinglyLinkedList(head);
    printInvertedSinglyLinkedListRecursive(head); // 1 3
    
    freeSinglyLinkedList(head); // frees all nodes in the list
    return 0;
}