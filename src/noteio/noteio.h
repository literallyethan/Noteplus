#ifndef NOTEIO_H
#define NOTEIO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Module authored by Ethan Purser
// Purpose:
// 	handle writing to, reading from,
// 	saving, and deleting files
// 	to and from the local system of the 
// 	user. 

// Assumes the use of C strings

// Assumes a destination folder 
// already provided in install for storing note files

// Creates a new note, and opens for editing
// Default will be in the <notes> folder 
int new_note(const char* path);

// Opens an existing note from editing
int open_note(const char* path);

// Saves and closes notes to specified path
int save_note(const char* path);

// Creates an array with multiple notes to keep them organized
int new_note_set(const char* path);

//-------------------------//
//    MAY NOT BE NEEDED    //
//-------------------------//

// Saves note set??
//int save_note_set(const char* path);

//May be out of scope for simple file IO
//int write_note(const char* path, char input[]);



#endif
