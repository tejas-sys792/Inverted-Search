#include "main.h"
#include <stdio.h>
#include <string.h>
extern int negative1;
extern int negative2;

//Function to display help
void displayhelp(char *argv[])
{
    printf("ERROR: Incorrect format of command line arguments.\n");
    printf("(Hint: %s  <file_name(s)>)\n", argv[0]);
}

//Function to validate and create filname linked list
int Validate_createfile(int argc, char *argv[], Slist **head)
{
    int i = 1; 
    while (i < argc)
    {
        //if it is not ".txt" file then skip the iteration.
        if (!(strstr(argv[i], ".txt")))
        {  
            printf("ERROR: %s isn't matching text file..!\n",argv[i]);
            i++;
            continue;
        }
        //if file not present
        FILE *fptr = fopen(argv[i], "r");
        if (fptr == NULL)
        {
            printf("ERROR: %s not found..!\n",argv[i]);
            i++;
            continue;
        }
        fseek(fptr, 0, SEEK_END);
        long int res = ftell(fptr);
        fclose(fptr);
        //if file is present but it is empty.
        if (res == 0)
            i++;
        //To skip the duplicate file name.
        else if(Duplicate(*head,argv[i])==SUCCESS)
            i++;
        //create a list for valid filenames
        else if(Create_filename_List(head, argv[i])==FAILURE)
           return FAILURE;
        i++;
        
    }
    return SUCCESS;
}

//Function to check if filename is already present in list.
int Duplicate(Slist *head, char *name)
{
    //traverse
    while(head)
    {
        //if found then return success
        if(strcmp(head->name,name)==0)
            return SUCCESS;
        head=head->link;
    }
    return FAILURE;
}

//Function to create filenames list

int Create_filename_List(Slist **head, char *name)
{
    //inset_last approach 
    Slist *new = malloc(sizeof(Slist));
    if (new == NULL)
    {
        return FAILURE;
    }

    strcpy(new->name, name);
    new->link = NULL;

    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        Slist *temp = *head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
    return SUCCESS;
}
//Function to print List
void printList(Slist *head)
{
    while (head)
    {
        printf("%s -> ", head->name);
        head = head->link;
    }
    printf("NULL\n"); 
}

int is_file_in_list(Bfile *head, const char *filename)
{
    while (head)
    {
        if (strcmp(head->filename, filename) == 0)
            return 1;
        head = head->link;
    }
    return 0;
}

void add_file_to_list(Bfile **head, const char *filename)
{
    Bfile *new = malloc(sizeof(Bfile));
    strcpy(new->filename, filename);
    new->link = *head;
    *head = new;
}
