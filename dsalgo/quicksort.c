#include <stdio.h>
#include <string.h>

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
	  while(data[i] <= data[pivot] && i < last)
	    i++;
	  while(data[j] > data[pivot])
	    j--;
	  if(i<j)
	    {
	      temp = data[i];
	      data[i] = data[j];
	      data[j] = temp;
	    }
	}

      temp = data[pivot];
      data[pivot] = data[j];
      data[j] = temp;
      quicksort(data, first, j-1);
      quicksort(data, j+1, last);
    }
}

int
countOccur(int arr[],int exists[], int len, int val) {
  int i;
  int cntr = 0;

  for(i = 0; i < len; i++) {
    if (arr[i] == val) {
      if (exists[i] != 0) return 0;
      cntr++;
    }
  }

  return cntr;
}

int
main(void){
  int miarr[] = {4,1,3,5,21,6,26,7,232,1,5,6,2,391,93,2,14,423,234,6,6,3,32,1,34,4,56,2,7,8,4,3,12,1,4,63};
  int miarr1[] = {4,1,3,5,21,6,26,7,232,1,5,6,2,391,93,2,14,423,234,6,6,3,32,1,34,4,56,2,7,8,4,3,12,1,4,63};
  int miarr2[] = {4,1,3,5,21,6,26,7,232,1,5,6,2,391,93,2,14,423,234,6,6,3,32,1,34,4,56,2,7,8,4,3,12,1,4,63};

  int r = (sizeof(miarr)/sizeof(miarr2[0]));

  int c;
  int counts[r];
  memset(&counts, 0, r*sizeof(counts[0]));

  for (int i = 0; i < r; i++) {
    c = countOccur(miarr, counts, r, miarr[i]);
    printf("Got %4d %d times\n", miarr[i], c);
  }
}
