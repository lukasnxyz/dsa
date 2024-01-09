#include <stdio.h>

#define HASHMAX 100

typedef struct {
    char *name;
    struct Node *next;
} Node;

unsigned int hashFunction(char *);
void printList(Node *);
void insertFront(Node **, char *);
void insertEnd(Node **, char *);

/*
 * hash(k, m) - m is size of hash table
 * add(key, value) - if key already exists, update value
 * exists(key)
 * get(key)
 * remove(key)
 */

void printList(Node *head) {
    Node *tmp = head;

    while(tmp != NULL) {
        printf("%s ", tmp->name);
        tmp = tmp->next;
    }

    putchar('\n');
}

void insertFront(Node **head, char *value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->name = value;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node **head, char *value) {
    Node *newNode = malloc(sizeof(Node));
    Node *tmp = *head;

    newNode->name = value;
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

unsigned int hashFunction(char *name) {
    // very very simple hash function
    int sum = 0;

    for(int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }

    return sum % HASHMAX;
}

int main() {
    return 0;
}
