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
void insert(Node **, int, char);
char valueAt(Node *, int);
void erase(Node *, int);
Node *reverse(Node *);

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

void insert(Node **head, int pos, char value) {
    if(pos < 1 || pos > size(*head)) {
        printf("Position is out of bounds!");
        return;
    }

    Node *newNode = malloc(sizeof(Node));
    Node *tmp = *head;

    for(int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
    }

    newNode->value = value;
    newNode->next = tmp->next;
    tmp->next = newNode;
}

char valueAt(Node *head, int pos) {
    if(pos < 1 || pos > size(head)) {
        printf("Position is out of bounds!");
        return ' ';
    }

    Node *tmp = head;
    char value;

    for(int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
    }

    value = tmp->value;

    return value;
}

void erase(Node *head, int pos) {
    if(pos < 1 || pos > size(head)) {
        printf("Position is out of bounds!");
        return;
    }

    Node *tmp = head;

    for(int i = 0; i < pos - 2; i++) {
        tmp = tmp->next;
    }

    Node *tmpOne = tmp->next;
    tmp->next = tmpOne->next;
}

Node *reverse(Node *head) {
    Node *prev = NULL;
    //Node *curr = head;
    Node *next = NULL;

    while(head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;

    return head;
}

int main() {
    Node *head = NULL;
    insertFront(&head, 'b');
    insertEnd(&head, 'c');
    insertEnd(&head, 'd');
    insertFront(&head, 'a');

    Node *reversed = reverse(head);
    printList(reversed);

    free(head);

    return 0;
}
