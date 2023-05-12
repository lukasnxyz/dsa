#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node *next;
} Node;

int size(Node *);
void printList(Node *);
void insertFront(Node **, char);
void insertEnd(Node **, char);
void insert(Node *, int, char); /* todo */
char valueAt(Node *, int); /* todo */
void erase(Node *, int); /* todo */

Node *reverse(Node *); /* todo */
void eraseValue(Node *, char); /* todo */

int size(Node *head) {
    Node *tmp = head;
    int len = 0;
    while(tmp != NULL) {
        len++;
        tmp = tmp->next;
    }

    return len;
}

void printList(Node *head) {
    Node *tmp = head;

    while(tmp != NULL) {
        printf("%c ", tmp->value);
        tmp = tmp->next;
    }

    putchar('\n');
}

void insertFront(Node **head, char i_value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = i_value;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node **head, char i_value) {
    Node *newNode = malloc(sizeof(Node));
    Node *tmp = *head;

    newNode->value = i_value;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

int main() {
    Node *head = NULL;
    insertFront(&head, 'a');
    insertEnd(&head, 'b');
    insertEnd(&head, 'c');
    insertFront(&head, 'a');

    printList(head);
    printf("%d\n", size(head));

    free(head);

    return 0;
}
