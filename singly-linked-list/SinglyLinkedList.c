#include <stdio.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

/* Create */
// creates a null pointer representing the tail of an empty singly linked list
SinglyLinkedListNode* createSinglyLinkedListNode() {
    return NULL;
}

/* Update */
// insert a node at the tail of a singly linked list
SinglyLinkedListNode* insertSinglyLinkedListNode(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* node = (SinglyLinkedListNode*) malloc(sizeof(SinglyLinkedListNode)); 
    node -> data = data; 
    node -> next = head; 
    return node;
}

// invert singly linked list
SinglyLinkedListNode* invertSinglyLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* previous = NULL;
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* next = head;

    while(!isSinglyLinkedListNodeEmpty(current)) {
        next = next -> next; // sets the next node to the current node's next
        current -> next = previous; // sets the current node's next to the previous node
        previous = current; // sets the previous node to the current node
        current = next; // sets the current node to the next node
    } 

    return previous;
}

/* Read */
// checks if a singly linked list node is empty
int isSinglyLinkedListNodeEmpty(SinglyLinkedListNode* node) {
    return node == NULL;
}

// search data in singly linked list
SinglyLinkedListNode* searchSinglyLinkedListNode(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* node = head;
    while (!isSinglyLinkedListNodeEmpty(node)) {
        if (node -> data == data) {
            return node;
        }
        node = node -> next;
    }
    return NULL;
}

// print singly linked list
void printSinglyLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;

    while (!isSinglyLinkedListNodeEmpty(current)) {
        printf("%d ", current -> data);
        current = current -> next;
    }

    printf("\n");
}

// print inverted singly linked list recursive
void printInvertedSinglyLinkedListRecursive(SinglyLinkedListNode* head) {
    if (isSinglyLinkedListNodeEmpty(head)) return;
 
    printInvertedSinglyLinkedListRecursive(head -> next);
    printf("%d ", head -> data);
}

/* Delete */
// remove singly linked list node by data
SinglyLinkedListNode* removeSinglyLinkedListNode(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* node = head;
    SinglyLinkedListNode* previous = createSinglyLinkedListNode();

    while (!isSinglyLinkedListNodeEmpty(node)) {
        if (node -> data == data) {
            /* If the node is the head, then we need to update the head.
             * If the node is not the head, then we need to update the previous node's next. 
             */
            if (isSinglyLinkedListNodeEmpty(previous)) {
                // The node is removed and the it is returned it's next.
                head = freeSinglyLinkedListNode(node);
            } else {
                previous -> next = node -> next;
            }

            return head;
        }
        previous = node;
        node = node -> next;
    }
    return head;
}

// recursive remove nodes from a singly linked list.
SinglyLinkedListNode* removeSinglyLinkedListRecursive(SinglyLinkedListNode* head, int data) {
    if (isSinglyLinkedListNodeEmpty(head)) return head;

    // If the head is the node to be removed, then we need to update the head with it's next.
    if (head -> data == data) return freeSinglyLinkedListNode(head);
    
    // Otherwise, we need to update the head's next.
    head -> next = removeSinglyLinkedListRecursive(head -> next, data);
    return head;
}

// free a singly linked list node.
SinglyLinkedListNode* freeSinglyLinkedListNode(SinglyLinkedListNode* node) {
    SinglyLinkedListNode* next = node -> next;
    free(node);
    return next;
}

// free a singly linked list.
void freeSinglyLinkedList(SinglyLinkedListNode* head) {
    while (!isSinglyLinkedListNodeEmpty(head)) {
        head = freeSinglyLinkedListNode(head);
    }   
}