#include "AudioPlayer.hpp"

AudioPlayer::~AudioPlayer() {
	SDL_CloseAudioDevice(deviceId); // Close audio device
	SDL_FreeWAV(wavBuffer); // Free memory assigned to wavBuffer
}

void AudioPlayer::Load(const char* _filePath) {
	if (SDL_LoadWAV(_filePath, &wavSpec, &wavBuffer, &wavLength) == NULL) { // Load wav file
		std::cout << "Could not open " << _filePath << ". Error: " << SDL_GetError() << std::endl; // Send error message if unable to load
	}
	deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0); // Open Audio Device to play audio from
}

void AudioPlayer::Play() {
	SDL_QueueAudio(deviceId, wavBuffer, wavLength); // Queue the Audio
	SDL_PauseAudioDevice(deviceId, 0); // Start playing
}

void AudioPlayer::Pause() {
	SDL_PauseAudioDevice(deviceId, 1); // Pause Audio
}
