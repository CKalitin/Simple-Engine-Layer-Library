#include <iostream>

#include "Sell.hpp"

void Start(); // Start Callback Declaration
void Update(); // Update Callback Declaration

Sell sell; // Sell instance
InputManager* inputManager; // InputManager instance
UIManager* uiManager; // UIManager instance

SDL_Texture* stationTexture;

Entity* station; // station entity
Element* uiElement; // UI Element

int main(int argc, char *argv[]) {
    sell.Init("SELL", 1280, 720, &Start, &Update); // Init Sell Engine

    return 0; // SDL2 needs this at the end of main
}

void Start() {
    inputManager = sell.GetInputManager(); // Get inputManager instance
    uiManager = sell.GetUIManager(); // Get UIManager instance

    stationTexture = sell.LoadTexture("gfx/img.png");

    station = sell.InstantiateEntity(Vector2(0, 0), Vector2(1,1), stationTexture); // Instantiate entity for station
    uiElement = uiManager->InstantiateElement(Vector2(0.88889f, 0.5f), Vector2(1, 1), stationTexture);
}

void Update() {
    station->Move(Vector2(station->getPos().x + (3 * sell.GetDeltaTime()), station->getPos().y + (3 * sell.GetDeltaTime())));
    //sell.SetCamPos(Vector2(sell.GetCamPos().x + (3 * sell.GetDeltaTime()), sell.GetCamPos().y + (3 * sell.GetDeltaTime())));
    //sell.GetCamPos().print();
    //station->getPos().print();
    //std::cout << "-" << std::endl;
}