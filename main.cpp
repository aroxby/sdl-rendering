#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

class WavSound {
public:
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;

    WavSound(const char *path) {
        SDL_LoadWAV(path, &wavSpec, &wavBuffer, &wavLength);
    }
    
    ~WavSound() {
        SDL_FreeWAV(wavBuffer);
    }

    int play(SDL_AudioDeviceID audioDevice) {
        int err = SDL_QueueAudio(audioDevice, wavBuffer, wavLength);
        if(!err) {
            SDL_PauseAudioDevice(audioDevice, 0);
        }
        return err;
    }
};

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

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    if(SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer)) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    WavSound sound("../Blackbird.SoundBible.wav");
    SDL_AudioDeviceID audioDevice = SDL_OpenAudioDevice(NULL, 0, &sound.wavSpec, NULL, 0);
    sound.play(audioDevice);

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

    SDL_CloseAudioDevice(audioDevice);
    SDL_Quit();

    return 0;
}
