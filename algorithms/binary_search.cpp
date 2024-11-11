#include <iostream>
#include <cmath>

size_t binary_search(int arr[], const size_t n, const int t) {
  int l = 0;
  int r = n - 1;

  while (l <= r) {
    int m = floor((l+r)/2);
    if (arr[m] < t) {
      l = m +1;
    } else if (arr[m] > t) {
      r = m - 1;
    } else if (arr[m] == t) {
      return m;
    }
  }

  return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 10, 11, 12, 13, 14, 15, 16, 17};
    const size_t n = sizeof(arr) / sizeof(arr[0]);

    int se = 12;
    int res = binary_search(arr, n, se);

    if (res == -1) {
      std::cout << "element " << se << " does not exist in array!" << std::endl;
    } else {
      std::cout << "element " << se << " found at index: " << res << std::endl;
    }

    return 0;
}
