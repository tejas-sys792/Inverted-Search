#include "main.h"

int Update(Mnode *table[], Bfile **backup_files)
{
    char backup_file[100];
    printf("-> Enter the Back-up file name: ");
    scanf(" %s", backup_file);

    FILE *fptr = fopen(backup_file, "r");
    if (!fptr)
    {
        perror("ERROR: Failed to open file..!");
        return FAILURE;
    }
    char first_h = getc(fptr);
    fseek(fptr, -1, SEEK_END);
    char last_h = getc(fptr);
    rewind(fptr);
    if (!(first_h == '#' && last_h == '#'))
    {
        printf("ERROR: File entered isn't a Back-up file..\n");
        return FAILURE;
    }
    int index, filecount;
    char word[100], filename[100];
    int word_count;
    char hash;
    fscanf(fptr, "%c", &hash);
    while (fscanf(fptr, "%d", &index) == 1)
    {
        if (fscanf(fptr, "%s", word) != 1)
            break;
        if (fscanf(fptr, "%d", &filecount) != 1)
            break;

        // Create Main Node
        Mnode *Mnew = NULL;
        if (create_MainNode(&Mnew, word) == FAILURE)
            break;
        Mnew->file_count = filecount;

        // Read and create SubNodes
        for (int i = 0; i < filecount; i++)
        {
            if (fscanf(fptr, "%s", filename) != 1)
                break;
            if (fscanf(fptr, "%d", &word_count) != 1)
                break;

            Snode *Snew = NULL;
            if (create_SubNode(&Snew, filename) == FAILURE)
                break;
            Snew->word_count = word_count;

            // Append subnode
            if (Mnew->sublink == NULL)
            {
                Mnew->sublink = Snew;
            }
            else
            {
                Snode *subtemp = Mnew->sublink;
                while (subtemp->sublink)
                    subtemp = subtemp->sublink;
                subtemp->sublink = Snew;
            }
            if (!is_file_in_list(*backup_files, filename))
                add_file_to_list(backup_files, filename);
        }

        // Add Mnode to table
        if (table[index] == NULL)
        {
            table[index] = Mnew;
        }
        else
        {
            Mnode *temp = table[index];
            while (temp->mlink)
                temp = temp->mlink;
            temp->mlink = Mnew;
        }
    }

    fclose(fptr);
    return SUCCESS;
}
