#include "Sell.hpp"

void Sell::Init(const char* _title, int _w, int _h, void(*_StartCallback)(), void(*_UpdateCallback)()) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // Init SDL
        std::cout << "SDL could not initialize. SDL Error:" << SDL_GetError << std::endl;
    if (!IMG_Init(IMG_INIT_PNG)) // Init image loading script in SDL
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;

    StartCallback = _StartCallback; // Set Start Callback Variable
    UpdateCallback = _UpdateCallback; // Set Update Callback Variable

    windowDimensions = Vector2((float)_w, (float)_h);

    RenderWindow newWindow(_title, _w, _h); // Init Window
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
        //(-camPos.x + (windowDimensions.x / 2)) / (1 / camSize), (-camPos.y + (windowDimensions.y / 2)) / (1 / camSize)
        (*window).Clear(); // Clear Window
        for (Entity& entity : entities) { // Loop through entities
            Vector2 entityPos = Vector2(entity.getPos().x * (1 / camSize) + (windowDimensions.x / 2) + camPos.x, entity.getPos().y * (1 / camSize) + (windowDimensions.y / 2) + camPos.x); // Get position of entity and adjust
            (*window).Render(entity, entityPos, camSize); // Draw current entity
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

Entity* Sell::InstantiateEntity(Vector2 _pos, Vector2 _scale, const char* _texturePath) {
    Entity newEntity = Entity(_pos, _scale, window->LoadTexture(_texturePath)); // Create new Entity
    entities.push_back(newEntity); // Add new Entity to entities list
    return &entities[entities.capacity() - 1]; // return memory position of new Entity in entities list
}

void Sell::DeleteEntity(Entity* _entity) {
    //entities.erase(std::remove(entities.begin(), entities.end(), p_entity), entities.end());
    delete _entity;
}
