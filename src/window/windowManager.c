#include "windowManager.h"

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;

int initialize_window(void) {
    int width = 640;
    int height = 480;
    SDL_GLContext mainContext = NULL;
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        puts("Failed to init SDL.");
        SDL_GetError();
        return 0;
    }

    /*
    int info = SDL_GetVideoInfo();
    if(!info) {
        puts("Failed Video Query.");
        return 0;
    }
    */

    window = SDL_CreateWindow(
        "NotePlus",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_OPENGL
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_PROFILE_MASK,
        SDL_GL_CONTEXT_PROFILE_CORE
    );

    mainContext = SDL_GL_CreateContext(window);
    //gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress); for glad, not glew
    
    return 1;
}

void destroy_window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

SDL_Renderer* get_renderer() {
    return renderer;
}

SDL_Window* get_window() {
    return window;
}