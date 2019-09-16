#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void MaxHeapify(int arr[],int index,int n)
{
	int l=2*index+1;
	int r=2*index+2;
	int largest=index;
	if(l<n && arr[index]<arr[l])
	{
		largest=l;
	}
	if(r<n && arr[largest]<arr[r])
	{
		largest=r;
	}
	if(largest!=index)
	{
		swap(arr[largest],arr[index]);
		MaxHeapify(arr,largest,n);
	}
	return;
}

void convertMinToMax(int arr[],int n)
{
	int i;
	for(i=(n-2)/2;i>=0;i--)
	{
		MaxHeapify(arr,i,n);
	}
	for(int i=0;i<n;i++)
	{
		std::cout<<arr[i]<<" ";
	}
	return;
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n;
		std::cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		convertMinToMax(arr,n);
		std::cout<<endl;
	}
	return 0;
}
