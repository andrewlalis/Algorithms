/*
handyalgs.h
Created By:
	Andrew Lalis (andrewlalisofficial@gmail.com)
	22 May 2017
This file is free to use, as long as the above comment remains in the file.
Please contact the author regarding bugs and/or feature requests.
*/

#ifndef HANDYALGS_H
#define HANDYALGS_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/*
STACK
	The stack is a data structure in which items are stored and retrieved by the first-in, first-out basis. The stack keeps track of the index of the top item, so that the item may be taken out with pop. push will add an item to the top of the list, and increment the top variable.
*/

/*
Stack constants:
*/
//	Size allocated to the stack on creation.
#define STACK_SIZE_DEFAULT 8

/*
Stack Structure:
	Stores the top index of the stack, and a list of items in the stack.
	top: index of the top of the stack (one above top item).
	size: allocated size of the stack's list.
	items: list of items in the stack.
*/
typedef struct {
	int top;
	int size;
	int* items;
} Stack;

/*
Stack Creation:
	Creates a new stack with a default size defined above.
*/
Stack newStack(){
	Stack s;
	s.top = 0;
	s.size = STACK_SIZE_DEFAULT;
	s.items = malloc(s.size*sizeof(int));
	assert(s.items != NULL);
	return s;
}

/*
Stack Deallocation:
	Safely deallocates memory assigned to the stack's list.
*/
void freeStack(Stack s){
	free(s.items);
}

/*
Stack Push:
	Pushes an item onto a stack. If there is no more room, more memory will be allocated to accommodate the extra item.
*/
void pushToStack(int item, Stack s){
	//It is safe to push to the stack.
	if (s.top < s.size){
		s.items[s.top] = item;
	} else {
		//There was not enough space, so we must double size.
		s.size *= 2;
		s.items = realloc(s.items, s.size*sizeof(int));
		assert(s.items != NULL);
		s.items[s.top] = item;
	}
	s.top++;
}

/*
Stack Pop:
	Pops an item from the top of the stack, if it exists, or zero otherwise. Size will be checked to see if it is needed to reduce the size of the array.
*/
int popFromStack(Stack s){
	int result;
	//Check if at least one item exists in the list.
	if (s.top > 0){
		s.top--;
		result = s.items[s.top];
	} else {
		//The stack is empty.
		result = 0;
		fprintf(syserr, "STACK EMPTY");
	}
	//Check if the items array size can be reduced.
	if (s.top < (s.size / 2) && (s.size > STACK_SIZE_DEFAULT)){
		s.size /= 2;
		s.items = realloc(s.items, s.size*sizeof(int));
		assert(s.items != NULL);
	}
	return result;
}

/*
Stack Print:
	Utility function to print the formatted contents of a stack.
*/
void printStack(Stack s){
	printf("\tStack: \tItems: %d, Allocated Size: %d\n", s.top, s.size);
	for (int i = s.top-1; i >= 0; i--){
		printf("\t\tItem %d: %d\n", i+1, s.items[i]);
	}
}

#endif