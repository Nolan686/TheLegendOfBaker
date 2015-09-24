#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include "Animation.h"

#include "CApplication.h"

class TextureManager
{
private:
	SDL_Texture *texture;

	int tWidth;
	int tHeight;

public:
	TextureManager(int width, int height);
	~TextureManager();
	TextureManager();

	SDL_Window *window;
	SDL_Renderer *renderer;

	bool loadFromFile(std::string path);
	void renderCamera(int x, int y, SDL_Rect clip);

	void render(float x, float y);
	void renderAnimation(int x, int y, SDL_Rect* clip);

	//Alpha blenderingo
	void setAlpha(Uint8 alpha);
	void setBlendMode(SDL_BlendMode blending);

	int getWidth();
	int getHeight();

	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);






	void free();
};

extern TextureManager projectile;
extern TextureManager playerStandRight;
extern TextureManager mapTexture;
extern TextureManager tileTexture;
extern TextureManager stoneTile;
extern TextureManager blankTile;

#endif