#include <iostream>
#include <vector>
#include <math.h>

#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "utils.hpp"

class Sell {
public:
	Sell() {}; // Default Constructor
	void Init(const char* p_title, int p_w, int p_h, void(*p_StartCallback)(), void(*p_UpdateCallback)()); // Init Window and Vars
	void Loop(); // Loop which will run every frame

	int GetFPS() { return fps; };
	void SetTargetFPS(int p_targetFPS) { targetFPS = p_targetFPS; };

	Entity* InstantiateEntity(Vector2 p_pos, const char* texturePath);
	void DeleteEntity(Entity* p_entity);
private:
	int fps;
	int targetFPS = 30;

	RenderWindow* window;
	void(*UpdateCallback)();
	void(*StartCallback)();
	bool run = true;

	const char* title;
	int width;
	int height;

	std::vector<Entity> entities = {};
};