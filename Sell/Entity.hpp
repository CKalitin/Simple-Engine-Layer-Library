#pragma once

#include <vector>
#include <math.h>

#include <SDL.h>
#include <SDL_image.h>

#include "Math.hpp"
#include "Utils.hpp"

class Entity {
public:
	Entity(); // Default Constructor (I don't understand this so I think it is absolute nonsense and is a horrible feature)
	Entity(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex); // Entity Constructor

	void Move(Vector2 _pos); // Move Entity to pos
	void MoveTowards(Vector2 _dest, float t); // Lerp Move Entity

	void SetAnimation(std::vector<SDL_Texture*> _animTextures, std::vector<float> _animDelays); // Set variables for animation
	void UpdateAnimation(); // Update Texture if nessesary

	Vector2& getPos() { return pos; };
	Vector2& getScale() { return scale; };
	SDL_Texture* getTex() { return tex;  };
	SDL_Rect getCurrentFrame() { return currentFrame; };
	bool getIsAnimated() { return animated; }
private:
	Vector2 pos;
	Vector2 scale;
	SDL_Rect currentFrame;
	SDL_Texture* tex;

	std::vector<SDL_Texture*> animTextures = {}; // Vector of textures for animation
	std::vector<float> animDelays = {}; // Vector of delays for animaiton

	Timer* animTimer; // Time since animation start
	bool animated = false; // If entity has animation
	float animLength = 0; // Length of animation
	int animIndex = 0; // Index of which delay and texture to use

	int animIterations; // Number of times the full animation has been run
};
