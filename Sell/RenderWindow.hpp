#pragma once

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.hpp"

class RenderWindow {
public:
	RenderWindow(const char* p_title, int p_w, int p_h); // Constructor
	SDL_Texture* LoadTexture(const char* p_filePath);

	int getRefreshRate();

	void CleanUp();
	void Clear();
	void Render(Entity& p_entity);
	void Display();
private:
	SDL_Window* window; // Pointer to window var in SDL
	SDL_Renderer* renderer; // Pointer to SDL Renderer
};