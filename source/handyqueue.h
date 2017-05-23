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

/*
Queue:
	A storage data structure which follows the rule 'first-in, first-out', and has special functions 'enqueue' and 'dequeue' to manipulate the queue.
*/

#define QUEUE TEMPLATE(QUEUE_TYPE,queue)

/*
Queue Structure:
*/
typedef struct {
	QUEUE_TYPE* data;
	int back;
	int front;
	int size;
} QUEUE;

#endif