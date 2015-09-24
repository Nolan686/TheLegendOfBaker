#ifndef PROJECTILE_H
#define PROJECTILE_H


#include <cmath>
#include <SDL.h>
#include "TextureManager.h"
#include "CApplication.h"
#include <SDL.h>
#include <iostream>
#include <vector>
#include "World.h"
#include <cmath>

#include "Character.h"



class Projectile
{
public:

	Projectile();


	void projectile_move(float timeStep);
	void render_projectile(float timerAdjust);

	void projectileLogic();

	void throwProjectile(float mX, float mY, int num);

	float getposX();
	float getposY();

	float velX = 0;
	float velY = 0;

	bool inRangeX = false;

	bool onGround = true;

	bool atleastOneCollision;

	bool inRange = false;

	bool renderProjectile = false;

	bool collision = false;



	bool atleastOneRender = false;

	float  CHARACTER_HEIGHT = 30;
	float  CHARACTER_WIDTH = 30;

	int gridXL = floor(posX / 16);
	int gridYL = floor(posY / 16);


private:


	float posX;
	float posY;


};

extern Projectile projectileObj;
extern Projectile projectArray[30];

#endif