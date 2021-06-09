#include <iostream>

#include "Sell.hpp"

void Start(); // Start Callback Declaration
void Update(); // Start Callback Declaration

Sell sell; // Sell instance
InputManager* inputManager; // InputManager instance

Entity* station; // station entity

int main(int argc, char *argv[]) {
    sell.Init("SELL", 1280, 720, &Start, &Update); // Init Sell Engine

    return 0; // SDL2 needs this at the end of main
}

void Start() {
    inputManager = sell.GetInputManager(); // Get inputManager instance

    station = sell.InstantiateEntity(Vector2(0, 0), Vector2(1,1), "gfx/img.png"); // Instantiate entity for station

    sell.SetCamSize(0.25);
}

void Update() {
    station->Move(Vector2(station->getPos().x + (3 * sell.GetDeltaTime()), station->getPos().y + (3 * sell.GetDeltaTime())));
    //sell.SetCamPos(Vector2(sell.GetCamPos().x + (3 * sell.GetDeltaTime()), sell.GetCamPos().y + (3 * sell.GetDeltaTime())));
    //sell.GetCamPos().print();
    //station->getPos().print();
    //std::cout << "-" << std::endl;
}