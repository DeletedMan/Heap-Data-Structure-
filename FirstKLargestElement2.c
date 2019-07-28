#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void printHeap(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

void MaxHeapify(int arr[],int n,int index)
{
	int l=2*index+1;
	int r=2*index+2;
	int largest=index;
	if(l<n && arr[l]>arr[index])
	{
		largest=l;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=index)
	{
		swap(&arr[largest],&arr[index]);
		MaxHeapify(arr,n,largest);
	}
}

void buildHeap(int arr[],int n)
{
	int startIndex=(n/2)-1;
	for(int i=startIndex;i>=0;i--)
	{
		MaxHeapify(arr,n,i);
	}
	return;
}

void KLargest(int *arr,int n,int k)
{
	int i;
	i=0;
	while(i<k)
	{
		printf("%d ",arr[0]);
		swap(&arr[0],&arr[n-1-i]);
		MaxHeapify(arr,n-1-i,0);
		i++;
	}
}

int main()
{
	int n,k;
	scanf("%d",&n);
	int arr[n];
	scanf("%d",&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	buildHeap(arr,n);
	printHeap(arr,n);
	KLargest(arr,n,k);
	return 0;
}
