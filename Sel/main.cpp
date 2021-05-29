#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        std::cout << "SDL could not initialize. SDL Error:" << SDL_GetError << std::endl;
    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;

    return 0; // Need return 0 in main() when using SDL
}