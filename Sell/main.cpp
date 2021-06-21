#include <iostream>

#include <SDL_ttf.h>

#include "Sell.hpp"

void Start(); // Start Callback Declaration
void Update(); // Update Callback Declaration

Sell sell; // Sell instance
InputManager* inputManager; // InputManager instance
UIManager* uiManager; // UIManager instance

AudioPlayer audioPlayer;

TTF_Font* sans;

SDL_Texture* stationTexture;
SDL_Texture* station2Texture;
SDL_Texture* station3Texture;
SDL_Texture* textTexture;

Entity* station; // station entity
Element* uiElement; // UI Element
Element* uiTextElement; // UI Text Element

Timer timer = Timer();

int main(int argc, char *argv[]) {
    sell.Init("SELL", 1280, 720, &Start, &Update); // Init Sell Engine

    return 0; // SDL2 needs this at the end of main
}

void Start() {
    inputManager = sell.GetInputManager(); // Get inputManager instance
    uiManager = sell.GetUIManager(); // Get UIManager instance

    sans = TTF_OpenFont("gfx/Sans.ttf", 200);

    stationTexture = sell.GetRenderWindow()->LoadTexture("gfx/img.png");
    station2Texture = sell.GetRenderWindow()->LoadTexture("gfx/img1.png");
    station3Texture = sell.GetRenderWindow()->LoadTexture("gfx/img2.png");
    textTexture = sell.GetRenderWindow()->CreateMessageTexture(sans, {255,255,255}, "Hello World! (Also I really hope this works)");

    station = sell.InstantiateEntity(Vector2(0, 0), Vector2(1,1), stationTexture); // Instantiate entity for station
    station->SetAnimation({stationTexture, station2Texture, station3Texture}, {1, 3, 6}); // Set animation for station
    //uiElement = uiManager->InstantiateElement(Vector2(0.88889f, 0.5f), Vector2(0.5f, 0.5f), stationTexture); // Instantiate UI Element with station texture
    uiTextElement = uiManager->InstantiateElement(Vector2(0.88889f, 0.9f), Vector2(0.1f, 0.1f), textTexture); // Instantiate UI Text Element

    //audioPlayer.Load("gfx/song.wav");
    //audioPlayer.Play();
}

void Update() {
    //station->Move(Vector2(station->getPos().x, station->getPos().y) + (3 * sell.GetDeltaTime()));
    station->MoveTowards(Vector2(station->getPos().x, station->getPos().y) + 3, sell.GetDeltaTime());
    /*if (uiElement->isClicked()) {
        std::cout << uiElement->GetSelected() << std::endl;
    }*/
}