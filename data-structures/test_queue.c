#include "queue.h"

int main(void) {
  queue_t *q = queue_init();
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  queue_print(q);
  int d = dequeue(q);
  printf("%d\n", d);
  queue_print(q);
  queue_free(q);

  return 0;
}
