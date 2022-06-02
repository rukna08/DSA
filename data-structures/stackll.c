// stack using linked list (ll)

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

struct node {
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

struct stack {
    int ptr;

    node* head;
    node* end;
};
typedef struct stack stack;

void insert(node** n, node** end, int data) {
    if(*n == NULL) {
        *n = malloc(sizeof(node));
        
        (*n)->data = data;
        (*n)->next = NULL;

        *end = *n;
        
        return;
    }

    node* temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    (*end)->next = temp;

    node* prev0x = *end;

    *end = temp;

    (*end)->prev = prev0x;
}

void del(node** end) {
    node* temp = (*end)->prev;

    *end = temp;
    (*end)->next = NULL;
}

void init(stack* s) {
    (*s).ptr = -1;
    
    (*s).head = NULL;
    (*s).end = NULL;
}

void push(stack* s, int data) {
    ((*s).ptr)++;

    if((*s).ptr == STACK_SIZE) return;

    insert(&((*s).head), &((*s).end), data);
}

void pop(stack* s) {
    if((*s).ptr == -1) return;
    
    ((*s).ptr)--;

    del(&(*s).end);
}

int main() {
    stack s;

    init(&s);

    push(&s, 5);
    push(&s, 3);
    push(&s, 2);

    pop(&s);

    return 0;
}