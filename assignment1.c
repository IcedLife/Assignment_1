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
	int num_children;
	int status;
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
int main (int argc ,char* argv[])
{
	char *string = "this is a test";
    char *delimiters = ":";
    char **fields;
    int  numOfTokens;
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


}