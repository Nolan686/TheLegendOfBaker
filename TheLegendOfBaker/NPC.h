#ifndef NPC_H
#define NPC_H

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

class NPC
{

public:

	NPC();


	float  getposY();
	float  getposX();

	void setposX(int x);
	void setposY(int y);

	void enemy_logic();

	bool officersArrived = false;

	void npc_move(float timeStep);
	void render_npc(float timerAdjust);

	float  CHARACTER_HEIGHT = 156;
	float  CHARACTER_WIDTH = 56;

	void checkDamage();

	bool renderNPC = false;
	bool moveNPC = false;

private:

	int NPC_HEALTH = 100;

	bool right = false;
	bool left = false;

	bool inRangeX = false;

	int characterAnimationFrames = 8;



	double currentCharacterFrame = 0;



	bool lastLeft = false;
	bool lastRight = false;

	bool collideRight = false;
	bool collideLeft = false;

	bool collision = false;

	float currentNPCFrame = 0;
	float currentNPCFrameLeft = 0;

	bool onGround = true;

	bool atleastOneCollision;

	bool inRange = false;

	float  posX;
	float  posY;

	float  velX = 0;
	float  velY;

	bool atleastOneRender = false;



	int gridXL = floor(posX / 16);
	int gridYL = floor(posY / 16);

	float gravity = 1100;
	float velXMod = 200;
	float  velYMod = 650;

};

extern NPC npcObj;
extern NPC npc[29];

#endif