#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* enqueue(struct node* queue, int value)
{
    struct node* new_node = NULL;
    new_node              = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        exit(-1);
        return NULL;
    }
    new_node->value = value;
    new_node->next  = NULL;
    if (queue == NULL) {
        queue = new_node;
    } else {
        while (queue->next != NULL) {
            queue = queue->next;
        }
        queue->next = new_node;
    }
    return new_node;
}

struct node* dequeue(struct node* queue)
{
    struct node* temp;
    if (queue == NULL) {
        return NULL;
    } else {
        temp = queue->next;
        free(queue);
        return temp;
    }
}

#endif /* QUEUE_HPP */
