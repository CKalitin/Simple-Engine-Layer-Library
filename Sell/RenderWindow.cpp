#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) : window(NULL), renderer(NULL) {
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN); // Create SDL Window
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

void RenderWindow::Render(Entity& p_entity) {
	SDL_Rect src; // Source: Create rect for texture
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst; // Destination: Create rect for texture
	// Set texture position to entity position
	dst.x = (int)p_entity.getPos().x;
	dst.y = (int)p_entity.getPos().y;
	// Set texture pixels and scale to entity pixels and scale
	dst.w = p_entity.getCurrentFrame().w * (int)p_entity.getScale().x;
	dst.h = p_entity.getCurrentFrame().h * (int)p_entity.getScale().y;

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst); // Render texture to screen
}

void RenderWindow::Display() {
	SDL_RenderPresent(renderer); // Display all rendered textures
}