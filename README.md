Inverted-Search-Engine/
│
├── src/               # All source files
│   ├── main.c
│   ├── Save.c
│   ├── Search.c
│   ├── Update.c
│   ├── Validate.c
│   ├── View.c
│
├── include/
│   └── main.h         # Header file
│
├── data/              # Sample text / backup files
│
├── build/             # Compiled output
🚀 Features
✔ Create Database

Reads all input .txt files and builds:

Hash table of 27 indexes (a–z + non-alphabets)

Linked lists of words

Sub-lists of filenames & word counts

✔ Display Database

Shows indexed words with:

Word

File count

All filenames

Word count in each file

✔ Search Word

Searches for a word and displays all locations where it appears.

✔ Save Database (Backup)

Saves the entire hash structure into a .txt backup file in a structured format.

✔ Update Database from Backup

Reads a backup file and reconstructs the entire hash table.
