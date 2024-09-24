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

// Called when making a new note.
// By default, puts files in the <files> folder. 
int create_file(const char* path);

#endif
