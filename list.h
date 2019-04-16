#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

typedef struct node
{
	char* info;
	struct node *nxtp;
} node;

typedef struct list
{
	node *head;
	node *tail;
} list;

list history;
int nWord;

void push(char *s);