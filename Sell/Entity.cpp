#include "Entity.hpp"

Entity::Entity(Vector2 _pos, Vector2 _scale, SDL_Texture* _tex) : pos(_pos), scale(_scale), tex(_tex) {
	int w, h;
	SDL_QueryTexture(_tex, NULL, NULL, &w, &h); // Get pixel dimensions of texture

	// Set variables of currentFrame
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = w;
	currentFrame.h = h;
}

void Entity::Move(Vector2 _pos) {
	pos.x = _pos.x; // Set current X to new pos
	pos.y = _pos.y; // Set current Y to new pos
}

void Entity::MoveTowards(Vector2 _dest, float t) {
	pos.x += (_dest.x - pos.x) * t; // Add new X pos to current pos X
	pos.y += (_dest.y - pos.y) * t; // Add new Y pos to current pos Y
}

void Entity::SetAnimation(std::vector<SDL_Texture*> _animTextures, std::vector<float> _animDelays) {
	if (animated == true) { delete animTimer; } // If this is setting a new animation delete the old timer

	animTextures = _animTextures; // Set animTextures
	animDelays = _animDelays; // Set animDelays

	animated = true; // Set animated
	animLength = _animDelays.back(); // Set animLength
	animIndex = 0; // Reset animIndex

	animTimer = new Timer(); // Create new Timer
}

void Entity::UpdateAnimation() {
	if (animTimer->GetTime() > animDelays[animIndex] + (animLength * animIterations)) { // If current time if greater than delay
		animIndex++; // Increase animationIndex
		if (animIndex > animDelays.size() - 1) { // If animIndex is greater than animDelays
			animIndex = 0;
			animIterations++;
		}

		tex = animTextures[animIndex]; // Set texture
	}
}
