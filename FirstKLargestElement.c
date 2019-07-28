#include<stdio.h>
#include<stdlib.h>

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
  int k;
  scanf("%d",&k);
  for(int i=0;i<k;i++)
  {
	  printf("%d ",values[n-1-i]);
  }
  return 0;
}
