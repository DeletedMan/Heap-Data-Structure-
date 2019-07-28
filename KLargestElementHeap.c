#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return;
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void MaxHeapify(int arr[],int index,int n)
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
		swap(&arr[index],&arr[largest]);
		MaxHeapify(arr,largest,n);
	}
}

void MaxHeapUtil(int arr[],int n)
{
	int max;
	printf("Enter the maximum Array size:\n");
	scanf("%d",&max);
	int *arr1=(int*)malloc(sizeof(int)*max);
	for(int k=0;k<n;k++)
	{
		arr1[k]=arr[k];
	}
	for(int j=n;j<max;j++)
	{
		scanf("%d",&arr1[j]);
		if(arr1[j]>arr[0])
		{
			swap(&arr1[j],&arr[0]);
			MaxHeapify(arr,0,n);
			printArray(arr,n);
		}
	}
	return;
}

void BuildHeap(int arr[],int n)
{
	int i;
	for(i=(n/2)-1;i>=0;i--)
	{
		MaxHeapify(arr,i,n);
	}
	MaxHeapUtil(arr,n);
	return;
}

int main()
{
	int i,k;
	scanf("%d",&k);
	int arr[k];
	for(i=0;i<k;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("The content of the array before sorting:\n");
	printArray(arr,k);
	BuildHeap(arr,k);
	printf("%d largest element are:\n ",k);
	printArray(arr,k);
	return 0;
}

