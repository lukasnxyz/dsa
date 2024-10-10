#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
  int *queue_arr;
  size_t len;
} queue_t;

queue_t *queue_init(void);
void queue_free(queue_t *s);
void queue_print(queue_t *s);
void enqueue(queue_t *s, int d);
int dequeue(queue_t *s);

queue_t *queue_init(void) {
  queue_t *s = (queue_t *)malloc(sizeof(queue_t));
  if (s == NULL) {
    return NULL;
  }

  s->queue_arr = NULL;
  s->len = 0;

  return s;
}

void queue_free(queue_t *s) {
  free(s->queue_arr);
  free(s);
}

void queue_print(queue_t *s) {
  for (size_t i = 0; i < s->len; ++i) {
    printf("%d ", s->queue_arr[i]);
  }
  printf("\n");
}

// add to end
void enqueue(queue_t *s, int d) {
  s->len++;
  if (s->queue_arr == NULL) {
    int *sa = (int *)malloc(sizeof(int));
    if (sa == NULL) {
      return;
    }
    s->queue_arr = sa;
    s->queue_arr[s->len - 1] = d;
    return;
  } else {
    s->queue_arr = realloc(s->queue_arr, (s->len + 1) * sizeof(int));
    s->queue_arr[s->len - 1] = d;
  }
}

int dequeue(queue_t *s) {
  if (s->len == 0) {
    return -1;
  }
  int d = s->queue_arr[0];
  s->len--;
  int *n = (int *)malloc(s->len * sizeof(int));
  for (size_t i = 1; i < s->len + 1; ++i) {
    n[i-1] = s->queue_arr[i];
  }
  free(s->queue_arr);
  s->queue_arr = n;

  return d;
}

#endif // __QUEUE_H__
