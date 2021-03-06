#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "makeargv.h"

#define INELIGIBLE 0
#define READY 1
#define RUNNING 2
#define	FINISHED 3

typedef struct node {
	int id;
	char prog[1024];
	char input[1024];
	char output[1024];
	int children[10];
	int parent[15];
	int num_children;
	int num_parent=0;
	int status;
	int level = 0;
	pid_t pid;
} Node_t;

Node_t *readgraph(char* graph,int myId)
{
	Node_t *newNode = malloc(sizeof(Node_t));
	if(newNode == NULL)
		return NULL;

	char **fields;
	int numToken;
	char *token;

	numToken = makeargv(graph,":",&fields);
	if(numToken != 4)
	{
		printf("Not enough Arguments in graph");
		return NULL;
	}
	
	token = strtok(fields[1]," ");
	if(token == NULL)
		newNode->num_children = 0;
	else
	{
		int i=0;
		int token_NUM=0;
		while(token != NULL)
		{
			token_NUM = atoi(token);
			newNode->children[i]=token_NUM;
			token = strtok(NULL," ");
			i++;
		}
		newNode->num_children = i;
	}
	newNode->id = myId;
	newNode->prog = fields[0];
	newNode->input = fields[2];
	newNode->output = fields[3];
	newNode->status = INELIGIBLE;
}

void run(Node_t** queue,int numNode,int id)
{
	if(queue[id]->level = 0;
}
int main (int argc ,char* argv[])
{
	int numOfNode;
    Node_t *queue[50];

    numOfTokens = makeargv(string, delimiters, &fields);
    FILE *ifp, *ofp;
    char *outputFilename = NULL;

    ifp = fopen(argv[1],"r");

    if(ifp == NULL) {
    	fprintf(stderr,"Can't open input file %s!\n",argv[1]);
    	exit(1);
    }

    ofp = fopen(outputFilename, "w");

    if (ofp == NULL) {
    	fprintf(stderr, " Can't open output file %s!\n",outputFilename);
    	exit(1);
    } 

    char graph[1023];
    int i=0;
    while(fgets(graph,1023,ifp) != NULL) {
    	Node_t *node = readgraph(graph,i);
    	queue[i] = node;
    }
    numOfNode = i;
	//Following code determine the level of each node.
	Node_t *nodeptr;
	Node_t *childNode;
	int maxLevel = 0;;
	for(int k=0;k<numOfNode;k++) {
		nodeptr = queue[k];
		for(int m=0;m<nodeptr->num_children;m++) {
			childNode = queue[nodeptr->children[m]];
			childNode->parent[childNode->num_parent] = nodeptr-> id;
			childNode->num_parent++;
			if(nodeptr->level+1 > childNode->level)
				childNode->level++;
				if(childNode->level > maxLevel)
					maxLevel = childNode->level;
		}
	}
}
