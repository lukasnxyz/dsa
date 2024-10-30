#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include <stdlib.h>
#include <stdbool.h>

/* Hash table
 * - basically arrays that are indexed via hash functions
 */

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


#endif /* __HASH_TABLE_H__ */
