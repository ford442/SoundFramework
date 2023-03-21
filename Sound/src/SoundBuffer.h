#pragma once

#include <vector>
#include <iostream>
#include <AL/al.h>
#include <AL/alc.h>
#include "/content/RAMDRIVE2/SoundFramework/Sound/libsndfile/include/sndfile.hh"
#include <inttypes.h>
#include </content/RAMDRIVE2/SoundFramework/Sound/openal-soft/include/AL/alext.h>

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
