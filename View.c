#include "main.h"

int display(Mnode *table[])
{
    int is_empty = 1;
    int c=0;
    for (int i = 0; i < 27; i++)
    {
        
        Mnode *temp = table[i];
        while (temp)
        {
            is_empty = 0;
            if (c == 0)
            {
                printf("-------------------------------------------------------------------\n");
                printf("%-10s %-15s %-15s %-10s %-10s\n","Index", "Words", "File_count", "File_Name" , "Word_count");
                c++;
            }
            printf("\n %-9d %-20s %-10d",i, temp->word,temp->file_count);

            Snode *sub = temp->sublink;
            while (sub)
            {
                if(sub==temp->sublink)
                {
                    printf("%-15s %d\n", sub->filename,sub->word_count);
                }
                else
                {
                    printf("%51s %7d\n", sub->filename,sub->word_count);
                }
              
                sub = sub->sublink;
            }

            temp = temp->mlink;
        }
        

    }
    if(c == 1)
    {
        printf("\n-------------------------------------------------------------------\n");
        c++;
    }

    if (is_empty)
    {
        printf("ERROR: DB is empty...!\n");
        return FAILURE;
    }

    return SUCCESS;
}
