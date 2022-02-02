#include <stdio.h>
#include <stdlib.h>

struct arraylist {
	int* array;
	int index;
	int size;
};

typedef struct arraylist arraylist;

void pushBack(arraylist** list, int data) {
	if (*list == NULL) {
		*list = malloc(sizeof(list));
		(*list)->array = malloc(sizeof(int));
		(*list)->array[0] = data;
		(*list)->index = 0;
		(*list)->size = 1;
		
		return;
	}

	(*list)->size++;
	(*list)->index++;
	(*list)->array = realloc((*list)->array, sizeof(int) * (*list)->size);
	(*list)->array[(*list)->index] = data;
}

void deleteFromEnd(arraylist** list) {
	(*list)->index--;
	(*list)->size--;
	(*list)->array = realloc((*list)->array, sizeof(int) * (*list)->size);
}

void printList(arraylist* list) {
	for (int i = 0; i < list->size; i++) {
		printf("%d\n", list->array[i]);
	}
}
 
int main() {
	arraylist* list = NULL;

	pushBack(&list, 5);
	pushBack(&list, 99);
	pushBack(&list, 222);
	pushBack(&list, 9);
	pushBack(&list, 87);
	pushBack(&list, 123);

	printList(list);

	deleteFromEnd(&list);

	printf("---\n");

	printList(list);

	return(0);
}