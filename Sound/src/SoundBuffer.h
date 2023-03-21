#pragma once

#include <vector>
#include <iostream>

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

#include <sndfile.h>
#include <inttypes.h>

void DisplayALError(const char* msg,ALenum error);
void DisplayALCError(const char* msg,ALCenum error);

class SoundBuffer{
public:
SoundBuffer(const char* audioFilename);
~SoundBuffer();
ALuint GetID();

private:
ALuint m_ID = 0;
};
