/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int get_height1(struct node *root){

	if (root == 0)
		return 0;

	if (root->left == 0 && root->right == 0)
		return 1;

	int l = get_height1(root->left);
	int r = get_height1(root->right);

	return l > r ? l + 1 : r + 1;


	}


void getToArray(struct node* root, int *arr, int *index, int level){

	if (root == NULL)
		return;

	if (level == 0)
		{
		arr[*index] = root->data;
		*index = *index + 1;
		}

	if (level){

		getToArray(root->right, arr, index, level - 1);
		getToArray(root->left, arr, index, level - 1);
		}

	}

void BSTRighttoLeft_helper(struct node* root, int *arr, int *index){

	int height = get_height1(root);

	int i;
	for (i = 0; i < height; i++)
		getToArray(root, arr, index, i);

	}


int pow(int num, int power){

	int i = 0,ans=1;

	for (i = 0; i < power; i++)
		ans = ans * num;

	return ans;
	}

int* BSTRighttoLeftRows(struct node* root)
{

	if (root==NULL)
		return NULL;

	int height = get_height1(root);

	int ind = 0;
	int *resArray = (int*)malloc(pow(2,height)*sizeof(int));

	resArray[0] = root->data;

	BSTRighttoLeft_helper(root, resArray, &ind);

	return resArray;
}
