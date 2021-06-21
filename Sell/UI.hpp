#pragma once

#include <iostream>
#include <vector>
#include <list>

#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.hpp"
#include "InputManager.hpp"
#include "utils.hpp"

class Element {
public:
	Element(); // Default Constructor (I don't understand this so I think it is absolute nonsense and is a horrible feature)
	Element(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex, InputManager* _inputManager, Vector2Int _windowDimensions); // UI Element Constructor

	void Move(Vector2 _pos); // Move Entity to pos

	bool isClicked();

	Vector2& getPos() { return pos; };
	Vector2& getScale() { return scale; };
	SDL_Texture* getTex() { return tex; };
	SDL_Rect getCurrentFrame() { return currentFrame; };

	bool GetSelected() { return selected; };
private:
	Vector2 pos;
	Vector2 scale;
	SDL_Rect currentFrame;
	SDL_Texture* tex;

	InputManager* inputManager; // SELL input manager for buttons and input fields
	Vector2Int windowDimensions;
	float windowXtoY = 0;

	bool selected = false;
};

class UIManager {
public:
	UIManager() {}; // Default Constructor for initialization of variables
	UIManager(Vector2Int _windowDimensions, RenderWindow* _renderWindow, InputManager* _inputManager); // UI Construcor

	void RenderElements(); // Render all UI elements to specified window

	Element* InstantiateElement(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex); // Create new element
	void RemoveElement(Element* _element); // Remove element from list and delete

	void SetWindowDimensions(Vector2Int _windowDimensions);

private:
	Vector2Int windowDimensions; // Dimensions of specified window

	RenderWindow* renderWindow; // Render window to render elements to
	InputManager* inputManager; // SELL input manager for buttons and input fields

	float windowXToY; // windowDimensions.x / windowDimensions.y, this is for normalized ui coordinates

	std::list<Element> elements = {}; // List of elements
};