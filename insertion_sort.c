/*
 gcc insertion_sort.c -std=c99 -Wall -Wextra
*/
#include <stdio.h>

int main()
{
  int operations=0;
  int a[]= {99,1,5,9,2,8,9,6,4,4,1,-9};
  const int size=sizeof(a)/sizeof(a[0]);

  for(int j=0; j <size; j++){
    int cache = a[j];
    printf("checking %d  pos %d",cache,j);
    int i;
    for( i=j-1; i>=0; i--){
      if(a[i]>cache){
	printf("need to put %d at %d\n",a[i],i+1);
	a[i+1] = a[i];
	operations++;
      }else{
	break;
      }	
    }
    if(i != j-1){
      printf("\ninserting %d at %d\n",cache,i+1);
      a[i+1] = cache;
      operations++;
    }



  }
  printf("Operations total: %d\n",operations);
  for(int x=0;x<size;x++)
    printf("%d|",a[x]);
  printf("\n");

}
