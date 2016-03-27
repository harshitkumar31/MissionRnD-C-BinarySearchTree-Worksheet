/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};



void swapNodes(struct node* node1, struct node* node2){

	int temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;

	}

void fix_bst(struct node *root){

	if (root==NULL)
		return;

	struct node *curr, *prev, *node1 , *node2 ;
	struct node *first, *second ;

	node1 = node2 = first = second = NULL;
	curr = root;
	while (curr)
		{
		if (curr->left == NULL)
			{
			if (node1 == NULL)
				node1 = curr;
			else if (node2 == NULL) 
				node2 = curr;
			else
				{
				node1 = node2;
				node2 = curr;
				}
			curr = curr->right;
			}
		else
			{
			prev = curr->left;
			while (prev->right && prev->right != curr)
				prev = prev->right;
			if (prev->right == NULL)
				{
				prev->right = curr;
				curr = curr->left;
				continue;
				}
			else
				{
				prev->right = NULL;
				if (node2 == NULL) 
					node2 = curr;
				else
					{
					node1 = node2;
					node2 = curr;
					}

				curr = curr->right;
				}
			}
		if (node1 && node2 && node1->data > node2->data)
			{
			if (first == NULL)   
				first = node1;

			second = node2;
			}
		}

	swapNodes(first, second);


}
