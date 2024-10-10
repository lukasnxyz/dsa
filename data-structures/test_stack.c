#include "stack.h"

int main(void) {
  stack_t *s = stack_init();
  push(s, 1);
  push(s, 2);
  push(s, 3);
  stack_print(s);
  stack_free(s);

  return 0;
}
