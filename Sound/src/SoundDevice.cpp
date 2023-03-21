#include "SoundDevice.h"

SoundDevice::SoundDevice()
{
   // open default device
   m_Device = alcOpenDevice(nullptr);
 //  if (!m_Device) // verify success

   // create new context
   m_Context = alcCreateContext(m_Device, nullptr);
 //  if (!m_Context)   // verify success

   // make context current
  alcMakeContextCurrent(m_Context);   const ALCchar* name = nullptr;
/* 
   if (alcIsExtensionPresent(m_Device, "ALC_ENUMERATE_ALL_EXT"))
      name = alcGetString(m_Device, ALC_ALL_DEVICES_SPECIFIER);
   else

   if (!name || !alcGetError(m_Device))
      name = alcGetString(m_Device, ALC_DEVICE_SPECIFIER);

 std::cout << "Opened Device: " << name << std::endl; 
 */
}

SoundDevice::~SoundDevice()
{
   // clear current context
   if (!alcMakeContextCurrent(nullptr))
   DisplayALCError("Error Unbinding Current Context", alcGetError(m_Device));

   // destroy context
   alcDestroyContext(m_Context);
   DisplayALCError("Error Destroying Context", alcGetError(m_Device));

   // close active device
   alcCloseDevice(m_Device);
}
