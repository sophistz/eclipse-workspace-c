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
	struct bNode* next;
};

void addNode(struct bNode** root, int data){
	if((*root)==NULL)
	{
		(*root)=(struct bNode*)malloc(sizeof(struct bNode));
		(*root)->data=data;
		(*root)->next=NULL;
	}
	else
	{
		addNode(&((*root)->next),data);
	}
}

int main(void) {
	struct bNode* root=NULL;
	printf("start\n");
	addNode(&root,1);
	addNode(&root,2);
	printf("%d\n",root->data);
	printf("%d\n",root->next->data);
	return 0;
}
