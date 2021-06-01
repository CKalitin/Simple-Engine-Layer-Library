#pragma once

#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "Math.hpp"

class Entity {
public:
	Entity(); // Default Constructor (I don't understand this so I think it is absolute nonsense and is a horrible feature)
	Entity(Vector2 p_pos, SDL_Texture* p_tex); // Entity Constructor

	void Move(Vector2 p_pos); // Move Entity to pos

	Vector2& getPos() { return pos; };
	SDL_Texture* getTex() { return tex;  };
	SDL_Rect getCurrentFrame() { return currentFrame; };
private:
	Vector2 pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};
