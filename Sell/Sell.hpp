#include <iostream>
#include <vector>
#include <math.h>

#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "InputManager.hpp"
#include "utils.hpp"

class Sell {
public:
	Sell() {}; // Default Constructor
	void Init(const char* p_title, int p_w, int p_h, void(*p_StartCallback)(), void(*p_UpdateCallback)()); // Init Window and Vars
	void Loop(); // Loop which will run every frame

	InputManager* GetInputManager() { return &inputManager; }; // Return Input Manager

	int GetFPS() { return fps; }; // GetFPS (Used by user)
	void SetTargetFPS(int p_targetFPS) { targetFPS = p_targetFPS; }; // Set Target FPS (Used by user)
	float GetDeltaTime() { return deltaTime; }; // Get deltaTime (Used by user)

	Entity* InstantiateEntity(Vector2 p_pos, Vector2 p_scale, const char* p_texturePath); // Create new entity meathod
	void DeleteEntity(Entity* p_entity); // Delete entity meathod
private:
	int fps;
	int targetFPS = 30;

	float deltaTime;

	RenderWindow* window;
	InputManager inputManager;

	void(*UpdateCallback)();
	void(*StartCallback)();

	bool run = true;

	std::vector<Entity> entities = {};
};