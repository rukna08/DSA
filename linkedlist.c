#include <stdio.h>
#include <stdlib.h>





// node structure.
struct node {
    int data;
    struct node* next;
};
typedef struct node node;





// insertion of each element one after the other.
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





// deletion of the whole list.
void deletelist(node** n) {
    node* t1 = *n;
    node* t2;

    while(t1 != NULL) {
        t2 = t1->next;
        free(t1);
        t1 = t2;
    }

    *n = NULL;
}





// delete the first element of the list.
void deletehead(node** n) {
    node* t1 = *n;
    *n = (*n)->next;
    free(t1);
}





// delete the last element of the list.
void deletelast(node** n) {

    for(node* i = *n; i != NULL; i = i->next) {

        if(i->next->next == NULL) {
            node* j = i->next;
            free(j);
            i->next = NULL;
            return;
        }
    
    }

}




// delete the element in the specified position.
void deleteatpos(node** n, int position) {
    int k = 1;
    
    for(node* i = *n; i != NULL; i = i->next) {

        if(k == position-1) {
            node* j = i->next;
            i->next = i->next->next;
            free(j);
        }
        
        k++;
    }
}





// printing the whole list.
void printlist(node* n) {
    if(n == NULL) {
        printf("List is empty.\n");
        return;
    }

    for(node* i = n; i != NULL; i = i->next) printf("%d\n", i->data);
}





int main() {
    node* n = NULL;
    node* n2 = NULL;
    
    insert(&n, 1);
    insert(&n, 2);
    insert(&n, 3);
    insert(&n, 4);
    
    deleteatpos(&n, 3);

    printlist(n);

    return 0;
}