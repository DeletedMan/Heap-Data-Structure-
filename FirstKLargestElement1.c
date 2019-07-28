#include<stdio.h>
#include<stdlib.h>


void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return;
}

void KLargest(int arr[],int k,int n)
{
	int i=0,max;
	while(i<k)
	{
		max=arr[0];
		for(int j=0;j<n-i;j++)
		{
			if(arr[j]>max)
			{
				max=arr[j];
			}
		}
		printf("%d ",max);
		swap(&max,&arr[n-1-i]);
		i++;
	}
}

int main()
{
	int n,k;
	printf("Enter the size of the array:\n");
	scanf("%d",&n);
	printf("Enter the value of k:\n");
	scanf("%d",&k);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Our Array are:\n");
	printArray(arr,n);
	printf("\n");
	KLargest(arr,k,n);
	return 0;
}

