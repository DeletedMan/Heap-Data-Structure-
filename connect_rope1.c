#include<stdio.h>
#include<stdlib.h>

struct MinHeap
{
	unsigned size;
	unsigned capacity;
	int *harr; 
};

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

struct MinHeap* createMinHeap(unsigned capacity)
{
	struct MinHeap* minHeap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->size=0;
	minHeap->capacity=capacity;
	minHeap->harr=malloc(sizeof(struct MinHeap)*capacity);
	if(!minHeap->harr)
	{
		return NULL;
	}
	return minHeap;
}
void minHeapify(struct MinHeap* minHeap,int index)
{
	int l=2*index+1;
	int r=2*index+2;
	int smallest=index;
	if(l<minHeap->size && minHeap->harr[l]<minHeap->harr[index])
	{
		smallest=l;
	}
	if(r<minHeap->size && minHeap->harr[r]<minHeap->harr[index])
	{
		smallest=r;
	}
	if(smallest!=index)
	{
		swap(&minHeap->harr[index],&minHeap->harr[smallest]);
		minHeapify(minHeap,smallest);
	}
}

void buildMinHeap(struct MinHeap* minHeap)
{
	int n=minHeap->size;
	for(int i=(n/2)-1;i>=0;i--)
	{
		minHeapify(minHeap,i);
	}
}

struct MinHeap* createAndBuildMinHeap(int len[],int size)
{
	struct MinHeap* minHeap=createMinHeap(size);
	for(int i=0;i<size;++i)
	{
		minHeap->harr[i]=len[i];
	}
	minHeap->size=size;
	buildMinHeap(minHeap);
	return minHeap;
}
int SizeOne(struct MinHeap* minHeap)
{
	return(minHeap->size==1);
}
void insertMinHeap(struct MinHeap* minHeap,int val)
{
	++minHeap->size;
	int i=minHeap->size-1;
	if(i && (val <minHeap->harr[(i-1)/2]))
	{
		minHeap->harr[i]=minHeap->harr[(i-1)/2];
		i=(i-1)/2;
	}
	minHeap->harr[i]=val;
}
int extractMin(struct MinHeap* minHeap)
{
	int temp=minHeap->harr[0];
	minHeap->harr[0]=minHeap->harr[minHeap->size-1];
	--minHeap->size;
	minHeapify(minHeap,0);
	return temp;
}

int minCost(int len[],int n)
{
	int cost=0;
	struct MinHeap* minHeap=createAndBuildMinHeap(len,n);
	while(!SizeOne(minHeap))
	{
		int min=extractMin(minHeap);
		int sec_min=extractMin(minHeap);
		cost=cost+(min+sec_min);
		insertMinHeap(minHeap,min+sec_min);
	}
	return cost;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("%d ",minCost(arr,n));
	return 0;
}
