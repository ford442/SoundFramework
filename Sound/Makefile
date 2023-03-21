b3_openal:
	em++ src/Main.cpp -c -std=c++2b -fno-math-errno -O0 -Ilibsndfile/include -Iopenal-soft/include
	em++ src/SoundBuffer.cpp -c -std=c++2b -O0 -Ilibsndfile/include -Iopenal-soft/include
	em++ src/SoundDevice.cpp -c -std=c++2b -O0 -Ilibsndfile/include -Iopenal-soft/include
	em++ src/SoundSource.cpp -c -std=c++2b -O0 -Ilibsndfile/include -Iopenal-soft/include
	emcc Main.o SoundDevice.o SoundSource.o SoundBuffer.o -Ilibsndfile/include -Iopenal-soft/include -o al001.html -lopenal -std=c++2b -O0 \
	-sFORCE_FILESYSTEM=1 -sALLOW_MEMORY_GROWTH=0 -sINITIAL_MEMORY=2048mb
  
all: b3_openal
	echo 'Built 1ink.us OpenAL.'
