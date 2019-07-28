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

struct node* insert(struct node* root,int key)
{
	if(!root)
	{
		return newNode(key);
	}
	if(root->data > key)
	{
		root->left=insert(root->left,key);
	}
	else if(root->data < key)
	{
		root->right=insert(root->right,key);
	}
	return root;
}

int NodeCount(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	else
	{
		return NodeCount(root->left)+1+NodeCount(root->right);
	}
}

int FindMedianRec(struct node* root,int Tcount,int Ncount,int median)
{
	if(!root)
	{
		return Ncount;
	}
	int left=FindMedianRec(root->left,Tcount,Ncount,median);
	if(left==(Tcount-1)/2)
	{
		median=root->data;
	}
	if(left=(Tcount/2))
	{
		if(Tcount%2==0)
		{
			median=(median+root->data)/2;
		}
	}
	return FindMedianRec(root->right,Tcount,Ncount+1+left,median);
}

int FindMedian(struct node* root)
{
	if(!root)
	{
		return 0;
	}	
	int count=NodeCount(root);
	int median=0;
	struct node* curr=root;
	return FindMedianRec(curr,count,0,median);
}

int main()
{
	struct node* root=NULL;
	int n,i,m;
	printf("Enter the number of the nodes in BST:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		root=insert(root,m);
	}
	printf("Inorder Traversal:\n");
	inorder(root);
	printf("\n");
	printf("Median of the BST is:\n");
	printf("%d",FindMedian(root));
	return 0;
}
