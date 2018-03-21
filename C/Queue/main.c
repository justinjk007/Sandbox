#include <stdio.h>
#include "Queue.h"

int main()
{
    Queue* queue = NULL;
    Queue* temp  = NULL;

    temp = enqueue(queue, 2);
    if (queue == NULL) queue = temp;
    temp = enqueue(queue, 3);
    if (queue == NULL) queue = temp;
    temp = enqueue(queue, 4);
    if (queue == NULL) queue = temp;
    temp = enqueue(queue, 5);
    if (queue == NULL) queue = temp;

    printf("After enquing 4 elements\n");
    temp  = queue;
    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }

    queue = dequeue(queue);
    queue = dequeue(queue);

    printf("\nAfter dequeuing 2 elements\n");
    while (queue != NULL) {
        printf("%d\n", queue->value);
        queue = queue->next;
    }
    return 0;
}
