# Algorithms
A handy collection of C algorithms compiled into one header file for use anywhere. Feel free to include this file with any C project, as long as you keep the comment at the top with a little copyright notice.

## Functionality

### Stack
The stack is probably the most basic storage structure, using the 'first-in, 
first-out' approach. To define a stack, the user must first know what type the stack 
is, either a primitive type, or a **struct**. To define a stack, you must first define 
the **STACK_TYPE** to *int*, *float*, *char*, or whatever type you wish. Then, include 
the *handystack* header file.
``` #define STACK_TYPE int 
	#include "handystack.h" ```
To define more than one stack, **STACK_TYPE** must first be undefined.
``` #undef STACK_TYPE ```
Then you simply define the type, and include the header again. Do not try to define two of the same type, however, as that will give all sorts of nasty errors.
* ``` Stack createStack() ```
* ``` void freeStack(Stack *s) ```
* ``` void pushToStack(STACK_TYPE item, Stack *s) ```
* ``` STACK_TYPE popFromStack(Stack *s) ```
* ``` void printStack(Stack s) ```

### Queue

### Linked List

### Heap (Priority Queue)
