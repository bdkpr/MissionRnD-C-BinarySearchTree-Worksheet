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


void in_ord(struct node *root, int *arr, int *ind){
	if (root == NULL){
		return;
	}
	in_ord(root->left, arr, ind);
	arr[*ind] = root->data;
	(*ind)++;
	in_ord(root->right, arr, ind);
}
void pre_ord(struct node *root, int *arr, int *ind){
	if (root == NULL){
		return;
	}
	arr[*ind] = root->data;
	(*ind)++;
	pre_ord(root->left, arr, ind);
	pre_ord(root->right, arr, ind);
}
void post_ord(struct node *root, int *arr, int *ind){
	if (root == NULL){
		return;
	}
	post_ord(root->left, arr, ind);
	post_ord(root->right, arr, ind);
	arr[*ind] = root->data;
	(*ind)++;
}

void inorder(struct node *root, int *arr){
	if (root == NULL||arr==NULL){
		return;
	}
	int k = 0;
	in_ord(root, arr, &k);
}

void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		return;
	}
	int k = 0;
	pre_ord(root, arr, &k);
}

void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		return;
	}
	int k = 0;
	post_ord(root, arr, &k);
}