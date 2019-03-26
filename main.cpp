#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc, char *argv[]) {
    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    SDL_Delay(5000);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
