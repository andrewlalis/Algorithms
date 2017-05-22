typedef struct{
    char c;
    int v;
} TEST;

#include "source/handyalgs.h"

#include <stdio.h>

int main(int argc, char* argv[]){
    Stack s = newStack();
    for (int i = 2; i < 500; i+=3){
        TEST t;
        t.v = i;
        pushToStack(t, &s);
    }
    printStack(s);
    for (int i = 0; i < 100; i++){
        popFromStack(&s);
    }
    printStack(s);
}
