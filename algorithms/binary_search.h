#ifndef __BINARY_SEARCH_H__
#define __BINARY_SEARCH_H__

#include <stddef.h>

// O(log n)

size_t binary_search(int arr[], size_t n, int x);

size_t binary_search(int arr[], size_t n, int x) {
    size_t low = 0, high = n - 1;
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

#endif // __BINARY_SEARCH_H__
