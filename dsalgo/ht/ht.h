#pragma once

#include <stddef.h>
#include <stdbool.h>

// Hash table structure: create with ht_create, free with ht_destroy.
typedef struct ht ht;

// Returns an empty hash table with INITCAP entries capacity,
// if something goes wrong, it returns NULL.
ht* ht_create(int initCap);

// Gives all the memory used for hash table allocation,
// back to the operating system.
void ht_destroy(ht* table);

// Get item with given key (NUL-terminated) from hash table. Return
// value (which was set with ht_set), or NULL if key not found.
void* ht_get(ht* table, const char* key);

// Set item with given key (NUL-terminated) to value (which must not
// be NULL). If not already present in table, key is copied to newly
// allocated memory (keys are freed automatically when ht_destroy is
// called). Return address of copied key, or NULL if out of memory.
const char* ht_set(ht* table, const char* key, void* value);

// Return number of items in hash table.
size_t ht_length(ht* table);

// Hash table iterator: create with ht_iterator, iterate with ht_next.
/*
  Here the structure declaration is needed for the way
  that the access of the fields is designed..

  BUT.. here there are fields that we might want to hide.
  TODO: hide the implementation of this struct
  	i.e. extract key/val of the iterator with functions
 */
typedef struct hti {
  const char* key;  // current key
  void* value;      // current value

  // Don't use these fields directly.
  ht* _table;       // reference to hash table being iterated
  size_t _index;    // current index into ht._entries
} hti;


// Return new hash table iterator (for use with ht_next).
hti ht_iterator(ht* table);

// Move iterator to next item in hash table, update iterator's key
// and value to current item, and return true. If there are no more
// items, return false. Don't call ht_set during iteration.
bool ht_next(hti* it);
