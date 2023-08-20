#include "ht.h"
#include <stdlib.h>
#include <stdio.h>

void
exit_nomem(void) {
  fprintf(stderr, "out of memory\n");
  exit(1);
}

int
getUserInpt(char *word) {
  printf("Insert key (Ctrl-D to exit): ");
  return scanf("%100s", word);
}

#define INITCAP 16

int
main(void) {
  ht *counts = ht_create(INITCAP);
  if(counts == NULL) {
    exit_nomem();
  }

  char word[101];
  while (getUserInpt(word) != EOF) {
    void *value = ht_get(counts, word);
    if(value != NULL) {
      int *pcount = (int*)value;
      (*pcount)++; // here we're updating
      		   //the value in the hash table itself
      continue;
    }

    // didn't find user str as key in ht
    int *pcount = malloc(sizeof(int));
    if (pcount == NULL ){
      exit_nomem();
    }
    *pcount = 1;
    if(ht_set(counts, word, pcount) == NULL ){
      exit_nomem();
    }
  }

  hti *it = ht_iterator(counts);
  printf("\n\nOutcome:\n");
  while (ht_next(it)) {
    char *key = NULL;
    int val = 0;
    htiter_extract(it, &key, &val);
    
    printf("%s %d\n", key, val);
  }

  printf("Hash table total length: %d\n", (int)ht_length(counts));

  ht_destroy(counts);
  return 0;
}
