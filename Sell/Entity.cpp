#include "Entity.hpp"

Entity::Entity(Vector2 p_pos, SDL_Texture* p_tex) : pos(p_pos), tex(p_tex) {
	int w, h;
	SDL_QueryTexture(p_tex, NULL, NULL, &w, &h);

	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = w;
	currentFrame.h = h;
}

void Entity::Move(Vector2 p_pos) {
	pos.x = p_pos.x; // Set current X to new pos
	pos.y = p_pos.y; // Set current Y to new pos
}
