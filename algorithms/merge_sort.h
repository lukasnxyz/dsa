#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include <stdio.h>

// O(n log n)

void merge(int arr[], size_t left, size_t mid, size_t right);
void merge_sort(int arr[], size_t left, size_t right);
void print_array(int arr[], size_t n);

void merge(int arr[], size_t left, size_t mid, size_t right) {
    size_t i, j, k;
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    size_t L[n1], R[n2];

    for (i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void print_array(int arr[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    puts("\n");
}

#endif // __MERGE_SORT_H__
