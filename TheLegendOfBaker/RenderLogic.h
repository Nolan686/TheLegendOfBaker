#include "World.h"
#include "TextureManager.h"
#include "Character.h"
#include <SDL_mixer.h>
#include "NPC.h"
#include <vector>
#include <cmath>
#include "Projectile.h"


#ifndef RENDERLOGIC_H
#define RENDERLOGIC_H




class RenderLogic
{

public:

	RenderLogic();

	void handle_rendering(float timer);
	void introRendering();

	int projNum = 0;


};

extern RenderLogic render;

#endif