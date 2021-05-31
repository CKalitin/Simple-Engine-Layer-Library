#include <iostream>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "utils.hpp"

class Sell {
public:
	Sell(const char* p_title, int p_w, int p_h, void(*p_UpdateCallback)()); // Init function
	void Update(); // Loop which will run every frame
private:
	//RenderWindow* window;
	void(*UpdateCallback)();
	bool run = true;

	const char* title;
	int width;
	int height;

	std::vector<Entity> entities;
};