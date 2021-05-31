#pragma once

#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "Math.hpp"

class Entity {
public:
	Entity(Vector2 p_pos, SDL_Texture* p_tex); // Entity Constructor
	Vector2& getPos() { return pos; };
	SDL_Texture* getTex() { return tex;  };
	SDL_Rect getCurrentFrame() { return currentFrame; };

	static std::vector<Entity> entities;
private:
	Vector2 pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};
