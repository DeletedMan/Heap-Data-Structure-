#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<map>
#include<set>
#include<list>

using namespace std;
struct MinHeap
{
	unsigned size;
	unsigned capacity;
	int* arr;
};

struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minheap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
	minheap->size=0;
	minheap->capacity=capacity;
	minheap->arr=new int[capacity];
	return minheap;
}

void Minheapify(struct MinHeap* minHeap,int index)
{
	int l=2*index+1;
	int r=2*index+2;
	int lowest=index;
	if(l<minHeap->size && minHeap->arr[l]<minHeap->arr[index])
	{
		lowest=l;
	}
	if(r<minHeap->size && minHeap->arr[lowest]<minHeap->arr[r])
	{
		lowest=r;
	}
	if(lowest!=index)
	{
		swap(minHeap->arr[lowest],minHeap->arr[index]);
		Minheapify(minHeap,lowest);
	}
}

void buildHeap(struct MinHeap* minHeap)
{
	int i;
	int n=minHeap->size-1;
	for(i=(n-1)/2;i>=0;i--)
	{
		Minheapify(minHeap,i);
	}
}

struct MinHeap* createAndBuildHeap(int arr[],int n)
{
	struct MinHeap* minHeap=createMinHeap(n);
	minHeap->size=n;
	for(int i=0;i<n;i++)
	{
		minHeap->arr[i]=arr[i];
	}
	buildHeap(minHeap);
	return minHeap;
}

int isSizeOne(struct MinHeap* minHeap)
{
	return (minHeap->size==1);
}

int ExtractMin(struct MinHeap* minHeap)
{
	int temp=minHeap->arr[0];
	minHeap->arr[0]=minHeap->arr[minHeap->size-1];
	--minHeap->size;
	Minheapify(minHeap,0);
	return temp;
}
void insert(struct MinHeap* minHeap,int data)
{
	++minHeap->size;
	int i=minHeap->size-1;
	while(i &&(data<minHeap->arr[(i-1)/2]))
	{
		minHeap->arr[i]=minHeap->arr[(i-1)/2];
		i=(i-1)/2;
	}
	minHeap->arr[i]=data;
}

int minCost(int arr[],int n)
{
	struct MinHeap* minHeap=createAndBuildHeap(arr,n);
	int cost=0;
	while(!isSizeOne(minHeap))
	{
		int first=ExtractMin(minHeap);
		int sec=ExtractMin(minHeap);
		cost+=first+sec;
		insert(minHeap,first+sec);
	}
	return cost;
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
		std::cout<<minCost(arr,n)<<endl;
	}
	return 0;
}
