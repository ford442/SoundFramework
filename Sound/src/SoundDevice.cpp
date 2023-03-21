#include "SoundDevice.h"

SoundDevice::SoundDevice(){
m_Device=alcOpenDevice(nullptr);
m_Context=alcCreateContext(m_Device, nullptr);
alcMakeContextCurrent(m_Context);
const ALCchar* name=nullptr;
}

SoundDevice::~SoundDevice(){
if(!alcMakeContextCurrent(nullptr))
DisplayALCError("Error Unbinding Current Context",alcGetError(m_Device));
alcDestroyContext(m_Context);
DisplayALCError("Error Destroying Context",alcGetError(m_Device));
alcCloseDevice(m_Device);
}
