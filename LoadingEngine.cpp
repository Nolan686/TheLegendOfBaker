#include "LoadingEngine.h"

LoadingEngine load;


LoadingEngine::LoadingEngine()
{





}




void LoadingEngine::handleLoading(bool &quit)
{

	SDL_Thread* loadWorldThread = SDL_CreateThread(loadingThreadFunction, "loadingWorldThread", (void*)quit);




}



int LoadingEngine::loadingThreadFunction(void* data)
{

	




	return 0;

}

