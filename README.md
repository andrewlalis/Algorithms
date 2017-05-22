# Algorithms
A handy collection of C algorithms compiled into one header file for use anywhere. Feel free to include this file with any C project, as long as you keep the comment at the top with a little copyright notice.

## Functionality

### Stack
The stack is probably the most basic storage structure, using the 'first-in, first-out' approach. The following functions are the only ones available for stack manipulation, as it is quite a minimalistic data structure. The STACK_TYPE is a constant defined above the stack functions which can be set by the user to determine the type of items in the stack. By default it is left as an integer.
* ``` Stack createStack() ```
* ``` void freeStack(Stack *s) ```
* ``` void pushToStack(STACK_TYPE item, Stack *s) ```
* ``` STACK_TYPE popFromStack(Stack *s) ```
* ``` void printStack(Stack s) ```

### Queue

### Linked List

### Heap (Priority Queue)
