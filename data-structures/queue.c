#include <stdio.h>

#define QUEUE_SIZE 10

struct queue {
    int first;
    int last;

    int data[QUEUE_SIZE];
};

typedef struct queue queue;

void init(queue* q) {
    q->first = 0;
    q->last = 0;
}

void enqueue(queue* q, int data) {
    if(q->last == QUEUE_SIZE) return;

    q->data[q->last] = data;
    (q->last)++;
}

void dequeue(queue* q) {
    if(q->first == q->last) return;

    for(int i = 0; i < q->last; i++) {
        q->data[i] = q->data[i + 1];
    }

    (q->last)--;
}

void printqueue(queue* q) {
    for(int i = 0; i < q->last; i++) {
        printf("%d\n", q->data[i]);
    }
}

int main() {
    queue q;
    init(&q);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);

    dequeue(&q);

    printqueue(&q);
}