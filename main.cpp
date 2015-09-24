#include <iostream>
#include "CApplication.h"
#include "TextureManager.h"
#include <SDL.h>
#include "Character.h"
#include "World.h"
#include "Timer.h"
#include <SDL_mixer.h>
#include "RenderLogic.h"
#include <SDL_ttf.h>
#include "NPC.h"
#include "Animation.h"
#include "Projectile.h"
#include "LoadingEngine.h"




const int SCREEN_WIDTH = 1152;
const int SCREEN_HEIGHT = 864;
const int SCREEN_FPS = 110;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


SDL_Event event;

int main(int argc, char* args[])
{

	

	bool quit = false;
	
	application.run();

	Timer fpsTimer;

	Timer capTimer;

	int countedFrames = 0;
	fpsTimer.start();
	load.handleLoading(quit);
	while (quit == false)
	{

		capTimer.start();
		while (SDL_PollEvent(&event))
		{

			player.player_input(event);

			world.handle_input(event);
			
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}

			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
			}

		}


		float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);

		if (avgFPS > 2000000)
		{
			avgFPS = 0;
		}

		float Timestep = timer.getTicks() / 1000.f;

		
		player.player_move(Timestep);
		npcObj.npc_move(Timestep);
		projectileObj.projectile_move(Timestep);



		timer.start();


		render.handle_rendering(Timestep);

		++countedFrames;

		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}

	}

	
	application.close();
	return 0;
}