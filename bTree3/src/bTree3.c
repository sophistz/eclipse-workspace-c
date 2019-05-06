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

void addNode(struct bNode* root, int data){
	if(root->left==NULL && root->right==NULL)
	{
		root->data=data;
		root->left=(struct bNode*)malloc(sizeof(struct bNode));
		root->left->data=0;
		root->left->left=NULL;
		root->left->right=NULL;
		root->right=(struct bNode*)malloc(sizeof(struct bNode));
		root->right->data=0;
		root->right->left=NULL;
		root->right->right=NULL;
	}
	else
	{
		if(data<=root->data)
			addNode(root->left,data);
		else
			addNode(root->right,data);
	}
}

void traverse(struct bNode* root)
{

}

int main(void) {
	struct bNode* root;
	root=(struct bNode*)malloc(sizeof(struct bNode));
	printf("start\n");
	root->data=0;
	root->left=NULL;
	root->right=NULL;
	addNode(root,2);
	addNode(root,1);
	addNode(root,3);
	printf("%d\n",root->data);
	printf("%d\n",root->left->data);
	printf("%d\n",root->right->data);
	return 0;
}
