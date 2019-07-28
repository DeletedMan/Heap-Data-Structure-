#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void inorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

struct node* MaxtoMinHeap(int *arr,int n)
{
	static int i=0;
	if(i>n)
	{
		return NULL;
	}
	struct node* root=newNode(arr[i++]);
	root->left=MaxtoMinHeap(arr,n);
	root->right=MaxtoMinHeap(arr,n);
	return root;
}

void printArray(int *arr,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printArray(arr,n);
	printf("\n");
	struct node* temp=MaxtoMinHeap(arr,n);
	inorder(temp);
	return 0;
}
