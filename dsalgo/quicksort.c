#include <x7ht.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef DBG
size_t array_size_global;
#define PRINTARR(arr)						\
  do {								\
    for (size_t i = 0; i < array_size_global; i++) {		\
      printf("%d ", arr[i]);					\
    }								\
    printf("\n");						\
  }while(0)

#define DEBUG(format, ...) \
  printf("[%s:%d] " format, __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define DEBUG(format, ...)
#define PRINTARR(int)
// It will basically become a noop: `;`
#endif

// To sort an array in full,
// FIRST should be 0,
// LAST should be the index of the last element (not arrsize!)
// if array size is supplied instead.. strange things will happen.
void
quicksort(int data[], int first, int last){
  int i, j, pivot, temp;
  if (first < last)
    {
      pivot = first;
      i = first;
      j = last;

      while(i<j)
	{
	  while(data[i] <= data[pivot] && i < last) {
	    DEBUG("data[i] <= data[pivot] && i < last\n");
	    DEBUG("data[%d] <= data[%d] && %d < %d\n", i, pivot, i, last);
	    i++;
	    DEBUG("Incremented i to %d\n", i);
	  }
	  
	  while(data[j] > data[pivot]) {
	    DEBUG("data[j] > data[pivot]\n");
	    DEBUG("data[%d] > data[%d]\n", j, pivot);
	    j--;
	    DEBUG("Incremented j to %d\n", j);
	  }
	  
	  if(i<j)
	    {
	      DEBUG("i is < than j: %d < %d\n", i, j);
	      DEBUG("swapping values\n");
	      /*
		If index i is smaller than index j
		we just swap the values in the array
	       */
	      temp = data[i];
	      data[i] = data[j];
	      data[j] = temp;
	    }
	  DEBUG("End of iteration:\n");
	  DEBUG("array looks like this: ");
	  PRINTARR(data);
	  DEBUG("Indices: i (%d), j (%d)\n", i, j);
	}

      DEBUG("i is not longer < j; main while loop ends\n");

      DEBUG("swapping data[pivot] with data[j]:\n");
      DEBUG("pivot (%d), j (%d); data[pivot] (%d), data[j] (%d)\n", pivot, j, data[pivot], data[j]);
      temp = data[pivot];
      data[pivot] = data[j];
      data[j] = temp;

      DEBUG("array looks like this: ");
      PRINTARR(data);

      DEBUG("calling quicksort on array, with first (%d) and last (%d)\n", first, j-1);
      DEBUG("and after that, another quicksort on array, with first (%d) and last (%d)\n", j+1, last);
      quicksort(data, first, j-1);
      quicksort(data, j+1, last);
    }
}

int
populateHT(ht *table, int arr[], size_t arrsize) {
#define ENOMEM -1  
  size_t i;
  int retcode;
  int *val;
  char *k = malloc(sizeof(char)*5); //assuming ints are no bigger than 4 digits

  for (i = 0; i < arrsize; i++) {
    retcode = sprintf(k, "%d", arr[i]);
    if (retcode <= 0) {
      printf("Unable to convert int to string\n");
      return ENOMEM;
    }
    
    val = (int*)ht_get(table, k);
    if (val != NULL) {
      *val = *val+1;
      ht_set(table, k, val);
      continue;
    }
    
    val = malloc(sizeof(int));
    *val = 1;
    ht_set(table, k, val);
  }

  return arrsize;
}

void
checkSameHT(ht *ht1, ht *ht2){
  int *v;
  int vs;
  char *k = NULL;
  hti *it = ht_iterator(ht1);
    
  while(ht_next(it)) {
    htiter_extract(it, &k, &vs);

    v = (int*)ht_get(ht2, k);
    if (v == NULL) {
      printf("someway.. we had a key (%s) that is not present in the ht. EXITING..\n", k);
      exit(-1);
    }
    
    if (*v != vs) {
      printf("MISMATCH found between %s in miarr and miarr sorted: miarr(%d times) - miarr_s(%d times)\n", k, *v, vs);
      exit(-1);
    }

    printf("We've got %3s, %d time(s)\n", k, *v);
  }
}

int
main(void){
  int miarr[] = {4,1,3,5,21,6,26,7,232,1,5,6,2,391,93,2,14,423,234,6,6,3,32,1,34,4,56,2,7,8,4,3,12,1,4,63};
  int r = (sizeof(miarr)/sizeof(miarr[0]));
  #ifdef DBG
  array_size_global = r; //DEBUG
  #endif

  ht *table1 = ht_create(r);
  ht *table2 = ht_create(r);;

  populateHT(table1, miarr, r);
  DEBUG("input array looks like this: ");
  PRINTARR(miarr);
  quicksort(miarr, 0, r-1);  
  populateHT(table2, miarr, r);

  checkSameHT(table1, table2);

  return 0;
}
