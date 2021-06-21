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
	pos.x = pos.x + ((_dest.x - pos.x) * t);
	pos.y = pos.y + ((_dest.y - pos.y) * t);
}
