#include <stdio.h>
#include "Queue.h"

int main()
{
    struct node* queue = NULL;
    queue              = enqueue(queue, 2);
    queue              = enqueue(queue, 3);
    queue              = enqueue(queue, 4);
    queue              = enqueue(queue, 5);
    while (queue != NULL) {
        printf("%d\n", queue->value);
        queue = queue->next;
    }
    return 0;
}
