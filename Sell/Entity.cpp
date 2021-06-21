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

void Entity::SetAnimation(std::vector<SDL_Texture*> _animTextures, std::vector<float> _animDelays) {
	animTextures = _animTextures;
	animDelays = _animDelays;

	animLength = _animDelays.back();
	animated = true;

	animTimer = new Timer();
}

void Entity::UpdateAnimation() {
	/*animProgress = animTimer->GetTime() - (animTime * floor(animTimer->GetTime() / animTime - 0.05f));
	std::cout << animProgress << std::endl;

	for (int i = animIndex; i < animDelays.size(); i++) {
		if (animProgress > animDelays[i]) {
			tex = animTextures[i];
			animIndex++;
			animIndex = animIndex % animDelays.size();
			return;
		}
	}*/
	std::cout << animTimer->GetTime() << ", " << animDelays[animIndex] + (animLength * animIterations) << std::endl;
	if (animTimer->GetTime() > animDelays[animIndex] + (animLength * animIterations)) {
		animIndex++;
		if (animIndex > animDelays.size() - 1) {
			animIndex = 0;
			animIterations++;
		}

		tex = animTextures[animIndex];

	}
}
