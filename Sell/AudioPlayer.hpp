// Code adapted from here: https://github.com/jarreed0/GameDevTut/tree/ep6-audio
#pragma once

#include <iostream>

#include <SDL.h>

class AudioPlayer {
public:
    ~AudioPlayer(); // Destructor, prevents memory leaks (Which I probably have tons of)

    void Load(const char* _filePath); // Loads audio file
    void Play(); // Play loaded audio file
    void Pause(); // Pause audio
private:
    SDL_AudioSpec wavSpec; // IDK
    Uint32 wavLength; // Length of audio clip
    Uint8* wavBuffer; // Next peice of audio to play
    SDL_AudioDeviceID deviceId; // IDK

    bool playing = false; // True if playing audio
};