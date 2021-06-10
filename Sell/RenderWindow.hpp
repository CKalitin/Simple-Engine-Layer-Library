#pragma once

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "Entity.hpp"

class RenderWindow {
public:
	RenderWindow(const char* _title, int _w, int _h); // Constructor
	RenderWindow* GetRenderWindow(); // Returns this

	SDL_Texture* LoadTexture(const char* _filePath); // Load texture at specified file path

	int getRefreshRate(); // return refresh rate of current monitor

	void CleanUp(); // Delete dynamic variables
	void Clear(); // Clear screen
	void RenderEntity(Entity& _entity, Vector2 _posOffset, float _scale); // Render entity to screen
	void Render(SDL_Texture* _tex, SDL_Rect _rect, Vector2 _pos, Vector2 _size); // Render texture to screen
	void Display(); // Display rendered textures to window
private:
	SDL_Window* window; // Pointer to window var in SDL
	SDL_Renderer* renderer; // Pointer to SDL Renderer
};