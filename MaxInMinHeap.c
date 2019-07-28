#include<stdio.h>
#include<stdlib.h>

void printArray(int *heap,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",*(heap+i));
	}
	return;
}

int findMaximumElement(int heap[],int n)
{
	int i;
	if(n%2==0)
	{
		int max=heap[n/2];
		for(i=n/2;i<n;++i)
		{
			if(heap[i+1]>max)
			{
				max=heap[i+1];
			}
		}
		return max;
	}
	else if(n%2!=0)
	{
		int max=heap[(n/2)+1];
		for(int i=(n/2)+1;i<n;++i)
		{
			if(heap[i+1]>max)
			{
				max=heap[i+1];
			}
		}
		return max;
	}	
}

int main() 
{ 
    int n;
    scanf("%d",&n);
    int heap[n];
    for(int i=0;i<n;i++)
    {
		scanf("%d",&heap[i]);
	}
	printf("\n");
	printArray(heap,n); 
	printf("\n");
    printf("%d",findMaximumElement(heap,n));  
    return 0; 
} 
