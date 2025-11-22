
#ifndef Inverted
#define Inverted

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE 1

typedef struct node
{
    char name[50];
    struct node *link;
}Slist;

typedef struct Snode
{
    int word_count;
    char filename[20];
    struct Snode *sublink;
}Snode;

typedef struct Mnode
{
    int file_count;
    char word[20];
    struct Mnode *mlink;
    struct Snode *sublink;
}Mnode;

typedef struct Bfile {
    char filename[100];
    struct Bfile *link;
} Bfile;


void displayhelp(char *argv[]);

int Validate_createfile(int argc, char *argv[],Slist **filename);

int Create_filename_List(Slist **head, char *name);

int Duplicate(Slist *head, char *name);

void printList(Slist *head);

int create_Database(Slist *filename, Mnode *table[], Bfile *backup_files);

int create_MainNode(Mnode **Mnew, char *word);

int create_SubNode(Snode **Snew,char *filename);

void convertlowercase(char *word);

int display(Mnode *table[]);

int isDuplicate(Mnode *table[], int index, char *word);

int search(Mnode *table[]);

int save(Mnode *table[]);

int Update(Mnode *table[], Bfile **backup_files);

void add_file_to_list(Bfile **head, const char *filename);

int is_file_in_list(Bfile *head, const char *filename);

#endif