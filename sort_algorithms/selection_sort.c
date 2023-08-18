#include <stdio.h>

#define MAX 10

int main() {
    int set[MAX] = {4, 3, 2, 5, 9, 6, 8, 7, 1, 0};
    int curr;
    int min;

    for(int i = 0; i < MAX; i++) {
        for(int y = 0; y < MAX; y++) {
            printf("%d, ", set[y]);
        }
        printf("\n");

        min = i;

        for(int x = i; x < MAX - 1; x++) {
            if(set[x] < set[min]) {
                min = x;
            }
        }

        if(set[min] == set[i]) {
            continue;
        } else {
            curr = set[i];
            set[i] = set[min];
            set[min] = curr;
        }
    }

    return 0;
}
