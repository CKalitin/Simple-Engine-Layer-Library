#include "Sell.hpp"

void Sell::Init(const char* p_title, int p_w, int p_h, void(*p_StartCallback)(), void(*p_UpdateCallback)()) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) // Init SDL
        std::cout << "SDL could not initialize. SDL Error:" << SDL_GetError << std::endl;
    if (!IMG_Init(IMG_INIT_PNG)) // Init image loading script in SDL
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;

    title = p_title;
    width = p_w;
    height = p_h;

    UpdateCallback = p_UpdateCallback;
    StartCallback = p_StartCallback;

    RenderWindow newWindow(p_title, p_w, p_h);
    window = newWindow.GetRenderWindow();

    Loop();
}

void Sell::Loop() {
    //RenderWindow window(title, width, height); // Create Window
    SDL_Event event; // SDL Event Queue

    StartCallback();

    while (run) { // Game Loop
        Timer* timer = new Timer();
    
        UpdateCallback();
    
        while (SDL_PollEvent(&event)) { // Loop through SDL Events
            if (event.type == SDL_QUIT) { // If quit button was pressed stop running
                run = false;
            }
        }
    
        (*window).Clear(); // Clear Window
        for (Entity& entity : entities) { // Loop through entities
            (*window).Render(entity); // Draw current entity
        }
        (*window).Display(); // Display all rendered textures
    
        float deltaTime = timer->GetTime();
        if (deltaTime < 1 / (float)targetFPS) {
            SDL_Delay((int)((1 / (float)targetFPS - deltaTime) * 1000));
        }

        utils::time::deltaTime = timer->GetTime();
        fps = (int)round(1 / utils::time::deltaTime);
        delete timer;
    }
    (*window).CleanUp();
    SDL_Quit();
    
}

Entity* Sell::InstantiateEntity(Vector2 p_pos, const char* texturePath) {
    Entity newEntity = Entity(p_pos, window->LoadTexture(texturePath));
    entities.push_back(newEntity);
    newEntity.getPos().print();
    return &entities[entities.capacity() - 1];
}

void Sell::DeleteEntity(Entity* p_entity) {
    //entities.erase(std::remove(entities.begin(), entities.end(), p_entity), entities.end());
    delete p_entity;
}
