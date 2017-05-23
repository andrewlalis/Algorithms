/*
handystack.h
Created By:
	Andrew Lalis (andrewlalisofficial@gmail.com)
	23 May 2017
This file is free to use, as long as the above comment remains in the file.
Please contact the author regarding bugs and/or feature requests.
*/

#ifdef LIST_TYPE

#include "templates.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
Linked List:
	The linked list is a list of items of arbitrary value that are linked via a pointer to the next element, and the last element has a null pointer. The list does not try to maintain any particular order.
*/

#define LIST_NODE TEMPLATE(LIST_TYPE,list)

/*
List structure:
	Each list node will contain a piece of data, which is of an arbitrary type, and a pointer to the next element.
*/

typedef struct LIST_NODE LIST_NODE;

struct LIST_NODE {
	LIST_TYPE data;
	LIST_NODE* next;
};

/*
Size of List:
	returns size of list.
*/
int TEMPLATE(size,LIST_NODE)(LIST_NODE* list){
	int size = 0;
	while (list != NULL){
		size++;
		list = list->next;
	}
	return size;
}

/*
New list:
	allocates memory for a new list item, and returns it.
*/
LIST_NODE* TEMPLATE(new,LIST_NODE)(LIST_TYPE data, LIST_NODE* next){
	LIST_NODE *n = malloc(sizeof(LIST_NODE));
	assert(n != NULL);
	n->data = data;
	n->next = next;
	return n;
}

/*
Free List:
	de-allocates memory for a list, and all next items recursively.
*/
void TEMPLATE(free,LIST_NODE)(LIST_NODE* list){
	if (list->next != NULL){
		TEMPLATE(free,LIST_NODE)(list->next);
	}
	free(list);
	list = NULL;
}

/*
Add to the list:
	Appends an item to the end of the list.
*/
void TEMPLATE(add,LIST_NODE)(LIST_TYPE data, LIST_NODE* list){
	while (list->next != NULL){
		list = list->next;
	}
	list->next = TEMPLATE(new,LIST_NODE)(data, NULL);
}

/*
Insert List;
	Inserts an item at the given index, so that the item can be retreived with the get function at that index.
*/
void TEMPLATE(insert,LIST_NODE)(LIST_TYPE data, int index, LIST_NODE* list){
	
}

/*
Get list item:
	Returns the item in a specific index of the list, or fails.
*/
LIST_TYPE TEMPLATE(get,LIST_NODE)(int index, LIST_NODE* list){
	int i = 0;
	while (i < index){
		if (list->next != NULL){
			list = list->next;
		} else {
			printf("Index specified does not exist in list.\n");
			exit(-1);
		}
		i++;
	}
	return list->data;
}

#endif