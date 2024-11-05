#ifndef INPUT_H
#define INPUT_H
#include "../common.h"
#include "../window/windowManager.h"

void initialize_input();

void close_input();

char* get_input(SDL_Event* event, char buffer[]);

int render_input(const char* text, int x, int y, SDL_Color* color);

#endif