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

void MergeArray(int *arr1,int *arr2,int *arr3,int *arr4,int *arr5,int n,int max)
{
	int i,j,k,l,min,m;
	i=0;
	j=0;
	k=0;
	l=0;
	m=0;
	while(i<n || j<n || k<n || l<n || m<max)
	{
		if(arr1[i]>arr2[j])
		{
			min=arr2[j++];
			arr5[m++]=min;
		}
		else
		{
			min=arr1[i++];
			arr5[m++]=min;
		}
		if(arr3[k]>arr4[l])
		{
			if(arr4[l]<min)
			{
				min=arr4[l++];
				arr5[m++]=min;
			}
			else
			{
				min=arr4[k++];
				arr5[m++]=min;
			}
		}
	}
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr1[n],arr2[n],arr3[n],arr4[n];
	int max=4*n;
	int arr5[max]={0};
	printf("Enter the content of the first array:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
	}
	printf("Enter the content of the second array:\n");
	for(int k=0;k<n;k++)
	{
		scanf("%d",&arr2[k]);
	}
	printf("Enter the content of the third array:\n");
	for(int l=0;l<n;l++)
	{
		scanf("%d",&arr3[l]);
	}
	printf("Enter the content of the fourth array:\n");
	for(int m=0;m<n;m++)
	{
		scanf("%d",&arr4[m]);
	}
	MergeArray(arr1,arr2,arr3,arr4,arr5,n,max);
	printf("Final Sorted array content are:\n");
	printArray(arr5,max);
	return 0;
}
