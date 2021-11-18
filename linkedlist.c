#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node* n, int data) {
    if(n == NULL) {
        printf("inside n as its null\n");
        struct node* i = n;
        i = (struct node*)malloc(sizeof(struct node));
        i->data = data;
        i->next = NULL;
    } else {
        for(struct node* i = n; i != NULL; i = i->next) {
            if(i->next == NULL) {
                struct node* temp = i;
                i->next = (struct node*)malloc(sizeof(struct node));
                i = i->next;
                i->data = data;
                i->next = NULL;
                temp->next = i;

                return;
            }
        }
    }
}

void printList(struct node* n) {
    for(struct node* i = n; i != NULL; i = i->next) {
        printf("%d ", i->data);
    }
    printf("\n");
}

int main() {
    // struct node* n = (struct node*)malloc(sizeof(struct node));;
    // n->data = 99;
    // n->next = NULL;
    
    struct node* n = NULL;

    insert(n, 1);
    insert(n, 2);
    insert(n, 3);
    insert(n, 4);

    printList(n);

    return 0;
}