#include <stdio.h>
#include "insertion_sort.h"

int main(void) {
  size_t n = 5;
  int a[] = {6, 3, 5, 1, 9};

  for (size_t i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n---\n");

  insertion_sort(a, n);

  for (size_t i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
