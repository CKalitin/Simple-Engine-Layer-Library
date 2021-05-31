#include <SDL.h>
#include <SDL_image.h>

#include "Sell.hpp"

void Update();

int main(int argc, char *argv[]) {
    Sell("SELL", 1280, 720, &Update);

    return 0;
}

void Update() {
    //std::cout << "Hello from Update2!!!" << std::endl;
}