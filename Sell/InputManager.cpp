#include "InputManager.hpp"

void InputManager::Update() {
    SDL_Event event; // SDL Event Queue
    while (SDL_PollEvent(&event)) { // Loop through SDL Events
        if (event.type == SDL_MOUSEMOTION) { // If event is mouse had moved, update mousePos variables
            mousePos.x = (float)event.motion.x;
            mousePos.y = (float)event.motion.y;
        } else if (event.type == SDL_KEYDOWN) { // If event is KeyDown, update key list values
            keyStates = SDL_GetKeyboardState(0);
        } else if (event.type == SDL_KEYUP) { // If event is KeyUp, update key list values
            keyStates = SDL_GetKeyboardState(0);
        } else if (event.type == SDL_MOUSEBUTTONDOWN) { // If event is mouse button down, update mouse button value
            if (event.button.button == SDL_BUTTON_LEFT) { // Check if mouse button is left mouse button
                mouseButtonStates[LEFT_Mouse_Button] = true;
            } else if (event.button.button == SDL_BUTTON_MIDDLE) { // Check if mouse button is middle mouse button
                mouseButtonStates[MIDDLE_Mouse_Button] = true;
            }else if (event.button.button == SDL_BUTTON_RIGHT) { // Check if mouse button is right mouse button
                mouseButtonStates[RIGHT_Mouse_Button] = true;
            }
        } else if (event.type == SDL_MOUSEBUTTONUP) { // If event is mouse button up, update mouse button value
            if (event.button.button == SDL_BUTTON_LEFT) { // Check if mouse button is left mouse button
                mouseButtonStates[LEFT_Mouse_Button] = false;
            } else if (event.button.button == SDL_BUTTON_MIDDLE) { // Check if mouse button is middle mouse button
                mouseButtonStates[MIDDLE_Mouse_Button] = false;
            } else if (event.button.button == SDL_BUTTON_RIGHT) { // Check if mouse button is right mouse button
                mouseButtonStates[RIGHT_Mouse_Button] = false;
            }
        } else if (event.type == SDL_QUIT) { // If event is X in top right is pressed, update quitPressed bool value
            quitPressed = true;
        }
    }

}

bool InputManager::isKeyDown(SDL_Scancode _key) {
    if (keyStates != 0) { // If there are keys down
        if (keyStates[_key] == 1) { // If key is pressed
            return true;
        } else {
            return false;
        }
    }

    return false;
}

bool InputManager::isMouseButtonDown(int _mouseButtonNumber) {
    return mouseButtonStates[_mouseButtonNumber]; // Return mouseButton bool value
}

Vector2 InputManager::getMousePosition() {
	return mousePos; // Return pointer to mousePos
}

bool InputManager::onQuit() {
	return quitPressed; // Return quitPressed bool value
}
