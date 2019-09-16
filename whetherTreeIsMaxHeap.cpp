#include<stack>
#include<bits/stdc++.h>
#include <iostream>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int new_data)
{
	struct node* newnode=new node();
	newnode->data=new_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

int isMaxHeap(struct node* root)
{
	if(!root->left && !root->right)
	{
		return 1;
	}
	if(root->right==NULL)
	{
		return(root->data>=root->left->data);
	}
	if(root->data>=root->left->data && root->data>=root->right->data)
	{
		return(isMaxHeap(root->left) && isMaxHeap(root->right));
	}
	else
	{
		return 0;
	}
}

int countNodes(struct node* root)
{
	if(!root)
	{
		return 0;
	}
	else
	{
		return(countNodes(root->left)+1+countNodes(root->right));
	}
}

int isCompleteTree(struct node* root,int index,int node_count)
{
	if(!root)
	{
		return 1;
	}
	if(index>=node_count)
	{
		return 0;
	}
	return(isCompleteTree(root->left,2*index+1,node_count) && isCompleteTree(root->right,2*index+2,node_count));
}

int isHeap(struct node* root)
{
	if(!root)
	{
		return 1;
	}
	int node_count=countNodes(root);
	int index=0;
	return (isCompleteTree(root,index,node_count) && isMaxHeap(root));
}

int main() 
{ 
    struct node* root = NULL; 
    root = newNode(10); 
    root->left = newNode(9); 
    root->right = newNode(8); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    root->left->left->left = newNode(3); 
    root->left->left->right = newNode(2); 
    root->left->right->left = newNode(1);   
    if (isHeap(root))
    {
		std::cout<<"Yes\n";
	}
    else
    {
		std::cout<<"No\n";
	}
	return 0;
}
