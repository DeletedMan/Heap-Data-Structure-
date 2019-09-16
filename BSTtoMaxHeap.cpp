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

void convertToMaxHeapUtil(struct node* root,vector<int>&vect)
{
	if(!root)
	{
		return;
	}
	convertToMaxHeapUtil(root->left,vect);
	vect.push_back(root->data);
	convertToMaxHeapUtil(root->right,vect);
}

/*
void convertToMaxHeapUtil(struct node* root)//First Approach to convert into Max Heap...
{
	if(!root)
	{
		return;
	}
	convertToMaxHeapUtil(root->right);
	std::cout<<root->data<<" ";
	convertToMaxHeapUtil(root->left);
}
*/

int main() 
{ 
    struct node* root = newNode(4); 
    root->left = newNode(2); 
    root->right = newNode(6); 
    root->left->left = newNode(1); 
    root->left->right = newNode(3); 
    root->right->left = newNode(5); 
    root->right->right = newNode(7); 
    vector<int>vect;
    convertToMaxHeapUtil(root,vect);
    for(int i=vect.size()-1;i>=0;i--)
    {
		std::cout<<vect[i]<<" ";
	} 
    std::cout<<endl;
    return 0; 
} 
