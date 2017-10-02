/*
handyqueue.h
Created By:
	Andrew Lalis (andrewlalisofficial@gmail.com)
	23 May 2017
This file is free to use, as long as the above comment remains in the file.
Please contact the author regarding bugs and/or feature requests.
*/

#ifdef QUEUE_TYPE

#include "templates.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*
Queue:
	A storage data structure which follows the rule 'first-in, first-out', and has special functions 'enqueue' and 'dequeue' to manipulate the queue.
*/

/*
Queue constants:
*/
#ifndef QUEUE_SIZE_DEFAULT
#define QUEUE_SIZE_DEFAULT 64
#endif

/*
QUEUE: the queue type for a specific queue.
*/
#define QUEUE TEMPLATE(QUEUE_TYPE,queue)

/*
Queue Structure:
	Each queue will contain an array of data, as well as a front, back, and size integer.
*/
typedef struct {
	QUEUE_TYPE* data;
	int back;//The index after the last element of the queue.
	int front;//The index of the first element.
	int size;//The size of the data array.
} QUEUE;

/*
Queue Creation:
	Creates a new queue with a default size defined above.
*/
QUEUE TEMPLATE(new,QUEUE)(){
	QUEUE queue;
	queue.front = 0;
	queue.back = 0;
	queue.size = QUEUE_SIZE_DEFAULT;
	queue.data = malloc(queue.size*sizeof(QUEUE_TYPE));
	assert(queue.data != NULL);
	return queue;
}

/*
Queue deallocation:
	Safely deallocates memory assigned to the queue.
*/
void TEMPLATE(free,QUEUE)(QUEUE queue){
	free(queue.data);
}

/*
Size of the queue:
	returns the size of the queue. (Number of elements in the queue.)
*/
int TEMPLATE(size,QUEUE)(QUEUE queue){
	return queue.back-queue.front;
}

/*
Enqueue:
	Enqueues an item into the queue.
*/
void TEMPLATE(enqueue,QUEUE)(QUEUE *queue, QUEUE_TYPE item){
	//Ensure that enough memory is available.
	if (queue->back == queue->size){
		queue->data = realloc(queue->data, (queue->size*2)*sizeof(QUEUE_TYPE));
		assert(queue->data != NULL);
	}
	queue->data[queue->back] = item;
	queue->back++;
}

/*
Dequeue:
	Dequeues an item from the queue.
*/
QUEUE_TYPE TEMPLATE(dequeue,QUEUE)(QUEUE *queue){
	QUEUE_TYPE item = queue->data[queue->front];
	queue->front++;
	//Check to see if it is possible to shrink the array.
	if (queue->back - queue->front < queue->size/2){
		QUEUE_TYPE* newData = malloc((queue->size/2)*sizeof(QUEUE_TYPE));
		int size = queue->back - queue->front;
		assert(newData != NULL);
		memcpy(newData, queue->data + queue->front, size*sizeof(QUEUE_TYPE));
		free(queue->data);
		queue->data = newData;
		queue->size /= 2;
		queue->front = 0;
		queue->back = size;
	}
	return item;
}

/*
Empty:
	Returns true if the queue is empty.
*/
int TEMPLATE(empty,QUEUE)(QUEUE queue){
	return (queue.back == queue.front);
}

/*
Print:
	Prints info about the queue, in well formatted fashion.
*/
void TEMPLATE(print,QUEUE)(QUEUE queue){
	printf("Queue: (Items: %d), (Size: %d), (Front: %d), (Back: %d)\n", TEMPLATE(size,QUEUE)(queue), queue.size, queue.front, queue.back);
}

#endif