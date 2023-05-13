#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} Queue;

void initQueue(Queue *);
bool enqueue(Queue *, int);
bool dequeue(Queue *);

void initQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

int main() {
    return 0;
}
