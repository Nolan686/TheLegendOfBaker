#include "World.h"


World world;


World::World()
{



}



void World::set_Grid()
{

	for (int x = 0; x < 6509; x++)
	{
		incrementorX = 0;
		for (int i = 0; i < 6509; i++)
		{

			grid[x][i].x = incrementorX;
			grid[x][i].y = incrementorY;
			grid[x][i].width = gridSize;
			grid[x][i].height = gridSize;

			if (x > 50)
			{
				grid[x][i].render = stoneTileVal;
			}
			else
			{
				grid[x][i].render = eraseTileVal;
			}

			incrementorX += 16.0;

		}
		incrementorY += 16.0;
	}


}


void World::handle_input(SDL_Event event)
{
	mouseX = 0;
	mouseY = 0;



	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		mouseHoldDown = true;

	}


	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{


		case SDLK_0:
			currentTile = eraseTileVal;
			break;

		case SDLK_1:
			currentTile = dirtTileVal;

			break;

		case SDLK_2:
			currentTile = stoneTileVal;
			break;

		case SDLK_3:
			currentTile = blankTileVal;
			break;

		}
	}





	if (event.type == SDL_MOUSEBUTTONUP)
	{
		mouseHoldDown = false;



		if (event.button.button == SDL_BUTTON_RIGHT)
		{
			mouseX = event.button.x;
			mouseY = event.button.y;
			erase = true;

			fill_rect(mouseX, mouseY, xGridF, yGridF, erase);


		}

	}




	if (mouseHoldDown == true)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			mouseX = event.button.x;
			mouseY = event.button.y;




			set_tile(mouseX, mouseY, &xGridF, &yGridF);


		}
		if (event.button.button == SDL_BUTTON_RIGHT)
		{
			mouseX = event.button.x;
			mouseY = event.button.y;

			delete_tile(mouseX, mouseY, &xGridF, &yGridF);

		}
	}

}

void World::fill_rect(float  x, float  y, int gridXF, int gridYF, bool render)
{




	float mouseCordX = x + player.playerCam.x;
	float mouseCordY = y + player.playerCam.y;


	int gridXL = floor(mouseCordX / 16);
	int gridYL = floor(mouseCordY / 16);


	int yDiff = gridYL - gridYF;
	int xDiff = gridXL - gridXF;



	for (int x = gridYF; x <= gridYF + yDiff; x++)
	{
		for (int i = gridXF; i <= gridXF + xDiff; i++)
		{
			if (erase == false)
			{

				grid[x][i].render = currentTile;

			}
			if (erase == true)
			{
				grid[x][i].render = currentTile;
			}


		}
	}

}

void World::set_tile(float x, float y, int *grid1, int *grid2)
{

	float  mouseCordX = x + player.playerCam.x;
	float  mouseCordY = y + player.playerCam.y;

	int gridX = floor(mouseCordX / 16);
	int gridY = floor(mouseCordY / 16);

	gridX = gridX - (player.farLeftChunk * 120);
	gridY = gridY - (player.highestChunk * 120);
	*grid2 = gridY;
	*grid1 = gridX;

	//std::cout << "GridX: " << gridX << std::endl;
	//std::cout << "GridY: " << gridY << std::endl;


	grid[gridY][gridX].render = currentTile;

	



}

void World::delete_tile(float x, float y, int *grid1, int *grid2)
{

	float  mouseCordX = x + player.playerCam.x;
	float  mouseCordY = y + player.playerCam.y;

	int gridX = floor(mouseCordX / 16);
	int gridY = floor(mouseCordY / 16);
	*grid2 = gridY;
	*grid1 = gridX;


	grid[gridY][gridX].render = currentTile;




}



void World::render_tile()
{

	delGridX = floor(player.playerCam.x / 16);
	delGridY = floor(player.playerCam.y / 16);


	delGridX = delGridX - (player.farLeftChunk * 120);
	delGridY = delGridY - (player.highestChunk * 120);



	if (delGridY < 10)
	{
		delGridY = 10;
	}

	if (delGridY > 6500)
	{
		delGridY = 6500;
	}

	if (delGridX < 10)
	{
		delGridX = 10;
	}
	if (delGridX > 6500)
	{
		delGridX = 6500;
	}



	for (int x = delGridY - 10; x < delGridY + 78; x++)
	{

		for (int i = delGridX - 10; i < delGridX + 140; i++)
		{
			if (grid[x][i].render == dirtTileVal)
			{
				
				tileTexture.render(grid[x][i].x - player.playerCam.x, grid[x][i].y - player.playerCam.y);
			}
			
			if (grid[x][i].render == stoneTileVal)
			{
				
				stoneTile.render(grid[x][i].x - player.playerCam.x, grid[x][i].y - player.playerCam.y);
			}
			if (grid[x][i].render == blankTileVal)
			{
				blankTile.render(grid[x][i].x - player.playerCam.x, grid[x][i].y - player.playerCam.y);
			}

		}
	}

}