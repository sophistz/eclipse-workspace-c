/*
 ============================================================================
 Name        : bTree1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct bNode{
	int data;
	struct bNode* left;
	struct bNode* right;
};

struct bNode* addNode(struct bNode* root, int data){
	if(root==NULL)
	{
		struct bNode* temp=NULL;
		temp=(struct bNode*)malloc(sizeof(struct bNode));
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	else
	{
		if(data<=root->data)
			root->left=addNode(root->left,data);
		else
			root->right=addNode(root->right,data);
		return root;
	}
}

void traverse(struct bNode* root)
{
	if(root->left!=NULL)
	{
		traverse(root->left);
	}
	printf("%d\n",root->data);
	if(root->right!=NULL)
	{
		traverse(root->right);
	}
}

int main(void) {
	struct bNode* root=NULL;
	printf("start\n");
	root=addNode(root,2);
	root=addNode(root,1);
	root=addNode(root,3);
	/*
	printf("%d\n",root->data);
	printf("%d\n",root->left->data);
	printf("%d\n",root->right->data);
	*/
	traverse(root);
	return 0;
}
