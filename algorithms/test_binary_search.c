#include <stdio.h>
#include "binary_search.h"

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
