#include <iostream>

void swap(int *arr, size_t a, size_t b) {
  int c = arr[b];
  arr[b] = arr[a];
  arr[a] = c;
}

void bubble_sort(int *arr, size_t n) {
  bool swapped;
  for (size_t i = 0; i < n-1; ++i) {
    swapped = false;
    for (size_t j = 0; j < n-i-1; ++j) {
      if (arr[j] > arr[j+1]) {
        swap(arr, j, j+1);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

void print_array(int arr[], size_t n) {
  for (size_t i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int arr[] = {5, 3, 1, 5, 10, 2, 9, 7, 6, 4, 8};
  size_t n = sizeof(arr)/sizeof(int);

  print_array(arr, n);
  bubble_sort(arr, n);
  print_array(arr, n);

  return 0;
}
