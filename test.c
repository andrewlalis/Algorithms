#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_TYPE double
#include "source/handystack.h"

#define LIST_TYPE float
#include "source/handylist.h"

#define QUEUE_TYPE int
#include "source/handyqueue.h"

void printList(float_list* list){
	int size = size_float_list(list);
	for (int i = 0; i < size; i++){
		printf("\tIndex: %d, Value: %f\n", i, get_float_list(i, list));
	}
	for (int i = 0; i < 20; i++){
		printf("-");
	}
	printf("\n");
}

void printQueue(int_queue q){
	for (int i = q.front; i < q.back; i++){
		printf("\t%d. %d\n", i, q.data[i]);
	}
}

int main(int argc, char* argv[]){
    
	
	double_stack s = new_double_stack();
	push_double_stack(42.5, &s);
	print_double_stack(s);
	free_double_stack(s);
	
	int_queue q = new_int_queue();
	for (int i = 2; i < 20000000; i *= 2){
		enqueue_int_queue(&q, i);
	}
	print_int_queue(q);
	printf("First Item in queue: %d\n", dequeue_int_queue(&q));
	free_int_queue(q);
	
}
