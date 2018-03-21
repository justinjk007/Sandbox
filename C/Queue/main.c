#include <stdio.h>
#include "Queue.h"

int main()
{
    struct node* queue = NULL;
    struct node* temp  = NULL;

    temp = enqueue(queue, 2);
    if (queue == NULL) queue = temp;
    temp = enqueue(queue, 3);
    if (queue == NULL) queue = temp;
    temp = enqueue(queue, 4);
    if (queue == NULL) queue = temp;
    temp = enqueue(queue, 5);
    if (queue == NULL) queue = temp;

    temp  = queue;
    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }

    queue = dequeue(queue);
    queue = dequeue(queue);

    while (queue != NULL) {
        printf("%d\n", queue->value);
        queue = queue->next;
    }
    return 0;
}
