#pragma once

#include <stddef.h> // for size_t

// hash tables are structures with key/value entries
typedef struct ht_entry {
  const char *key; // NULL if this slot is empty
  void *value;
} ht_entry;

struct ht{
  ht_entry *entries; // ptr to entry [0] in an array of entries
  size_t capacity;  // how many entries does the hash table has
  size_t length;   // number of used entries in the hash table
};
