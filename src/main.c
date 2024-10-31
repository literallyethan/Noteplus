#include <stdio.h>
#include <string.h>
#include "window/windowManager.h"
#include "input/input.h"
#include "common.h"

#define MAX_INPUT_LENGTH 256

int main(int argc, char* argv[]) {
    /*SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("SDL Input Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
*/
    int running = initialize_window();

    initialize_input();

    char inputText[MAX_INPUT_LENGTH] = "";  // C string to hold the input
    int quit = 0;


    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_BACKSPACE && strlen(inputText) > 0) {
                    // Handle backspace: remove the last character
                    inputText[strlen(inputText) - 1] = '\0';
                } else if (event.key.keysym.sym == SDLK_RETURN) {
                    // Handle enter: print the text and clear the string
                    printf("Input: %s\n", inputText);
                    inputText[0] = '\0';
                }
            }
            else if (event.type == SDL_TEXTINPUT) {
                // Append new text to inputText if it's not full
                if (strlen(inputText) + strlen(event.text.text) < MAX_INPUT_LENGTH) {
                    strcat(inputText, event.text.text);
                }
            }
        }

        SDL_SetRenderDrawColor(get_renderer(), 0, 0, 0, 255);  // Clear screen
        SDL_RenderClear(get_renderer());

        // Render your scene (optional)

        SDL_RenderPresent(get_renderer());
    }

    close_input();
    SDL_Quit();

    return 0;
}