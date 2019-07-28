#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return;
}
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void KLargest(int arr[],int k)
{
	int temp,m;
	int max;
	scanf("%d",&max);
	int *arr1=(int*)malloc(sizeof(int)*max);
	for(int i=0;i<k;i++)
	{
		arr1[i]=arr[i];
	}
	qsort (arr, k, sizeof(int), compare);
	temp=k;
	for(int j=k;j<max;j++)
	{
		scanf("%d",&arr1[j]);
		if(arr1[j]>arr[0])
		{
			swap(&arr1[j],&arr[0]);
			qsort(arr,temp,sizeof(int),compare);
		}
	}
}

int main()
{
	int k,i;
	scanf("%d",&k);
	int arr[k];
	for(i=0;i<k;i++)
	{
		scanf("%d",&arr[i]);
	}
	printArray(arr,k);
	printf("K Largest element are:\n");
	KLargest(arr,k);
	printArray(arr,k);
	return 0;
}

