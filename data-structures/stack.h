#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int *stack_arr;
  size_t len;
} stack_t;

stack_t *stack_init(void);
void stack_free(stack_t *s);
void stack_print(stack_t *s);
void push(stack_t *s, int d);
int pop(stack_t *s);

stack_t *stack_init(void) {
  stack_t *s = (stack_t *)malloc(sizeof(stack_t));
  if (s == NULL) {
    return NULL;
  }

  s->stack_arr = NULL;
  s->len = 0;

  return s;
}

void stack_free(stack_t *s) {
  free(s->stack_arr);
  free(s);
}

void stack_print(stack_t *s) {
  for (size_t i = 0; i < s->len; ++i) {
    printf("%d ", s->stack_arr[i]);
  }
  printf("\n");
}

// TODO: check len is actual len bc if you pop then push, 
//  you might relloc for no reason
void push(stack_t *s, int d) {
  s->len++;
  if (s->stack_arr == NULL) {
    int *sa = (int *)malloc(sizeof(int));
    s->stack_arr = sa;
    s->stack_arr[s->len - 1] = d;
    return;
  } else {
    s->stack_arr = realloc(s->stack_arr, (s->len + 1) * sizeof(int));
    s->stack_arr[s->len - 1] = d;
  }
}

int pop(stack_t *s) {
  int d = s->stack_arr[s->len - 1];
  s->stack_arr[s->len - 1] = 0;
  s->len--;
  return d;
}

#endif // __STACK_H__
