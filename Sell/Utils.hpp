#pragma once

#include <SDL.h>

namespace utils {
	namespace time {
		inline float timeInSeconds() { return SDL_GetTicks() / 1000.0f; } // Return current time in seconds since SDL Init
	}
}

class Timer {
public:
	Timer() { startTime = utils::time::timeInSeconds(); }; // Construct timer
	float GetTime() { return utils::time::timeInSeconds() - startTime; }; // Get current time of Timer
private:
	float startTime; // Start time of Timer
};