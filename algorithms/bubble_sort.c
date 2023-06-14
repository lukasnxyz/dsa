#include <stdio.h>

#define MAX 10

int main() {
    int set[MAX] = {4, 3, 2, 5, 9, 6, 8, 7, 1, 0};
    int swap = 0;
    int curr;

    while(swap < MAX) {
        swap += 1;
        for(int i = 0; i < MAX - 1; i++) {
            if(set[i] > set[i+1]) {
                curr = set[i];
                set[i] = set[i+1];
                set[i+1] = curr;
            } else {
                //swap = 0;
            }
        }

        for(int i = 0; i < MAX; i++) {
            printf("%d, ", set[i]);
        }

        printf("\n");
    }

    return 0;
}
