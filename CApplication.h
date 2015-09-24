#ifndef CAPPLICATION_H
#define CAPPLICATION_H


#include <SDL_image.h>
#include <iostream>
#include <string>
#include "TextureManager.h"
#include <SDL_ttf.h>
#include <fstream>
#include "Character.h"
#include "Audio.h"


class CApplication
{
private:


public:
	float SCREEN_WIDTH = 1920;
	float SCREEN_HEIGHT = 1080;
	float  LEVEL_WIDTH = 256000;
	float  LEVEL_HEIGHT = 128000;

	void loadAudio(bool &test);

	

	TTF_Font *menuTitleFont = NULL;
	SDL_Window *window = NULL;
	SDL_Renderer* renderer = NULL;

	bool init();
	bool loadMedia();
	void loadTiles();
	void loadProjectiles();

	CApplication();


	SDL_Texture* loadTexture(std::string path);
	void close();
	void run();
};

extern CApplication application;
#endif