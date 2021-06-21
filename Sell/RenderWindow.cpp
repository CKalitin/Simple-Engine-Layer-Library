#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* _title, int _w, int _h) : window(NULL), renderer(NULL), windowDimensions(_w, _h) {
	window = SDL_CreateWindow(_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _w, _h, SDL_WINDOW_SHOWN + SDL_WINDOW_RESIZABLE); // Create SDL Window
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
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture; // Return newly loaded texture
}

SDL_Texture* RenderWindow::CreateMessageTexture(TTF_Font* _font, SDL_Color _colour, const char* _message) {
	SDL_Texture* messageTexture = NULL; // Declare texture variable
	SDL_Surface* messageSurface = NULL; // Declare message surface variable

	messageSurface = TTF_RenderText_Solid(_font, _message, _colour); // Create Text Surface
	messageTexture = SDL_CreateTextureFromSurface(renderer, messageSurface); // Turn Text surface in SDL Texture

	if (messageTexture == NULL) // If texture was not loaded send an error message
		std::cout << "Failed to load message texture. Error: " << SDL_GetError() << std::endl;

	if (messageTexture == NULL) // If texture was not loaded send an error message
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return messageTexture; // Return newly loaded Texture
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

void RenderWindow::RenderEntity(Entity& _entity, Vector2 _pos, float _scale) {
	SDL_GetWindowSize(window, &windowDimensions.x, &windowDimensions.y); // Set windowDimensions to current window size

	SDL_Rect src; // Source, Create rect for texture
	src.x = _entity.getCurrentFrame().x;
	src.y = _entity.getCurrentFrame().y;
	src.w = _entity.getCurrentFrame().w;
	src.h = _entity.getCurrentFrame().h;

	SDL_Rect dst; // Destination, Create rect for texture
	// Set texture position to entity position and adjust so it is centered, not off to the bottom right
	dst.x = (int)(_pos.x * (_entity.getScale().x / (1 * _scale)));
	dst.y = (int)(_pos.y * (_entity.getScale().y / (1 * _scale)));
	dst.w = (int)(_entity.getCurrentFrame().w * _entity.getScale().x / (1 * _scale) * ((float)windowDimensions.x / (1000 * ((float)windowDimensions.x / (float)windowDimensions.y))));
	dst.h = (int)(_entity.getCurrentFrame().h * _entity.getScale().y / (1 * _scale) * ((float)windowDimensions.y / 1000));

	SDL_RenderCopy(renderer, _entity.getTex(), &src, &dst); // Render texture to screen

}

void RenderWindow::Render(SDL_Texture* _tex, SDL_Rect _rect, Vector2 _pos, Vector2 _size) {
	SDL_Rect src; // Source, Create rect for texture
	src.x = _rect.x;
	src.y = _rect.y;
	src.w = _rect.w;
	src.h = _rect.h;

	SDL_Rect dst; // Destination, Create rect for texture
	// Set pos and adjust so it is centered, not off to the bottom right
	dst.x = (int)_pos.x - (int)(_size.x / 2);
	dst.y = (int)_pos.y - (int)(_size.y / 2);
	dst.w = (int)_size.x;
	dst.h = (int)_size.y;

	SDL_RenderCopy(renderer, _tex, &src, &dst); // Render texture to screen
}

void RenderWindow::Display() {
	SDL_RenderPresent(renderer); // Display all rendered textures
}