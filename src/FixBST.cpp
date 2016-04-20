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

void no_nodes(struct node *, int *);
void tree_data_values(struct node *, int *, int *);
void changed_values(int *, int, int *, int *);
void fix(struct node *, int, int);
void fix_bst(struct node *root){
	if (root == NULL){
		return;
	}
	int len, *arr, changeVal_1, changeVal_2, k;
	k = changeVal_1 = changeVal_2 = len = 0;
	no_nodes(root, &len);
	arr = (int *)malloc(len*sizeof(int));
	tree_data_values(root, arr, &k);
	changed_values(arr, len, &changeVal_1, &changeVal_2);
	if (changeVal_1 != 0){
		fix(root, changeVal_1, changeVal_2);
	}
}
void no_nodes(struct node *root, int *count){
	if (root == NULL){
		return;
	}
	no_nodes(root->left, count);
	(*count)++;
	no_nodes(root->right, count);
}
void tree_data_values(struct node *root, int *arr, int *ind){
	if (root == NULL){
		return;
	}
	tree_data_values(root->left, arr, ind);
	arr[*ind] = root->data;
	(*ind)++;
	tree_data_values(root->right, arr, ind);
}
void changed_values(int *arr, int len, int *first, int *second){
	if (arr == NULL || len<1){
		return;
	}
	int ind;
	for (ind = 0; ind < len - 1; ind++){
		if (arr[ind]>arr[ind + 1]){
			break;
		}
	}
	if (ind != len - 1){
		*first = ind;
		ind += 2;
		for (; ind < len; ind++){
			if (arr[ind] < arr[ind - 1]){
				break;
			}
		}
		if (ind < len){
			*second = arr[ind];
		}
		else{
			*second = arr[(*first) + 1];
		}
		*first = arr[*first];
	}
}
void fix(struct node *root, int value_1, int value_2){
	if (root == NULL){
		return;
	}
	if (root->data == value_1){
		root->data = value_2;
	}
	else if (root->data == value_2){
		root->data = value_1;
	}
	fix(root->left, value_1, value_2);
	fix(root->right, value_1, value_2);
}