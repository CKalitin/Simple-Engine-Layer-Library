#include <iostream>
#include <vector>
#include <math.h>
#include <list>

#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "InputManager.hpp"
#include "UI.hpp"
#include "AudioPlayer.hpp"
#include "utils.hpp"

class Sell {
public:
	Sell() {}; // Default Constructor
	void Init(const char* _title, int _w, int _h, void(*_StartCallback)(), void(*_UpdateCallback)()); // Init Window and Vars
	void Loop(); // Loop which will run every frame

	InputManager* GetInputManager() { return &inputManager; }; // Return Input Manager
	UIManager* GetUIManager() { return &uiManager; }; // Return UI class
	RenderWindow* GetRenderWindow() { return renderWindow; }

	Entity* InstantiateEntity(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex); // Create new entity meathod
	void DeleteEntity(Entity* _entity); // Delete entity meathod

	int GetFPS() { return fps; }; // GetFPS (Used by user)
	void SetTargetFPS(int _targetFPS) { targetFPS = _targetFPS; }; // Set Target FPS (Used by user)
	float GetDeltaTime() { return deltaTime; }; // Get deltaTime (Used by user)

	void SetCamPos(Vector2 _pos) { camPos = _pos; }; // Set Cam Pos
	Vector2 GetCamPos() { return camPos; }; // Get Cam Pos
	void SetCamSize(float _size) { camSize = _size; }; // Set Cam Scale
	float GetCamSize() { return camSize; }; // Get Cam Scale
private:
	int fps = 0;
	int targetFPS = 30;
	float deltaTime = 0;

	RenderWindow* renderWindow;
	InputManager inputManager;
	UIManager uiManager;

	void(*UpdateCallback)();
	void(*StartCallback)();

	bool run = true;

	Vector2Int windowDimensions = Vector2Int();

	std::list<Entity> entities = {};

	Vector2 camPos = Vector2();
	float camSize = 1;
};