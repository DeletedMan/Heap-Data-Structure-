#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return;
}

struct node
{
	int data;
	struct node* left;
	struct node *right;
};

struct node *newNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node* insert(struct node* root,int key)
{
	if(!root)
	{
		return newNode(key);
	}
	else
	{
		if(root->data > key)
		{
			root->right=insert(root->right,key);
		}
		else if(root->data < key)
		{
			root->left=insert(root->left,key);
		}
	}
	return root;
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
		printf("%d ",root->data);;
		inorder(root->right);
	}
}

void KLargest(struct node* root,int k,int *index)
{
	//static int c=0;
	if(!root || *index>k)
	{
		return;
	}
	KLargest(root->right,k,index);
	(*index)++;
	if(*index==k)
	{
		printf("%d ",root->data);
	}
	KLargest(root->left,k,index);
}

void ArrayToBST(int arr[],int n)
{
	int i,k;
	struct node* root=NULL;
	for(i=0;i<n;i++)
	{
		root=insert(root,arr[i]);
	}
	printf("Inorder Traversal is:\n");
	inorder(root);
	printf("\n");
	printf("Enter the value of the K:\n");
	scanf("%d",&k);
	printf("First Three Lowest Value is:\n");
	for(i=1;i<=k;i++)
	{
		int index=0;
		KLargest(root,i,&index);
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
	printf("Content of the array is:\n");
	printArray(arr,n);
	printf("\n");
	ArrayToBST(arr,n);
	return 0;
}
