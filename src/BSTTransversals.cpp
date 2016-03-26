/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void inorder_helper(struct node *root, int *arr, int *ind){

	if (root == NULL)
		return;


	inorder_helper(root->left, arr,ind);
	arr[*ind] = root->data;
	*ind = *ind + 1;
	inorder_helper(root->right, arr,ind);


	}

void inorder(struct node *root, int *arr){


	if (arr == NULL)
		return;
	int ind=0;

	inorder_helper(root, arr, &ind);
	
}

void preorder_helper(struct node *root, int *arr,int *ind){
	
	if (root == NULL)
		return;

	arr[*ind] = root->data;
	*ind = *ind + 1;
	preorder_helper(root->left, arr,ind);
	preorder_helper(root->right, arr,ind);


	}

void preorder(struct node *root, int *arr){
	

	if (arr == NULL)
		return;
	int ind = 0;

	preorder_helper(root, arr, &ind);

	}

void postorder_helper(struct node *root, int *arr,int *ind){
	

	if (root == NULL)
		return;

	postorder_helper(root->left, arr,ind);
	postorder_helper(root->right, arr,ind);
	arr[*ind] = root->data;
	*ind = *ind + 1;


	}


void postorder(struct node *root, int *arr){

	if (arr == NULL)
		return;

	int ind = 0;
	postorder_helper(root, arr, &ind);
}

