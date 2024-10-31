#include <stdio.h>
#include <string.h>
#include "window/windowManager.h"
#include "input/input.h"
#include "common.h"

int main(int argc, char* argv[]) {

    int running = initialize_window();

    initialize_input();

    char inputText[MAX_INPUT_LENGTH] = "";  // C string to hold the input
    char displayText[MAX_INPUT_LENGTH] = "";
    int quit = 0;

    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
            get_input(&event, inputText);
            //strncpy(displayText, get_input(&event, inputText), MAX_INPUT_LENGTH);
            //printf("Input: %s\n", displayText);
            //displayText[0] = '\0';
            //nputText[0] = '\0';
        }

        SDL_SetRenderDrawColor(get_renderer(), 0, 0, 0, 255);  // Clear screen
        SDL_RenderClear(get_renderer());
    }

    close_input();
    destroy_window();
    SDL_Quit();

    return 0;
}