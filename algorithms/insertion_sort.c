#include <stdio.h>

void insertion_sort(int *a, size_t n) {
  for (size_t i = 1; i < n; i++) {
    int j = i - 1;
    int h = a[i];
    while (j >= 0 && h < a[j]) {
      a[j+1] = a[j];
      j = j - 1;
    }
    a[j+1] = h;
  }
}

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
