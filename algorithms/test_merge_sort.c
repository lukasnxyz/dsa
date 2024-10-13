#include <stdio.h>
#include "merge_sort.h"

int main(void) {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    print_array(arr, arr_size);

    merge_sort(arr, 0, arr_size - 1);

    printf("Sorted array is \n");
    print_array(arr, arr_size);

    return 0;
}
