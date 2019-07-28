#include <iostream> 
#include <queue> 

using namespace std; 

int minCost(int arr[], int n) 
{ 
	priority_queue<int, vector<int>, greater<int> > pq(arr, arr + n);  
	int res = 0; 
	while (pq.size() > 1) 
	{ 
		int first = pq.top(); 
		pq.pop(); 
		int second = pq.top(); 
		pq.pop(); 
		res += first + second; 
		pq.push(first + second); 
	} 

	return res; 
} 
int main() 
{ 
	int n;
	//int len[] = { 4, 3, 2, 6 }; 
	//int size = sizeof(len) / sizeof(len[0]);
	scanf("%d",&n);
	int len[n]; 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&len[i]);
	}
	printf("Total cost for connecting ropes is %d ",minCost(len,n)); 
	return 0; 
} 
