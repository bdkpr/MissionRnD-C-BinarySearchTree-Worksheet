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



void nodes_count(struct node*, int *);
void Queue_push(struct node**, struct node *, int *);
struct node *Queue_pop(struct node **, int *);
int* BSTRighttoLeftRows(struct node* root){
	if (root == NULL){
		return NULL;
	}
	int *res, f, r, no_nodes, ind = 0;
	struct node **q, *temp = root;
	f = r = no_nodes = 0;
	nodes_count(root, &no_nodes);
	res = (int *)malloc(no_nodes*sizeof(int));
	q = (node **)malloc(no_nodes*sizeof(node*));
	Queue_push(q, root, &r);
	while (no_nodes>0){
		temp = Queue_pop(q, &f);
		res[ind++] = temp->data;
		if (temp->right != NULL){
			Queue_push(q, temp->right, &r);
		}
		if (temp->left != NULL){
			Queue_push(q, temp->left, &r);
		}
		no_nodes--;
	}
	return res;
}
void Queue_push(struct node **q, struct node *root, int *r){
	q[*r] = root;
	(*r)++;
}
struct node *Queue_pop(struct node**q, int *f){
	struct node *temp = q[*f];
	//free(q[*f]);
	(*f)++;
	return temp;
}
void nodes_count(struct node *root, int *count){
	if (root == NULL){
		return;
	}
	(*count)++;
	nodes_count(root->left, count);
	nodes_count(root->right, count);
}