#include "ht_structs.h"
#include "ht.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* ht_set_entry(ht_entry *entries, size_t capacity,
			 const char *key, void *value, size_t *plength);

typedef struct{
  const char *name;
  void (*run)(void);
} TestCase;

#define INITCAP 15

void
TestHT_Set_EntryNULLPlength(void) {
  // random key/value
  const char *key = strdup("Arandomkey");
  int value = 11;
  int cap = 10;
  ht_entry *hte;

  hte = (ht_entry*) calloc(cap, sizeof(ht_entry));
  
  ht_set_entry(hte, cap, key, &value, NULL);
}

int
main(void) {
  TestCase tests[] = {
    {"Testing ht_set_entry with NULL plength", TestHT_Set_EntryNULLPlength},
  };

  for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
    printf("%s:", tests[i].name);
    tests[i].run();
    printf("\tPASS\n");
  }

  return 0;
}
