/*
 gcc qsort.c -std=c99 -Wall -Wextra
*/
#include <stdio.h>

int myset[]= {-22,99,1,5,9,2,8,9,6,4,1,-9,100,0,200,-10,-20,-30};
  const int mysize=sizeof(myset)/sizeof(myset[0]);
 
void dump()
{
   for(int x=0;x<mysize;x++)
    printf("%d|",myset[x]);
  printf("\n");

}
void dumpa(int *a,int s)
{
   for(int x=0;x<s;x++)
    printf("%d|",a[x]);
  printf("\n");

}

void sort(int *a, int size)
{
  if(1==size){
    return;
  }
  int pivot = a[size/2];
  printf("pivot %d for ",pivot);dumpa(a,size);
  int k=size-1;
  int i=0;
  while(1){
    while(k>=0 ){
      if(a[k]<=pivot){
	break;
      }
      k--;
     }
    while(i<size && i<=k){
      if(a[i]>=pivot){

	break;
      }
      i++;
    }
    if(i>=k){
      break;
    }
    if(a[k]!=a[i]){
      int temp = a[k];
      a[k]=a[i];
      a[i]=temp;
      printf("swapping %d[%d] and %d[%d]",a[k],i,temp,k);
      printf("      i %d k %d\n",i,k);
      k--;i++;
      dump();
    }else i++;      
  }
  sort(a, i);
  sort(a + k, size-k);
}
int main()
{
  dump();
  sort(myset,mysize);
  dump();
}
