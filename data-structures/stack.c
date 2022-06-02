#include <stdio.h>

#define STACK_SIZE 10

struct stack {
    int ptr;
    int data[STACK_SIZE];
};

typedef struct stack stack;

void init(stack* s) {
    s->ptr = -1;
}

void push(stack* s, int data) {
    if(s->ptr == STACK_SIZE) return; 

    s->ptr++;
    s->data[s->ptr] = data;
}

void pop(stack* s) {
    if(s->ptr == -1) return;

    s->ptr--;
}

void printstack(stack* s) {
    for(int i = s->ptr; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
}

int main() {
    stack s;
    init(&s);

    push(&s, 3);
    push(&s, 2);
    push(&s, 4);

    pop(&s);

    printstack(&s);

    return 0;
}