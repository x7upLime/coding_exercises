#include <stdio.h>

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
main(void){
  int miarr[] = {4,1,3,5,21,6,26,7,232,1,5,6,2,391,93,2,14,423,234,6,6,3,32,1,34,4,56,2,7,8,4,3,12,1,4,63};
  int count = 12;

  quicksort(miarr, 0, (sizeof(miarr)/sizeof(miarr[0]))-1);

  for(int i = 0; i < sizeof(miarr)/sizeof(miarr[0]); i++) {
    printf("arr elem %2d is %d\n", i, miarr[i]);
  }
}
