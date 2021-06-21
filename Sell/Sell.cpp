#include "Sell.hpp"

void Sell::Init(const char* _title, int _w, int _h, void(*_StartCallback)(), void(*_UpdateCallback)()) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // Init SDL
        std::cout << "SDL could not initialize. SDL Error:" << SDL_GetError << std::endl;
    if (!IMG_Init(IMG_INIT_PNG)) // Init image loading script in SDL
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError << std::endl;
    if (TTF_Init() < 0) // Init text system
        std::cout << "TTF Init Error. Error:" << TTF_GetError() << std::endl;


    StartCallback = _StartCallback; // Set Start Callback Variable
    UpdateCallback = _UpdateCallback; // Set Update Callback Variable

    windowDimensions = Vector2Int(_w, _h);

    RenderWindow newWindow(_title, _w, _h); // Init Window
    renderWindow = newWindow.GetRenderWindow(); // Get Window pointer
    
    inputManager = InputManager(); // Create Input Manager
    uiManager = UIManager(windowDimensions, renderWindow, &inputManager); // Create UIManager

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
        renderWindow->Clear(); // Clear Window
        for (Entity& entity : entities) { // Loop through entities
            if (entity.getIsAnimated()) { entity.UpdateAnimation(); }
            Vector2 entityPos = Vector2((entity.getPos().x - (entity.getCurrentFrame().w / 2)) * (1 / camSize) + (windowDimensions.x / 2) + camPos.x, (entity.getPos().y - (entity.getCurrentFrame().h / 2)) * (1 / camSize) + (windowDimensions.y / 2) + camPos.x); // Get position of entity and adjust
            renderWindow->RenderEntity(entity, entityPos, camSize); // Draw current entity
        }
        uiManager.RenderElements();
        renderWindow->Display(); // Display all rendered textures

        deltaTime = timer->GetTime(); // Set deltaTime
        if (deltaTime < 1 / (float)targetFPS) { // If the frame was finished before fps time specified
            SDL_Delay((int)((1 / (float)targetFPS - deltaTime) * 1000)); // Delay until frame time = specified frame time from SetFPS
        }

        deltaTime = timer->GetTime(); // Get actual deltaTime after delay
        fps = (int)round(1 / deltaTime); // Set FPS variable
        delete timer; // Delete Timer
    }
    renderWindow->CleanUp(); // Close Window
    SDL_Quit(); // Quit SDL
    
}

Entity* Sell::InstantiateEntity(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex) {
    Entity newEntity = Entity(_pos, _scale, _tex); // Create new Entity
    entities.push_back(newEntity); // Add new Entity to entities list
    return &entities.back(); // return memory position of new Entity in entities list
}

void Sell::DeleteEntity(Entity* _entity) {
    //entities.erase(std::remove(entities.begin(), entities.end(), _entity), entities.end());
    delete _entity;
}
