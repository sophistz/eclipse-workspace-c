
#define MAXBUF 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bNode {
	char data[MAXBUF]; // These are the instance variables of the
	struct bNode* left; // bNode class in the Java implementation.
	struct bNode* right;
};

struct bNode* root; // Pointer to B-Tree
struct bNode** indexArray; // Pointer to indexArray
int recCount; // Node count for use in recursion


void addNode (char* data){
	struct bNode** current = &root;
	while(*current != NULL)
	{

		int g_e_s = strcmp(data, (*current)->data);
		if(g_e_s > 0 )
		{
			// this should be added to the right side of the tree
			current = &((*current)->right);

		}else if(g_e_s < 0)
		{
			// this should be added to the left side of the tree
			current = &((*current)->left);
		}else
		{
			// we have the string in the tree so let us quit the method
			return;
		}
	}
	//now let's do the addition
	struct bNode* newNode = (struct bNode*)malloc(sizeof(struct bNode));
	newNode->left = NULL;
	newNode->right = NULL;
	strcpy(newNode->data, data);
	*current = newNode;
}
void traverse(struct bNode* node)
{
	if(node == NULL)
		return;
	traverse(node->left);
	indexArray[recCount] = node;
	recCount++;
	traverse(node->right);
}
void makeIndex (int numRecords){

	indexArray = (struct bNode**)malloc(sizeof(struct bNode*) * numRecords);
	recCount = 0;
	traverse(root);
}

int main(int argc, char* argv[]) {

	// Internal declarations
	FILE* FileD;			     // File descriptor (an object)!
	char* line;				     // Pointer to buffer used by getline function
	int bufsize = MAXBUF;	     // Size of buffer to allocate for file reading
	int linelen;
	int i;		         // Length of string returned (getline)
	int nOfRecords = 0;
	// Argument check
	if (argc != 2) {
		printf("Usage: fileReader [text file name]\n");
		return -1;
	}

	// Attempt to open the user-specified file.  If no file with
	// the supplied name is found, exit the program with an error
	// message.

	if ((FileD=fopen(argv[1],"r"))==NULL) {
		printf("Can't read from file %s\n",argv[1]);
		return -2;
	}

	// Allocate a buffer for the getline function to return data to.

	line=(char *)malloc(bufsize+1);
	if (line==NULL) {
		printf("Unable to allocate a buffer for reading.\n");
		return -3;
	}

	/*
	printf("\nContents of file %s:\n\n",argv[1]);

	// Read file line by line and dislay on output console
	 *
	 */
	while ((linelen=getline(&line,(size_t *)&bufsize,FileD))>0) {
		addNode(line);
		nOfRecords++;
		//printf("%s\n",line);
	}


	printf("nOfR = %d\n",nOfRecords);
	makeIndex(nOfRecords);

	printf("File Names.txt in sort order:\n");
	for (i = 0; i < nOfRecords; ++i) {
		printf("%d) %s\n", i + 1, indexArray[i]->data);
	}

	printf("\n\nFile Names.txt in reversed sort order:\n");
	for (i = nOfRecords-1; i >=0; --i) {
		printf("%d) %s\n", nOfRecords-i, indexArray[i]->data);
	}

	fclose(FileD);
}
