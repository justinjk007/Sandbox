#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdlib.h>

typedef struct Queue {
    int data;
    struct Queue* next;
} Queue;

typedef Queue* Node;

Node createNode()
{
    Node temp;
    temp       = (Node)malloc(sizeof(Queue));
    temp->next = NULL;
    return temp;
}

Node enqueue(Node head, int val)
{
    Node temp;
    temp       = createNode();
    temp->data = val;
    temp = head;
    head = temp;
    return head;
}

#endif /* QUEUE_HPP */
