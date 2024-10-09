#include <stdio.h>
#include "linked_list.h"

int main(void) {
  node_t *head = NULL;
  list_append(&head, 10);
  list_append(&head, 20);
  list_append(&head, 30);
  list_print(head);

  return 0;
}
