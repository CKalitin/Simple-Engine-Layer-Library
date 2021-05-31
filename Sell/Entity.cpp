#include "Entity.hpp"

Entity::Entity(Vector2 p_pos, SDL_Texture* p_tex) : pos(p_pos), tex(p_tex) {
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 126;
	currentFrame.h = 128;
}
