#include <stdio.h>

int main(void) {
  int prev = 0, pprev = 1;
  int next = prev + pprev;
  printf("%d %d ", prev, pprev);
  for (size_t i = 0; i < 10; ++i) {
    printf("%d ", next);
    prev = pprev;
    pprev = next;
    next = prev + pprev;
  }
  puts("\n");

  return 0;
}
