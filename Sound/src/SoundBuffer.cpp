#include "SoundBuffer.h"

SoundBuffer::SoundBuffer(const char* audioFilename){
ALenum err,format;
SNDFILE* soundEffect;
SF_INFO sfinfo;
short* membuf;
sf_count_t num_frames;
ALsizei num_bytes;
soundEffect = sf_open(audioFilename, SFM_READ, &sfinfo);
format = AL_FORMAT_STEREO16;
membuf = static_cast<short*>(malloc((size_t)(sfinfo.frames * sfinfo.channels) * sizeof(short)));
num_frames = sf_readf_short(soundEffect, membuf, sfinfo.frames);
num_bytes = (ALsizei)(num_frames * 2) * (ALsizei)sizeof(short);
alGenBuffers(1, &m_ID);
alBufferData(m_ID, format, membuf, num_bytes, sfinfo.samplerate);
free(membuf);
sf_close(soundEffect);
while (err = alGetError()){
alDeleteBuffers(1, &m_ID);
}
std::cout << "Loaded audio file :'" << audioFilename << "' with ID (" << m_ID << ')' << std::endl;
}

SoundBuffer::~SoundBuffer(){
alDeleteBuffers(1, &m_ID);
DisplayALError("Error Destroying Sound Buffer", alGetError());
}

ALuint SoundBuffer::GetID(){
return m_ID;
}
