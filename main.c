/* 
*   Author : Tejas B Gowda 
*   Date : 17/11/25
*   Description : The program that help user to search the words in text uploaded and to list them in alphabetical order
*   Prerequisits : Linked lists, Hash Table, Structures, Functions, Enums and 2D array concepts
*   Sample input : ./a.out f1.txt 
*   Sample output :  =====================
*                    |1. Create          |
*                    |2. Display         |
*                    |3. Search          |
*                    |4. Save            |
*                    |5. Update          |
*                    |6. Exit            |
*                    =====================
*                    -> Enter the option : 5
*                    -> Enter the Back-up file name: backup.txt
*                    SUCCESS: Updation Successful..!
*                    -> Enter the option : 2
*                    -------------------------------------------------------------------
*                     Index      Words           File_count      File_Name  Word_count

*                       0         and                  1         f2.txt          1
*
*                       2         core                 1         f2.txt          1

*                       2         circuits,            1         f2.txt          1

*                       4         electronics          1         f2.txt          1
*
*                       4         embedded             1         f2.txt          1
*                   -------------------------------------------------------------------            
*/
#include "main.h"

int is_db_created;
int is_db_updated;
int create_after_update_done;

int main(int argc, char *argv[])
{
    // if argument cout is invalid
    if (argc < 2)
    {
        displayhelp(argv); // display help function
        return FAILURE;
    }
    Slist *filename = NULL;
    Mnode *table[27] = {NULL};
    Bfile *backup_files = NULL;
    // validate and create a filename list
    if (Validate_createfile(argc, argv, &filename) == FAILURE)
    {
        return FAILURE;
    }
    while (1)
    {
        int ch;
        printf("=====================");
        printf("\n|1. Create\t    |\n|2. Display\t    |\n|3. Search\t    |\n|4. Save\t    |\n|5. Update\t    |\n|6. Exit\t    |\n");
        printf("=====================");
        printf("\n-> Enter the option : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (is_db_created && !is_db_updated)
            {
                printf("ERROR : DB readily exists...\n");
            }
            else if (is_db_updated && create_after_update_done)
            {
                printf("ERROR: DB creation post-update or post-create isn't allowed...\n");
            }
            else
            {
                if (create_Database(filename, table, backup_files) == FAILURE)
                    printf("ERROR: DB creation failed...\n");
                else
                {
                    printf("SUCCESS: Database creation successful..!\n");
                    if (is_db_updated)
                        create_after_update_done = 1;
                    else
                        is_db_created = 1;
                }
            }
            break;

        case 2:
            if (display(table) == FAILURE)
                printf("FAILED: Display failed..!\n");
            break;
        case 3:
            if (search(table) == FAILURE)
                printf("FAILED: Word isn't available..!\n");
            break;
        case 4:
            if (save(table) == FAILURE)
                printf("FAILED: Failed to save DB..!\n");
            break;
        case 5:
            if (is_db_created)
            {
                printf("ERROR : DB Updation post Creation isn't supported..!\n");
            }
            else if (is_db_updated)
            {
                printf("ERROR: DB Updation post Updation isn't supported...!\n");
            }
            else
            {
                if (Update(table, &backup_files) == FAILURE)
                    printf("FAILED: Hash Table updaion failed..!\n");
                else
                {
                    printf("SUCCESS: Updation Successful..!\n");
                    is_db_updated = 1;
                }
            }
            break;
        case 6: return 0;

        default:
            printf("ERROR: Invalid input..!\n");
            break;
        }
    }
}
