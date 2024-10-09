#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // for glew to work better, idk if necessary -Ethan
#include <../include/SDL2/SDL.h>
#include <../include/GL/glew.h>
#include "window/windowManager.h"

int main(int argc, char* argv[]) {
    int running = initialize_window();

    SDL_Event event;
    while(running) {
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = 0;
            }
        }
        glClearColor(1.0f, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    

    SDL_Quit();
    return 0;
}