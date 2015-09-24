#include "TextureManager.h"

TextureManager mapTexture(1920, 1080);
TextureManager tileTexture(16, 16);
TextureManager stoneTile(16, 16);
TextureManager blankTile(16, 16);
TextureManager playerStandRight(105, 195);
TextureManager projectile(30, 30);

TextureManager::TextureManager(int width, int height)
{
	texture = NULL;
	tWidth = width;
	tHeight = height;
}

TextureManager::TextureManager()
{
	texture = NULL;
	tWidth = 0;
	tHeight = 0;
}

TextureManager::~TextureManager()
{
	free();
}

bool TextureManager::loadFromFile(std::string path)
{
	free();

	SDL_Texture *newTexture = NULL;
	SDL_Surface *loadedSurface = NULL;

	loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		std::cout << path.c_str() << std::endl;
		std::cout << "wat" << loadedSurface << std::endl;
		std::cout << "Unable to load image " << path.c_str() << " SDL_image error " << IMG_GetError() << std::endl;
		getchar();
	}
	else
	{

		newTexture = SDL_CreateTextureFromSurface(application.renderer, loadedSurface);

		if (newTexture == NULL)
		{
			std::cout << "Unable to create texture from " << path.c_str() << std::endl;
			getchar();
		}
		else
		{
			//tWidth = loadedSurface->w;
			//tHeight = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	texture = newTexture;
	return texture != NULL;
}

bool TextureManager::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	//free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(application.menuTitleFont, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render menu text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(application.renderer, textSurface);
		if (texture == NULL)
		{
			printf("Unable to create Texture from the rendered Text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			tWidth = textSurface->w;
			tHeight = textSurface->h;
		}

		SDL_FreeSurface(textSurface);
	}


	return texture != NULL;
}

void TextureManager::render(float x, float  y)
{
	SDL_Rect renderQuad = { x, y, tWidth, tHeight };

	SDL_RenderCopyEx(application.renderer, texture, NULL, &renderQuad, NULL, NULL, SDL_FLIP_NONE);

}

void TextureManager::renderCamera(int x, int y, SDL_Rect clip)
{

	SDL_Rect renderQuad = { 0, 0, application.SCREEN_WIDTH, application.SCREEN_HEIGHT };

	SDL_RenderCopyEx(application.renderer, texture, &clip, &renderQuad, NULL, NULL, SDL_FLIP_NONE);

}

void TextureManager::renderAnimation(int x, int y, SDL_Rect* clip)
{

	SDL_Rect renderQuad = { x, y, clip->w, clip->h };


	SDL_RenderCopyEx(application.renderer, texture, clip, &renderQuad, NULL, NULL, SDL_FLIP_NONE);

}


int TextureManager::getWidth()
{
	return tWidth;
}
int TextureManager::getHeight()
{
	return tHeight;
}

void TextureManager::free()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		tWidth = 0;
		tHeight = 0;
	}
}



void TextureManager::setBlendMode(SDL_BlendMode blending)
{

	SDL_SetTextureBlendMode(texture, blending);
}

void TextureManager::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(texture, alpha);
}