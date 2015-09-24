#include "CApplication.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_thread.h>



CApplication application;

CApplication::CApplication()
{

}

void CApplication::run()
{

	if (!init())
	{
		std::cout << "INIT DUN FUCKLED" << std::endl;
	}
	if (!loadMedia())
	{
		std::cout << "I have autism, loadmedia error" << std::endl;
	}


}

bool CApplication::loadMedia()
{
	bool success = true;

	if (!(mapTexture.loadFromFile("world.png")))
	{
		std::cout << "Failed to load del world texture" << std::endl;
	}
	else
	{
		mapTexture.setBlendMode(SDL_BLENDMODE_BLEND);
	}

	if (!(playerStandRight.loadFromFile("playerStandRight.png")))
	{
		std::cout << "Failed to load player standing right texture!!!" << std::endl;
	}
	else
	{
		playerStandRight.setBlendMode(SDL_BLENDMODE_BLEND);
	}


	loadTiles();

	loadProjectiles();

	world.set_Grid(); 

	loadAudio(success);

	player.set_player_data();

	return success;
}

void CApplication::loadProjectiles()
{

	if (!(projectile.loadFromFile("projectile.png")))
	{
		std::cout << "Failed to load projectile texture" << std::endl;
	}
	else
	{
		projectile.setBlendMode(SDL_BLENDMODE_BLEND);
	}



}

bool CApplication::init()
{

	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		std::cout << "SDL could not initialize" << std::endl;
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			std::cout << "Warning: linear texture filtering not enabled!" << std::endl;
			getchar();
		}
		int setWidth;
		int setHeight;
		std::cout << "ENTER SCREEN WIDTH: ";
		//std::cin >> setWidth;
		std::cout << "ENTER SCREEN HEIGHT: ";
		//std::cin >> setHeight;

		SCREEN_WIDTH = 1920;
		SCREEN_HEIGHT = 1080;

		window = SDL_CreateWindow("RPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			std::cout << "Window could not be created!" << std::endl;
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			if (renderer == NULL)
			{
				std::cout << "Renderer could not be created" << std::endl;
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cout << "SDL Image could not initialize!" << std::endl;
					success = false;
				}

				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success == false;
				}

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					std::cout << "SDL_mixer coult not initialize! SDL_mixer Error: %s\n" << std::endl;
					success = false;
				}

			}
		}
	}
	return success;
}

void CApplication::loadAudio(bool &test)
{
	audio.introMusic = Mix_LoadMUS("IntroMusic.mp3");

	if (audio.introMusic == NULL)
	{
		printf("Failed to load intro music! SDL_mixer Error: %s\n", Mix_GetError());
		test = false;
	}

	audio.loadingScreenMusic = Mix_LoadMUS("LoadingMusic.mp3");

	if (audio.loadingScreenMusic == NULL)
	{
		printf("Failed to load loadingScreen music! SDL_mixer Error: %s\n", Mix_GetError());
		test = false;
	}

	audio.loadingScreen2Music = Mix_LoadMUS("Loading2Music.wav");

	if (audio.loadingScreen2Music == NULL)
	{
		printf("Failed to load loadingScreen2 music! SDL_mixer Error: %s\n", Mix_GetError());
		test = false;
	}

	audio.loadingScreen3Music = Mix_LoadMUS("Loading3Music.wav");

	if (audio.loadingScreen3Music == NULL)
	{
		printf("Failed to load loadingScreen3 music! SDL_mixer Error: %s\n", Mix_GetError());
		test = false;
	}
}

void CApplication::loadTiles()
{

	if (!(tileTexture.loadFromFile("tile.png")))
	{
		std::cout << "Failed to load del tile texture" << std::endl;
	}
	else
	{
		tileTexture.setBlendMode(SDL_BLENDMODE_BLEND);
	}


	if (!(stoneTile.loadFromFile("stoneTile3.png")))
	{
		std::cout << "Failed to load the stone tile texture!" << std::endl;

	}
	else
	{
		stoneTile.setBlendMode(SDL_BLENDMODE_BLEND);
	}

	if (!(blankTile.loadFromFile("blankTile.png")))
	{
		std::cout << "Failed to laod the blank Tile" << std::endl;
	}


}



void CApplication::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	TTF_CloseFont(menuTitleFont);

	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

}