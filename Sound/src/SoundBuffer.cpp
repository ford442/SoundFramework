#include "SoundBuffer.h"

SoundBuffer::SoundBuffer(const char* audioFilename){
ALenum err,format;
SNDFILE* soundEffect;
SF_INFO sfinfo;
short* membuf;
sf_count_t num_frames;
ALsizei num_bytes;
soundEffect = sf_open(audioFilename, SFM_READ, &sfinfo);
if (!soundEffect){
std::cout << "Could not open audio file: " << audioFilename << std::endl;
}
if (sfinfo.frames < 1 || sfinfo.frames >(sf_count_t)(INT_MAX / sizeof(short)) / sfinfo.channels){
std::cout << "Audio file: " << audioFilename << " : produced invalid data" << std::endl;
sf_close(soundEffect);
}
format = AL_NONE;
if (sfinfo.channels == 1)format = AL_FORMAT_MONO16;
else if (sfinfo.channels == 2)format = AL_FORMAT_STEREO16;
else if (sfinfo.channels == 3){
if (sf_command(soundEffect, SFC_WAVEX_GET_AMBISONIC, nullptr, 0) == SF_AMBISONIC_B_FORMAT)
format = AL_FORMAT_BFORMAT2D_16; // 2d
}else if (sfinfo.channels == 4){
if (sf_command(soundEffect, SFC_WAVEX_GET_AMBISONIC, nullptr, 0) == SF_AMBISONIC_B_FORMAT)
format = AL_FORMAT_BFORMAT3D_16; // 3d
}
if (!format){
std::cout << "Unsuported channel count/format: " << audioFilename << std::endl;
sf_close(soundEffect);
}
membuf = static_cast<short*>(malloc((size_t)(sfinfo.frames * sfinfo.channels) * sizeof(short)));
num_frames = sf_readf_short(soundEffect, membuf, sfinfo.frames);
if (num_frames < 1){
free(membuf);
sf_close(soundEffect);
std::cout << "Failed to read samples in audio file: " << audioFilename << std::endl;
}
num_bytes = (ALsizei)(num_frames * sfinfo.channels) * (ALsizei)sizeof(short);
alGenBuffers(1, &m_ID);
alBufferData(m_ID, format, membuf, num_bytes, sfinfo.samplerate);
free(membuf);
sf_close(soundEffect);
while (err = alGetError()){
//  DisplayALError("AL Error in " __FUNCTION__ ": ", err);  // throws error __FUNCTION__ non-existant
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
