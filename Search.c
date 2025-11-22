#include "main.h"
int search(Mnode *table[])
{
    char word[100];
    printf("-> Enter the word to be searched: ");
    scanf(" %s", word);
    convertlowercase(word);
    int index = word[0] % 97;
    int c=0;
    if (table[index] == NULL)
        return FAILURE;

    Mnode *temp = table[index];

    while (temp && !(strcmp(temp->word, word) == 0))
        temp = temp->mlink;

    if (!temp)
        return FAILURE;
    if (c == 0)
    {
        printf("-------------------------------------------------------------------\n");
        printf("%-10s %-15s %-15s %-10s %-10s\n","Index", "Words", "File_count", "File_Name" , "Word_count");
        c++;
    }
    printf("\n %-9d %-20s %-10d", index, temp->word, temp->file_count);

    Snode *sub = temp->sublink;
    while (sub)
    {
        if (sub == temp->sublink)
        {
            printf("%-15s %d\n", sub->filename, sub->word_count);
        }
        else
        {
            printf("%51s %7d\n", sub->filename, sub->word_count);
        }
        sub = sub->sublink;
    }
    if(c == 1)
    {
        printf("\n-------------------------------------------------------------------\n");
        c++;
    }

    return SUCCESS;
}