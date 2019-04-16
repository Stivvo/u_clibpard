#include "list.h"

void push(char *s)
{
	if (strlen(s) > 0)
	{
		node* n = (node*) malloc(sizeof (node));
		n->info = malloc(sizeof(char) * (strlen(s) + 1));
		n->nxtp = NULL;
		strcpy(n->info, s);

		if (history.head == NULL && history.tail == NULL)
		{
			history.head = n;
			history.tail = n;
		}
		else
		{
			history.tail->nxtp = n;
			history.tail = n;
		}
		nWord++;
	}
}
