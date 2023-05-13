#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

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
int dequeue(Queue *);

void initQueue(Queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(Queue *q, int value) {
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL)
        return false;

    newNode->value = value;
    newNode->next = NULL;

    if(q->tail != NULL) {
        q->tail->next = newNode;
    }
    q->tail = newNode;
    if(q->head == NULL) {
        q->head = newNode;
    }

    return true;
}

int dequeue(Queue *q) {
    if(q->head == NULL) {
        return QUEUE_EMPTY;
    }

    Node *tmp = q->head;
    int result = tmp->value;
    q->head = q->head->next;
    if(q->head == NULL)
        q->tail = NULL;

    free(tmp);

    return result;
}

int main() {
    Queue q2;

    initQueue(&q2);

    enqueue(&q2, 48);
    enqueue(&q2, 19);
    enqueue(&q2, 28);

    int t;
    while((t = dequeue(&q2)) != QUEUE_EMPTY) {
        printf("t = %d\n", t);
    }

    return 0;
}
