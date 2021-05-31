#include "Sell.hpp"

Sell::Sell(const char* p_title, int p_w, int p_h, void(*p_UpdateCallback)()) : title(p_title), width(p_w), height(p_h), UpdateCallback(p_UpdateCallback) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // Init SDL
        std::cout << "SDL could not initialize. SDL Error:" << SDL_GetError << std::endl;
    if (!IMG_Init(IMG_INIT_PNG)) // Init image loading script in SDL
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;

    Update();
}

void Sell::Update() {
    RenderWindow window(title, width, height); // Create Window
    SDL_Event event; // SDL Event Queue

    while (run) { // Game Loop
        Timer* timer = new Timer();
    
        UpdateCallback();
    
        while (SDL_PollEvent(&event)) { // Loop through SDL Events
            if (event.type == SDL_QUIT) { // If quit button was pressed stop running
                run = false;
            }
        }
    
        window.Clear(); // Clear Window
        for (Entity& entity : entities) { // Loop through entities
            window.Render(entity); // Draw current entity
        }
        window.Display(); // Display all rendered textures
    
        utils::time::deltaTime = timer->EndTimer(timer);
        fps = (int)(1 / utils::time::deltaTime);

        if (utils::time::deltaTime < 1 / (float)targetFPS) {
            SDL_Delay((int)(1 / (float)targetFPS - utils::time::deltaTime) * 1000);
        }
    }
    window.CleanUp();
    SDL_Quit();
    
}
