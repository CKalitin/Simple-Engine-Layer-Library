#pragma once

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.hpp"

class RenderWindow {
public:
	RenderWindow(const char* p_title, int p_w, int p_h); // Constructor
	RenderWindow* GetRenderWindow(); // Returns this

	SDL_Texture* LoadTexture(const char* p_filePath); // Load texture at specified file path

	int getRefreshRate(); // return refresh rate of current monitor

	void CleanUp(); // Delete dynamic variables
	void Clear(); // Clear screen
	void Render(Entity& p_entity); // Render entity to screen
	void Display(); // Display rendered textures to window
private:
	SDL_Window* window; // Pointer to window var in SDL
	SDL_Renderer* renderer; // Pointer to SDL Renderer
};