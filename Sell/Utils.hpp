#pragma once

#include <SDL.h>

namespace utils {
	namespace time {
		inline float timeInSeconds() {
			return SDL_GetTicks() / 1000.0f;
		}
		static float deltaTime = 0;
	}
}

class Timer {
public:
	Timer() { startTime = utils::time::timeInSeconds(); };
	float GetTime() {
		return utils::time::timeInSeconds() - startTime;
	};
private:
	float startTime;
};