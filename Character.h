#ifndef CHARACTER_H
#define CHARACTER_H
#include "TextureManager.h"
#include "CApplication.h"
#include <SDL.h>
#include <iostream>
#include <vector>
#include "World.h"
#include <cmath>
#include "RenderLogic.h"
#include <cmath>
#include <math.h>




class Character
{

public:

	Character();

	float  player_getposY();
	float  player_getposX();

	SDL_Rect playerCam;

	void player_input(SDL_Event event);
	void player_move(float timeStep);
	void render_player(float timerAdjust);
	void set_player_data();

	void handleWalking();

	float  velX = 0;
	float  velY;

	float gravity = 1100;
	float velXMod = 160;
	float  velYMod = 650;

	float  CHARACTER_HEIGHT = 156;
	float  CHARACTER_WIDTH = 56;

	bool right = false;
	bool left = false;

	bool walkRight = true;
	bool walkLeft = true;

	void set_posY(int y);
	void set_posX(int x);

	bool runLeft = false;
	bool runRight = false;

	int projNum = 0;

	bool doneSettingChunk = false;

	int currentChunkX;
	int currentChunkY;

	int highestChunk;
	int lowestChunk;

	int farRightChunk;
	int farLeftChunk;


private:

	int mouseX;
	int mouseY;


	bool rightPress = false;
	bool leftPress = false;


	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	float  posX;
	float  posY;



	double currentCharacterFrame = 0;
	double currentCharacterFrameLeft = 0;






	bool lastLeft = false;
	bool lastRight = false;






	int characterAnimationFrames = 8;



	bool collision = false;

	bool atleastOneRender = false;
	bool atleastOneCollision;

	bool onGround = true;
	bool inRange = false;
	bool inRiseBlock = false;

	int gridXL = floor(posX / 16);
	int gridYL = floor(posY / 16);








};

extern Character player;
#endif