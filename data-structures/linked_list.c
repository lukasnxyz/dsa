#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int d;
  struct node *next;
} node_t;

void list_append(node_t **head, int n_d) {
  node_t *n_node = (node_t *)malloc(sizeof(node_t));
  if (n_node == NULL) {
    return;
  }

  n_node->d = n_d;
  n_node->next = NULL;

  if (*head == NULL) {
    *head = n_node;
    return;
  }

  node_t *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = n_node;
}

void list_print(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    printf("%d ", current->d);
    current = current->next;
  }
  printf("\n");
}

void list_free(node_t *head) {
  node_t *tmp;
  while (head != NULL) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

int main(void) {
  node_t *head = NULL;
  list_append(&head, 10);
  list_append(&head, 20);
  list_append(&head, 30);
  list_print(head);

  list_free(head);

  return 0;
}
