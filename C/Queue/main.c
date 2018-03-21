#include "Queue.h"
#include <stdio.h>

int main()
{
    printf("Ellooo\n");
    Queue * test;
    enqueue(test,2);
    enqueue(test,2);
    enqueue(test,2);
    enqueue(test,2);
    while(test == NULL){
	printf("%d",test->data);
	test = test->next;
    }
    return 0;
}
