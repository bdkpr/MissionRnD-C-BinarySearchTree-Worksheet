/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows
6
/ \
1  10

A BST is said to be balanced ,when it satisifes the following property

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but
right subtree height is 2
(Diff >1)

1
\
3
/ \
10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};


void bst_construct(struct node**, int *, int, int);
struct node * convert_array_to_bst(int *arr, int len){
	if (arr == NULL || len < 1){
		return NULL;
	}
	struct node *root = NULL;
	bst_construct(&root, arr, 0, len - 1);
	return root;
}
void bst_construct(struct node **root, int *arr, int low, int up){
	if (low>up){
		return;
	}
	struct node *temp = (node*)malloc(sizeof(node));
	int mid = (low + up) / 2;
	temp->data = *(arr + mid);
	*root = temp;
	(*root)->left = (*root)->right = NULL;
	bst_construct(&(temp->left), arr, low, mid - 1);
	bst_construct(&(temp->right), arr, mid + 1, up);
}