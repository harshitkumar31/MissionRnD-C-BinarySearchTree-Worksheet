/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};


//Gets parent of a node
struct node* get_parent(struct node* root, int data){

	if (root == NULL)
		return NULL;

	if (root->left != NULL){
		if (root->left->data == data)
			return root;
		}
	if (root->right != NULL){
		if (root->right->data == data)
			return root;
		}

	struct node *l = NULL, *r = NULL;

	if (root->left != NULL){
		l = get_parent(root->left, data);
		}
	if (root->right != NULL){
		r = get_parent(root->right, data);
		}

	if (l != NULL)
		return l;
	if (r != NULL)
		return r;

	if (l == NULL && r == NULL)
		return NULL;
	}



 
int minimum(int a, int b){

	if (a != -1 && b != -1)
		return a > b ? b : a;

	if (a == -1){
		return b;
		}
	if (b == -1){
		return a;
		}

	}

int get_closest_dist_below(struct node *root){

	if (root == NULL)
		return -1;

	if (root->left == NULL && root->right == NULL)
		return 0;

	int l, r;

	l = get_closest_dist_below(root->left);
	r = get_closest_dist_below(root->right);

	int min = minimum(l, r);

	return 1 + min;

	}

int get_closest_leaf_distance_helper(struct node* root, struct node* temp){

	int close_dist_below = get_closest_dist_below(temp);

	if (close_dist_below == 0 || close_dist_below == 1)
		return close_dist_below;

	struct node* parent = get_parent(root, temp->data);
	
	if (parent != NULL){
		int pDist = get_closest_leaf_distance_helper(root, parent);

		int min = minimum(pDist, close_dist_below);

		if (min == pDist)
			return 1 + pDist;
		}
	return close_dist_below;

	}

int get_closest_leaf_distance(struct node *root, struct node *temp)
	{
	if (root == NULL || temp == NULL)
		return -1;

	return get_closest_leaf_distance_helper(root, temp);
	}
