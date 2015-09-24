#ifndef WORLD_H
#define WORLD_H
#include <SDL.h>

#include <iostream>
#include "TextureManager.h"
#include "Character.h"
#include <math.h>
#include <vector>
#include "NPC.h"



class World
{

public:


	int gridSize = 16;


	struct tile
	{
		float x;
		float y;
		float width;
		float height;
		short render;
	};


	float  incrementorX = 0.0;
	float  incrementorY = 0.0;
	bool atLeastOneRendered = false;
	


	int currentTile = 2;

	int eraseTileVal = 0;
	int dirtTileVal = 1;
	int stoneTileVal = 2;
	int blankTileVal = 3;

	World();
	tile grid[1000][500];

	void set_Grid();
	void handle_input(SDL_Event event);
	void set_tile(float  x, float  y, int *grid1, int *grid2);
	void render_tile();
	void delete_tile(float  x, float  y, int *grid1, int *grid2);
	void fill_rect(float  x, float  y, int x2, int y2, bool render);

	bool mouseHoldDown = false;


private:
	float  mouseX;
	float  mouseY;
	int count = 0;

	int delGridX;
	int delGridY;


	bool erase = false;

	int xGridF = 0;
	int yGridF = 0;


};

extern World world;

#endif