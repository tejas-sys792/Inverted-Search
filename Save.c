#include "main.h"
int save(Mnode *table[])
{
    // Check if the hash table is empty
    int is_empty = 1;
    for (int i = 0; i < 27; i++)
    {
        if (table[i] != NULL)
        {
            is_empty = 0;
            break;
        }
    }
    char str[100];
    while(1)
    {
        printf("Enter the backup file: ");
        scanf("%s",str);
        if(strstr(str,".txt")==NULL)
        {
            printf("ERROR: Upload text file only\n");
        }
        else
        {
            printf("Back-up Successfull..!\n");
            break;
        }
    }
    if (is_empty)
    {
        printf("ERROR: Hash table is empty..!\n");
        return FAILURE;
    }

    FILE *fp = fopen(str, "w");
    if (fp == NULL)
    {
        printf("ERROR: File open failed..!\n");
        return FAILURE;
    }
    fprintf(fp, "#");
    // Traverse the hash table
    for (int i = 0; i < 27; i++)
    {
        Mnode *mtemp = table[i];
        while (mtemp)
        {
            // index, word and file count
            fprintf(fp, "\n%d %s %d", i, mtemp->word, mtemp->file_count);

            Snode *stemp = mtemp->sublink;

            // files and count
            while (stemp)
            {
                fprintf(fp, " %s %d", stemp->filename, stemp->word_count);
                stemp = stemp->sublink;
            }
            mtemp = mtemp->mlink;
            // fprintf(fp, "\n");
        }
    }
    fprintf(fp, " #");

    fclose(fp);
    return SUCCESS;
}
