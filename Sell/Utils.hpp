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
	float EndTimer(Timer* p_timer) {
		return utils::time::timeInSeconds() - startTime;
		delete p_timer;
	};
private:
	float startTime;
};