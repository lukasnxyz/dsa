#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGTH 5
#define STACK_EMPTY INT_MIN
#define EMPTY -1

int stack[STACK_LENGTH];
int top = EMPTY;

bool push(int);
int pop();

// add value to stack[top++] position
bool push(int value) {
    if(top >= STACK_LENGTH - 1)
        return false;

    top++;
    stack[top] = value;
    return true;
}

// remove and return stack[top] and top--
int pop() {
    if(top == EMPTY)
        return STACK_EMPTY;

    int result = stack[top];
    top--;

    return result;
}

int main() {
    push(4);
    push(2);

    int t;
    while((t = pop()) != STACK_EMPTY) {
        printf("t = %d\n", t);
    }

    return 0;
}
