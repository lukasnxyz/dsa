#include <stdio.h>

void insertion_sort(int *a, size_t n);

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
