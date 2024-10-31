#ifndef INPUT_H
#define INPUT_H
#include "../common.h"

void initialize_input();

void close_input();

char* get_input(SDL_Event* event, char buffer[]);


#endif