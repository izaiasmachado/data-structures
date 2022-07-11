# Singly Linked List
Each node has the next element wich is other node and it's data. An explanation to this problem can be found in a [video](https://www.youtube.com/watch?v=vcQIFT79_50) of [My Code School](https://www.youtube.com/user/mycodeschool).

## Applications
- Implementation of stacks and queues
- Graph adjencency lists
- Long arithmetic operations

## Struct
- [Header](./SinglyLinkedList.h)
- [Implementation](./SinglyLinkedList.c)
- [Example Code](./main.c)

```c
struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
```

## Reference
- [Linked Lists Problems - Hacker Rank](https://www.hackerrank.com/domains/data-structures?filters%5Bsubdomains%5D%5B%5D=linked-lists&filters%5Bdifficulty%5D%5B%5D=easy)
- [Application Of Linked Lists - GeeksForGeeks](https://www.geeksforgeeks.org/applications-of-linked-list-data-structure/)