#include "input.h"

static SDL_Surface* text_surface;

void initialize_input() {
    SDL_StartTextInput();
}

void close_input() {
    SDL_StopTextInput();
}


char* get_input(SDL_Event* event, char buffer[]) {
    
    // detects non-printable keys
    if (event->type == SDL_KEYDOWN) {
        if (event->key.keysym.sym == SDLK_BACKSPACE && strlen(buffer) > 0) {
            // Handle backspace: remove the last character
            buffer[strlen(buffer) - 1] = '\0';
        } else if (event->key.keysym.sym == SDLK_RETURN) {
            // Handle enter: print the text and clear the string
            //return buffer;
            printf("Input: %s\n", buffer);
            buffer[0] = '\0';
        }
    }
    // detects string input
    else if (event->type == SDL_TEXTINPUT) {
        // Append new text to inputText if it's not full
        if (strlen(buffer) + strlen(event->text.text) < MAX_INPUT_LENGTH) {
            strcat(buffer, event->text.text);
        }
    }

    return buffer;
}   