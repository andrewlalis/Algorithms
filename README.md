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
//Creates new stack.
void new();
//Frees stack memory.
void free(Stack *s);
//Pushes item to top of the stack.
void push(item, Stack *s);
//Removes item on top of the stack and returns it.
item pop(Stack *s);
//Prints stack size, memory usage.
void print(Stack s);
//Returns 1 if empty stack, 0 otherwise.
int is_empty(Stack s);
```

### Description
The stack is probably the most basic storage structure, using the 'first-in, first-out' approach. To define a stack, the user must first know what type the stack is, either a primitive type, or a `struct`. To define a stack, you must first define the `STACK_TYPE` to *int*, *float*, *char*, or whatever type you wish. Then, include the *handystack* header file.
```c
#define STACK_TYPE int 
#include "handystack.h" 
```
To define more than one stack, `STACK_TYPE` must first be undefined.
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
Notice that the function names are characteristic of the `STACK_TYPE` you've defined earlier? The functions have the following basic format:
``` FUNCTION_ + STACK_TYPE + _stack ```
Where `FUNCTION` is the name of the function.

[Back to Top](#table-of-contents)

## Queue

### Functions

```c
//Creates a new queue.
queue* new();
//Frees the queue.
void free(Queue queue);
//Returns the number of elements in the queue.
int size(Queue queue);
//Returns true if the queue is empty.
int empty(Queue queue);
//Adds an item to the queue.
void enqueue(Queue *queue, QUEUE_TYPE item);
//Dequeues an item from the queue.
QUEUE_TYPE dequeue(Queue *queue);
//Prints some information about the queue.
void print(Queue queue);
```

### Description
The queue is a data structure in which items follow a *first-in, first out* pattern, so that the order in which an item is added is remembered. Items are added via `enqueue` and removed via `dequeue`. To define a queue, you must first define the `QUEUE_TYPE` to *int, float, char,* or whatever you wish. Then, include the *handyqueue* header file.
```c
#define QUEUE_TYPE int
#include "handyqueue.h"
```
To define more than one queue, `QUEUE_TYPE` must first be undefined.
`#undef QUEUE_TYPE`
Then you can simply re-define the type, and include the header again.

### Example
The following example creates a queue of integers, and queues many powers of two onto it, and then prints the characteristics of the queue, and outputs the first element in the queue.
```c
#define QUEUE_TYPE int
#include "handyqueue.h"
int_queue q = new_int_queue();
for (int i = 2; i < 20000000; i *= 2){
	enqueue_int_queue(&q, i);
}
print_int_queue(q);
printf("First Item in queue: %d\n", dequeue_int_queue(&q));
free_int_queue(q);
```

[Back to Top](#table-of-contents)

## Linked List

### Functions
```c
//Creates a new list.
list* new(data, next);
//Recursively frees a list.
void free(List *l);
//Returns the number of elements in a list.
int size(List *l);
//Returns a new list with an item added to the front.
List* add(data, List *l);
//Returns a new list with an item inserted at an index.
List* insert(data, index, List *l);
//Returns the item at an index.
data get(index, List *l);
//Returns a new list with an item at an index removed.
List* remove(index, List *l);
```

### Description
The linked list is a list where each *node* is comprised of a piece of data and a pointer to the next node. The list can have items added, inserted, and removed. To define a list, first define the type of data the list will contain, and then include the *handylist* header file.
```c
#define LIST_TYPE float
#include "handylist.h"
```
To define multiple lists, you must first undefine **LIST_TYPE** like so.
` #undef LIST_TYPE `
Then you simply repeat the instructions above for whatever new list type you would like to make. Just be sure to not define two list types for the same type.

### Example
The following example creates a list of **char** and adds a few to the list, and prints the number added.
```c
#define LIST_TYPE char
#include "handylist.h"
char_list* myList = new_char_list('a', NULL);
myList = add_char_list('b', myList);
myList = add_char_list('c', myList);
myList = insert_char_list('g', 1, myList);
printf("List size: %d\n", size_char_list(myList));
```

[Back to Top](#table-of-contents)

## Heap (Priority Queue)

[Back to Top](#table-of-contents)