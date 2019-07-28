#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void MaxHeapify(int *arr,int index,int n)
{
	int l=2*index+1;
	int r=2*index+2;
	int largest=index;
	if(l<=n && arr[l]>arr[index])
	{
		largest=l;
	}
	if(r<=n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=index)
	{
		swap(&arr[largest],&arr[index]);
		MaxHeapify(arr,largest,n);
	}
}

void deleteArray(int arr[],int key,int n)
{
	int i,search;
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			search=i;
			break;
		}
	}                    
	swap(&arr[search],&arr[n-1]);
	MaxHeapify(arr,search,n-2);
	return;
}

int main()
{
	int n,key;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the key:\n");
	scanf("%d",&key);
	printArray(arr,n);
	printf("\n");
	deleteArray(arr,key,n);
	printArray(arr,n-1);
	return 0;
}

