#include <stdio.h>
#include <string.h>

typedef struct ht_entry ht_entry;

const char*
ht_set_entry(ht_entry *entries, size_t capacity,
	     const char *key, void *value, size_t *plength);

typedef struct{
  const char *name;
  void (*run)(void);
} test;

void
foo(void) {
  return;
}

void
TestHT_Set_EntryNULLPlength(void) {
  // random key/value
  const char *key = strdup("Arandomkey");
  int value = 11;

  ht_entry *entries;
  size_t htcap;

  size_t *plength = NULL;
  
  ht_set_entry(entries, htcap, key, (void*)&value, plength);
}

int
main(void) {
  test tests[] = {
    {"Testing ht_set_entry with NULL plength", TestHT_Set_EntryNULLPlength},
    {"asdf", foo}
  };

  for (int i = 0; i < sizeof(tests)/sizeof(test); i++) {
    printf("%s:", tests[i].name);
    tests[i].run();
    printf("\tPASS\n");
  }

  return 0;
}
