#include <stdio.h>
#include <stdlib.h>

// node structure
struct node {
    int data;
    struct node* next;
};
typedef struct node node;

// insertion
void insert(node** n, int data) {
    if(*n == NULL) {
        *n = malloc(sizeof(node));
        (*n)->data = data;
        (*n)->next = NULL;
        return;
    }

    node* temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    for(node* i = *n; i != NULL; i = i->next) {
        if(i->next == NULL) {
            i->next = temp;
            return;
        }
    }
}

// printing
void printlist(node* n) {
    for(node* i = n; i != NULL; i = i->next) printf("%d\n", i->data);
}

int main() {
    node* n = NULL;
    insert(&n, 1);
    insert(&n, 1);
    insert(&n, 1);
    insert(&n, 1);
    
    printlist(n);

    return 0;
}