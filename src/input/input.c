#include "input.h"

void initialize_input() {
    SDL_StartTextInput();  // Enable text input
}

void close_input() {
    SDL_StopTextInput();  // Disable text input
}