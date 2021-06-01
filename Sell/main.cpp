#include <iostream>

#include "Sell.hpp"

void Start(); // Start Callback Declaration
void Update(); // Start Callback Declaration

Sell sell; // Sell instance
Entity* station; // station entity

int main(int argc, char *argv[]) {
    sell.Init("SELL", 1280, 720, &Start, &Update); // Init Sell Engine

    return 0; // SDL2 needs this at the end of main
}

void Start() {
    station = sell.InstantiateEntity(Vector2(200, 200), "gfx/img.png"); // Instantiate entity for station
}

void Update() {
    station->Move(Vector2((*station).getPos().x + 1.5, (*station).getPos().x + 1.5));
    station->getPos().print();
}