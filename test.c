#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]){
    
	#define STACK_TYPE double
	#include "source/handystack.h"
	double_stack s = new_double_stack();
	push_double_stack(42.5, &s);
	print_double_stack(s);
	
	#ifdef LIST_TYPE
	#undef LIST_TYPE
	#endif
	#define LIST_TYPE float
	#include "source/handylist.h"
	float_list* l = new_float_list(5.0, NULL);
	add_float_list(6.0, l);
	add_float_list(7.0, l);
	add_float_list(8.0, l);
	printf("%d\n", size_float_list(l));
	printf("%f\n", get_float_list(3, l));
	free_float_list(l);
	
}
