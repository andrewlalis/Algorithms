#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char* argv[]){
    
	#define STACK_TYPE double
	#include "source/handystack.h"
	double_stack s = new_double_stack();
	print_double_stack(s);
	
}
