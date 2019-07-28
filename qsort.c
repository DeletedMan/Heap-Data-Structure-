#include <stdio.h>      
#include <stdlib.h>   

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int n;
  scanf("%d",&n);
  int values[n];
  for(int i=0;i<n;i++)
  {
	  scanf("%d",&values[i]);
  }
  qsort (values, n, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}
