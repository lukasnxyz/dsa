#include <stdio.h>

size_t binary_search(int arr[], size_t n, int x) {
    size_t low = 0;
    size_t high = n - 1;
    while (low <= high) {
        size_t mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int arr[] = {1, 3, 5, 7, 10, 11, 12, 13, 14, 15, 16, 17};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    int res = binary_search(arr, n, 5);
    if (res == -1) {
        printf("element does not exist in array!\n");
    } else {
        printf("element found at index: %d\n", res);
    }

    return 0;
}
