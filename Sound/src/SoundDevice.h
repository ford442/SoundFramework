#pragma once

#include <iostream>

#include <AL/al.h>
#include <AL/alc.h>

void DisplayALError(const char* msg,ALenum error);
void DisplayALCError(const char* msg,ALCenum error);

class SoundDevice{
public:
SoundDevice();
~SoundDevice();

private:
ALCdevice* m_Device=nullptr;
ALCcontext* m_Context=nullptr;
};
