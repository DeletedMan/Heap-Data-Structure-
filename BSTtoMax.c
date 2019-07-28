#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* getNode(int new_data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=new_data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void postorder(struct node* root)
{
	if(!root)
	{
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

void inorderTraversal(struct node* root,int *arr)
{
	if(!root)
	{
		return;
	}
	static int i=0;
	inorderTraversal(root->left,arr);
	arr[i++]=root->data;
	inorderTraversal(root->right,arr);
}

void BSTToMaxHeap(struct node* root,int *arr,int *i)
{
	if(!root)
	{
		return;
	}
	else
	{
		BSTToMaxHeap(root->left,arr,i);
		BSTToMaxHeap(root->right,arr,i);
		root->data=arr[++*i];
	}
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

void  convertToMaxHeapUtil(struct node *root)
{
	int arr[1000];
	int i=-1;
	inorderTraversal(root,arr);
	BSTToMaxHeap(root,arr,&i);
}

int main() 
{ 
    struct node* root = getNode(4); 
    root->left = getNode(2); 
    root->right = getNode(6); 
    root->left->left = getNode(1); 
    root->left->right = getNode(3); 
    root->right->left = getNode(5); 
    root->right->right = getNode(7);
    printf("Inorder Traversal of the above tree is given as below:\n");
    inorder(root);
    printf("\n"); 
    convertToMaxHeapUtil(root);
    printf("Post Order traversal of the above tree is given as below:\n");
    postorder(root);
    return 0; 
} 
