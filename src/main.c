#include <stdio.h>
#include <stdlib.h>
#include <../include/SDL2/SDL.h>

int main(int argc, char* argv[]) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        puts("Failed to init SDL.");
        SDL_GetError();
        return 1;
    }

    

    SDL_Quit();
    return 0;
}