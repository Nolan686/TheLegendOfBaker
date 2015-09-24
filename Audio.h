#ifndef AUDIO_H
#define AUDIO_H

#include <SDL_mixer.h>

class Audio
{

public:

	Mix_Music *introMusic = NULL;
	Mix_Music *loadingScreenMusic = NULL;
	Mix_Music *loadingScreen2Music = NULL;
	Mix_Music *loadingScreen3Music = NULL;


	Audio();

private:





};

extern Audio audio;
#endif