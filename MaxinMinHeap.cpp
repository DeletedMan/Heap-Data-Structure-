#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int MaxInMinHeap(int arr[],int n)
{
	int max=0;
	int i;
	for(i=n/2;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
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
		std::cout<<MaxInMinHeap(arr,n)<<endl;
	}
	return 0;
}
