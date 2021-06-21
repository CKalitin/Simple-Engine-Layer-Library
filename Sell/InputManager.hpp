#pragma once

#include <vector>

#include <SDL.h>

#include "Math.hpp"

enum mouse_buttons
{
	LEFT_Mouse_Button = 0,
	MIDDLE_Mouse_Button = 1,
	RIGHT_Mouse_Button = 2
};

class InputManager {
public:
	InputManager() {};

	void Update(); // Run every frame to get inputs

	bool isKeyDown(SDL_Scancode _key); // Return true if specified key is pressed
	bool isMouseButtonDown(int _mouseButton); // Return true if specified mouseButton is pressed
	Vector2 getMousePosition(); // Return current mouse pos
	bool onQuit(); // Return if X in top right corner is pressed

	const Uint8* getKeyStates() { return keyStates; };
private:
	const Uint8* keyStates = 0; // List of Key States as ints

	std::vector<bool> mouseButtonStates = {false, false, false}; // List of Mouse Button States 
	Vector2 mousePos = Vector2(); // Mouse Position

	bool quitPressed = false; // If X button in top right is pressed
};