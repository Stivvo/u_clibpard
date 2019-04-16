#include "list.h"

void sig_handler(int signo)
{
	char buf[1000];
	FILE *memXclip;
	FILE *memXclipW;

	int chs;
	int i;

	char command[1100] = "";
	node *pa;

    if (signo == SIGINT) {
        system("xclip -o > memXclip.txt");

        memXclip = fopen("memXclip.txt", "r");
        fgets(buf, 999, memXclip);
        fclose(memXclip);

        push(buf);

        pa = history.head;
        
        printf("\n\n --- story ---" );

        for (i = 0; i < nWord; i++)
        {
        	if (pa != NULL)
        	{
	        	printf("\n[%d] %s", i, pa->info);
	        	pa = pa->nxtp;
        	}
        }	

        do
        {
        	printf("\nSelect a word: ");
        	scanf("%d", &chs);
        }
        while (chs < 0 || chs > nWord);

        pa = history.head;

        for (i = 0; i < chs; i++)
        	pa = pa->nxtp;

       	strcpy(buf, pa->info);

        memXclipW = fopen("memXclip.txt", "w");
       	fprintf(memXclipW, "%s", buf);
       	fclose(memXclipW);

        system("cat memXclip.txt | xclip -i -selection clipboard");
        system("cat memXclip.txt | xclip");
    }
}
	
int main(void)
{
	nWord = 0;
	history.head = NULL;
	history.tail = NULL;

    if (signal(SIGINT, sig_handler) == SIG_ERR) 
    {
        printf("\ncan't catch SIGINT\n");
    }

    while(1) 
    {
        sleep(1);
    }

    return 0;
}
