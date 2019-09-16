#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<deque>
#include<list>

using namespace std;

void MinHeapify(int arr[],int index,int n)
{
	int l=2*index+1;
	int r=2*index+2;
	int lowest=index;
	if(l<n && arr[l]<arr[index])
	{
		lowest=l;
	}
	if(r<n && arr[r]<arr[lowest])
	{
		lowest=r;
	}
	if(lowest!=index)
	{
		swap(arr[index],arr[lowest]);
		MinHeapify(arr,lowest,n);
	}
}

void replace(int arr[],int x,int n)
{
	arr[0]=x;
	MinHeapify(arr,0,n);
}

int getMin(int arr[])
{
	return arr[0];
}

void buildHeap(int arr[],int n)
{
	int i;
	for(i=(n-2)/2;i>=0;i--)
	{
		MinHeapify(arr,i,n);
	}
}

int main()
 {
	 int test;
	 std::cin>>test;
	 while(test--)
	 {
		 int k,n,x,index=0,i=0;
		 std::cin>>k>>n;
		 int *arr=new int[k];
		 while(n--)
		 {
			 std::cin>>x;
			 if(index<k-1)
			 {
				 arr[index++]=x;
				 std::cout<<"-1"<<" ";
			 }
			 else
			 {
				 if(index==k-1)
				 {
					 arr[index]=x;
					 buildHeap(arr,k-1);
				 }
				 else if(x>getMin(arr))
				 {
					 replace(arr,x,k-1);
				 }
				 std::cout<<getMin(arr)<<" ";
				 index++;
			 }
		 }
		 std::cout<<endl;
	 }
	 return 0;
 }
