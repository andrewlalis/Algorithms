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

/*
LIST_NODE: node for a list.
*/
#define LIST_NODE TEMPLATE(LIST_TYPE,list)

/*
List structures:
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
New list node:
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
Free List node:
	de-allocates memory for a list, and all next items recursively.
*/
void TEMPLATE(free,LIST_NODE)(LIST_NODE* list){
	if (list->next != NULL){
		TEMPLATE(free,LIST_NODE)(list->next);
	}
	free(list);
}

/*
Add to the list:
	Appends an item to the front of the list.
*/
LIST_NODE* TEMPLATE(add,LIST_NODE)(LIST_TYPE data, LIST_NODE* list){
	LIST_NODE* newNode = TEMPLATE(new,LIST_NODE)(data,list);
	return newNode;
}

/*
Insert List;
	Inserts an item at the given index, so that the item can be retreived with the get function at that index.
*/
LIST_NODE* TEMPLATE(insert,LIST_NODE)(LIST_TYPE data, int index, LIST_NODE* list){
	if (index == 0){
		return TEMPLATE(add,LIST_NODE)(data, list);
	}
	if (list == NULL){
		printf("List is null.\n");
		exit(-1);
	}
	list->next = TEMPLATE(insert,LIST_NODE)(data, index - 1, list->next);	
	return list;
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

/*
Remove from list:
	Removes an item at an index from the list.
*/
LIST_NODE* TEMPLATE(remove,LIST_NODE)(int index, LIST_NODE* list){
	if (list == NULL){
		printf("List is null.\n");
		exit(-1);
	}
	if (index == 0){
		LIST_NODE* newList = list->next;
		free(list);
		return newList;
	}
	list->next = TEMPLATE(remove,LIST_NODE)(index-1, list->next);
	return list;
}

#endif