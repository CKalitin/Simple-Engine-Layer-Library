#pragma once

#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "Math.hpp"

class Entity {
public:
	Entity(); // Default Constructor (I don't understand this so I think it is absolute nonsense and is a horrible feature)
	Entity(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex); // Entity Constructor

	void Move(Vector2 _pos); // Move Entity to pos

	Vector2& getPos() { return pos; };
	Vector2& getScale() { return scale; };
	SDL_Texture* getTex() { return tex;  };
	SDL_Rect getCurrentFrame() { return currentFrame; };
private:
	Vector2 pos;
	Vector2 scale;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};
