#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_TYPE double
#include "source/handystack.h"

#define LIST_TYPE float
#include "source/handylist.h"

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

int main(int argc, char* argv[]){
    
	
	double_stack s = new_double_stack();
	push_double_stack(42.5, &s);
	print_double_stack(s);
	
	float_list* l = new_float_list(5.0, NULL);
	l = add_float_list(6.0, l);
	l = add_float_list(7.0, l);
	l = add_float_list(8.0, l);
	printList(l);
	l = insert_float_list(15.5525, 2, l);
	l = insert_float_list(25, 0, l);
	printList(l);
	l = remove_float_list(2, l);
	printList(l);
	free_float_list(l);
	
}
