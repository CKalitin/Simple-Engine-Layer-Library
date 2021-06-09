#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* _title, int _w, int _h) : window(NULL), renderer(NULL) {
	window = SDL_CreateWindow(_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _w, _h, SDL_WINDOW_SHOWN); // Create SDL Window
	if (window == NULL) { // Check if window failed to init
		std::cout << "Window failed to init. Error" << SDL_GetError() << std::endl; // Print error
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // Setup renderer, param 3 is to use graphics card for better rendering times
}

RenderWindow* RenderWindow::GetRenderWindow() {
	return this; // Return pointer to RenderWindow
}

SDL_Texture* RenderWindow::LoadTexture(const char* p_filePath) {
	SDL_Texture* texture = NULL; // Declare texture variable
	texture = IMG_LoadTexture(renderer, p_filePath); // Get texture from file path

	if (texture == NULL) // If texture was not loaded send an error message
		std::cout << "Failed to lead texture. Error: " << SDL_GetError() << std::endl;

	return texture; // return newly loaded texture
}

int RenderWindow::getRefreshRate() {
	int displayIndex = SDL_GetWindowDisplayIndex(window); // Index of monitor being used for game window
	SDL_DisplayMode mode; // Declare mode variable
	SDL_GetDisplayMode(displayIndex, 0, &mode); // Set mode to data from monitor in use

	return mode.refresh_rate; // return refresh rate for monitor in use
}

void RenderWindow::CleanUp() {
	SDL_DestroyWindow(window); // Close window
}

void RenderWindow::Clear() {
	SDL_RenderClear(renderer); // Clear Window
}

void RenderWindow::Render(Entity& _entity, Vector2 _pos, float _scale) {
	SDL_Rect src; // Source: Create rect for texture
	src.x = _entity.getCurrentFrame().x;
	src.y = _entity.getCurrentFrame().y;
	src.w = _entity.getCurrentFrame().w;
	src.h = _entity.getCurrentFrame().h;

	SDL_Rect dst; // Destination: Create rect for texture
	// Set texture position to entity position and adjust so it is centered, not off to the bottom right
	dst.x = (int)_pos.x - ((_entity.getCurrentFrame().w / 2) * _entity.getScale().x / (1 * _scale));
	dst.y = (int)_pos.y - ((_entity.getCurrentFrame().h / 2) * _entity.getScale().y / (1 * _scale));
	dst.w = (int)(_entity.getCurrentFrame().w * _entity.getScale().x / (1 * _scale));
	dst.h = (int)(_entity.getCurrentFrame().h * _entity.getScale().y / (1 * _scale));

	SDL_RenderCopy(renderer, _entity.getTex(), &src, &dst); // Render texture to screen
}

void RenderWindow::Display() {
	SDL_RenderPresent(renderer); // Display all rendered textures
}