#ifndef LOADINGENGINE_H
#define LOADINGENGINE_H

#include <SDL.h>
#include <SDL_thread.h>
#include "CApplication.h"
#include "World.h"
#include <fstream>

#include "Character.h"



class LoadingEngine
{


public:

	LoadingEngine();

	static int loadingThreadFunction(void* data);


	void handleLoading(bool &quit);




private:







};



extern LoadingEngine load;


#endif