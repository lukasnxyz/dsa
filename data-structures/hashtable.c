#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  const char *key;
  void *value;
} ht_entry;

typedef struct {
  ht_entry *entries;
  size_t capacity;
  size_t length;
} ht;

#define INITIAL_CAPACITY 16 // can't be 0

ht *ht_create(void) {
  ht *table = (ht *)malloc(sizeof(ht));
  if (table == NULL) {
    return NULL;
  }
  table->length = 0;
  table->capacity = INITIAL_CAPACITY;

  table->entries = (ht_entry *)calloc(table->capacity, sizeof(ht_entry));
  if (table->entries == NULL) {
    free(table);
    return NULL;
  }
  return table;
}

void ht_destroy(ht *table) {
  for (size_t i = 0; i < table->capacity; i++) {
    free((void *)table->entries[i].key);
  }

  free(table->entries);
  free(table);
}

void *ht_get(ht *table, const char *key);
const char *ht_set(ht *table, const char *key, void *value);
size_t ht_length(ht *table);

typedef struct {
  const char *key;
  void *value;

  ht *_table;
  size_t _index;
} hti;

hti ht_iterator(ht *table);
bool ht_next(hti *it);





void exit_nomem(void) {
  fprintf(stderr, "out of memory!\n");
  exit(1);
}

int main(void) {
  ht *counts = ht_create();
  if (counts == NULL) {
    exit_nomem();
  }

  char word[101];
  while (scanf("%100s", word) != EOF) {
    void *value = ht_get(counts, word);
    if (value != NULL) {
      int *pcount = (int *)value;
      (*pcount)++;
      continue;
    }

    int *pcount = malloc(sizeof(int));
    if (pcount == NULL) {
      exit_nomem();
    }
    *pcount = 1;
    if (ht_set(counts, word, pcount) == NULL) {
      exit_nomem();
    }
  }

  hti it = ht_iterator(counts);
  while (ht_next(&it)) {
    printf("%s %sd\n", it.key, *(int *)it.value);
    free(it.value);
  }

  printf("%d\n", (int)ht_length(counts));

  ht_destroy(counts);
  return 0;
}
