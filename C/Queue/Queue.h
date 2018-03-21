#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdlib.h>

typedef struct Queue {
    int data;
    struct Queue* next;
    struct Queue* previous;
} Queue;

typedef Queue* Node;
Node head = NULL;
Node tail = NULL;

Node createNode(){
    Node temp;
    temp = (Node)malloc(sizeof(Queue));
    temp->next = NULL;
    temp->previous = NULL;
    return temp;
}

void enqueue(int val){
    Node temp;
    temp = createNode();
    temp->data = val;
    if(head != NULL)
	temp->next = head;
    if(tail == NULL)
	tail = temp;
    head = temp;
}

#endif /* QUEUE_HPP */
