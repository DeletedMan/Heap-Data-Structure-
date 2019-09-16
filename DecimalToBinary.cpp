#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void printArray(int arr[],int n)
{
	int i;
	for(i=n;i>=0;i--)
	{
		std::cout<<arr[i];
	}
	
}
void convertToBinary(long long int n)
{
	int i=0;
	int arr[10000];
	while(n>0)
	{
		int rem=n%2;
		arr[i++]=rem;
		n=n/2;
	}
	printArray(arr,i-1);
	std::cout<<" ";
}
int main()
{
	int test;
	std::cin>>test;
	while(test--)
	{
		long long int n;
		std::cin>>n;
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				std::cout<<"1"<<" ";
			}
			else
			{
				convertToBinary(i);
			}
		}
		std::cout<<endl;
	}
	return 0;
}
