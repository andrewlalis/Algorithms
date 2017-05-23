# Algorithms
A handy collection of C algorithms compiled into one header file for use anywhere. Feel free to include this file with any C project, as long as you keep the comment at the top with a little copyright notice.

## Table of Contents
1. [Stacks](#stack)
2. [Queues](#queue)
3. [Linked Lists](#linked-list)
4. [Heap(Priority Queue)](#heap-priority-queue)

## Stack

### Functions
```c
void new()
void free(Stack *s)
void push(item, Stack *s)
item pop(Stack *s)
void print(Stack s)
```

### Description
The stack is probably the most basic storage structure, using the 'first-in, 
first-out' approach. To define a stack, the user must first know what type the stack 
is, either a primitive type, or a **struct**. To define a stack, you must first define 
the **STACK_TYPE** to *int*, *float*, *char*, or whatever type you wish. Then, include 
the *handystack* header file.
```c
#define STACK_TYPE int 
#include "handystack.h" 
```
To define more than one stack, **STACK_TYPE** must first be undefined.
` #undef STACK_TYPE `
Then you simply define the type, and include the header again. Do not try to define two of the same type, however, as that will give all sorts of nasty errors.

### Example
The following example creates a stack of doubles, pushes 45.000 onto it, and prints the stack's characteristics.
```c
#define STACK_TYPE double
#include "handystack.h"
double_stack myStack = new_double_stack();
push_double_stack(45.000, &myStack);
print_double_stack(myStack);
```
Notice that the function names are characteristic of the **STACK_TYPE** you've defined earlier? The functions have the following basic format:
``` FUNCTION_ + STACK_TYPE + _stack ```
Where `FUNCTION` is the name of the function.

## Queue

## Linked List

## Heap (Priority Queue)
