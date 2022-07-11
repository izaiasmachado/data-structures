#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

typedef struct SinglyLinkedListNode SinglyLinkedListNode;

/* Create */
SinglyLinkedListNode* createSinglyLinkedListNode();

/* Update */
SinglyLinkedListNode* insertSinglyLinkedListNode(SinglyLinkedListNode* head, int data);
SinglyLinkedListNode* invertSinglyLinkedList(SinglyLinkedListNode* head);

/* Read */
int isSinglyLinkedListNodeEmpty(SinglyLinkedListNode* node);
SinglyLinkedListNode* searchSinglyLinkedListNode(SinglyLinkedListNode* head, int data);
void printSinglyLinkedList(SinglyLinkedListNode* head);
void printInvertedSinglyLinkedListRecursive(SinglyLinkedListNode* head);

/* Delete */
SinglyLinkedListNode* removeSinglyLinkedListNode(SinglyLinkedListNode* head, int data);
SinglyLinkedListNode* removeSinglyLinkedListRecursive(SinglyLinkedListNode* head, int data);
SinglyLinkedListNode* freeSinglyLinkedListNode(SinglyLinkedListNode* node);
void freeSinglyLinkedList(SinglyLinkedListNode* head);