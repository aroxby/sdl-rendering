#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

void draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
    SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
    SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer)) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    bool done = false;
    SDL_Event event;
    do {
        draw(renderer);

        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                done = true;
            }
        }
    }while(!done);

    if (renderer) {
        SDL_DestroyRenderer(renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();

    return 0;
}
