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
    while (run) {
        const float timeStep = 0.01f;
        float accumulator = 0.0f;
        float currentTime = utils::hireTimeInSeconds();

        while (run) { // Game Loop
            //std::cout << "Game Loop" << std::endl;
            UpdateCallback();
            //std::cout << "Loop Game" << std::endl;

            int startTick = SDL_GetTicks();

            float newTime = utils::hireTimeInSeconds();
            float frameTime = newTime - currentTime;
            currentTime = newTime;

            while (accumulator >= timeStep) {
                while (SDL_PollEvent(&event)) { // Loop through SDL Events
                    if (event.type == SDL_QUIT) { // If quit button was pressed stop running
                        run = false;
                    }
                }

                accumulator -= timeStep;
            }

            const float alpha = accumulator / timeStep;

            window.Clear(); // Clear Window

            for (Entity& entity : entities) { // Loop through entities
                window.Render(entity); // Draw current entity
            }

            window.Display(); // Display all rendered textures

            int frameTicks = SDL_GetTicks();

            if (frameTicks < 1000 / window.getRefreshRate())
                SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
        }
        window.CleanUp();
        SDL_Quit();
    }
}
