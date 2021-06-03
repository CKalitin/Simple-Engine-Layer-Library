#include "Sell.hpp"

void Sell::Init(const char* p_title, int p_w, int p_h, void(*p_StartCallback)(), void(*p_UpdateCallback)()) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // Init SDL
        std::cout << "SDL could not initialize. SDL Error:" << SDL_GetError << std::endl;
    if (!IMG_Init(IMG_INIT_PNG)) // Init image loading script in SDL
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;

    StartCallback = p_StartCallback; // Set Start Callback Variable
    UpdateCallback = p_UpdateCallback; // Set Update Callback Variable

    RenderWindow newWindow(p_title, p_w, p_h); // Init Window
    window = newWindow.GetRenderWindow(); // Get Window pointer

    inputManager = InputManager(); // Create Input Manager

    Loop(); // Start Loop
}

void Sell::Loop() {
    StartCallback(); // Run Start Callback

    while (run) { // Game Loop
        Timer* timer = new Timer(); // Init Timer for time taken per frame
    
        inputManager.Update();

        UpdateCallback(); // Run Update Callback

        if (inputManager.onQuit()) { // If X in top right of window is pressed
            run = false;
        }

        (*window).Clear(); // Clear Window
        for (Entity& entity : entities) { // Loop through entities
            (*window).Render(entity); // Draw current entity
        }
        (*window).Display(); // Display all rendered textures
    
        deltaTime = timer->GetTime(); // Set deltaTime
        if (deltaTime < 1 / (float)targetFPS) { // If the frame was finished before fps time specified
            SDL_Delay((int)((1 / (float)targetFPS - deltaTime) * 1000)); // Delay until frame time = specified frame time from SetFPS
        }

        deltaTime = timer->GetTime(); // Get actual deltaTime after delay
        fps = (int)round(1 / deltaTime); // Set FPS variable
        delete timer; // Delete Timer
    }
    (*window).CleanUp(); // Close Window
    SDL_Quit(); // Quit SDL
    
}

Entity* Sell::InstantiateEntity(Vector2 p_pos, Vector2 p_scale, const char* p_texturePath) {
    Entity newEntity = Entity(p_pos, p_scale, window->LoadTexture(p_texturePath)); // Create new Entity
    entities.push_back(newEntity); // Add new Entity to entities list
    return &entities[entities.capacity() - 1]; // return memory position of new Entity in entities list
}

void Sell::DeleteEntity(Entity* p_entity) {
    //entities.erase(std::remove(entities.begin(), entities.end(), p_entity), entities.end());
    delete p_entity;
}
