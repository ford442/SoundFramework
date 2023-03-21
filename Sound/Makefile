b3_openal:
	em++ src/Main.cpp -c -std=c++2b -fno-math-errno -O0 -lopenal
	em++ src/SoundBuffer.cpp -c -std=c++2b -sUSE_SDL=2 -O0 -lopenal
	em++ src/SoundDevice.cpp -c -std=c++2b -sUSE_SDL=2 -O0 -lopenal
	emcc src/SoundSource.cpp -c -std=c++2b -sUSE_SDL=2 -O0 -lopenal
	emcc Main.o SoundBuffer.o SoundDevice.o SoundSource.o -o al001.html -lopenal -std=c++2b -O0 \
	-sUSE_SDL=2 -sFORCE_FILESYSTEM=1 -sALLOW_MEMORY_GROWTH=0 -sINITIAL_MEMORY=2048mb
  
  
all: b3_openal
	echo 'Built 1ink.us OpenAL.'
