#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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
		swap(arr[index],arr[largest]);
		MaxHeapify(arr,largest,n);
	}
}

void KLargestElement(int arr[],int n,int k)
{
	int i;
	for(i=0;i<k;i++)
	{
		std::cout<<arr[0]<<" ";
		arr[0]=arr[n-1-i];
		MaxHeapify(arr,0,n-1-i);
	}
}

int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		int n,k;
		std::cin>>n>>k;
		int *arr=new int[n];
		for(int i=0;i<n;i++)
		{
			std::cin>>arr[i];
		}
		KLargestElement(arr,n,k);
	}
	return 0;
}
