#include "NPC.h"

NPC npc[29];

NPC npcObj;

NPC::NPC()
{
	for (int z = 0; z < 29; z++)
	{
		npc[z].posX = 486 + (z * 2 + 40);
		npc[z].posY = 0;

		npc[z].velX = 0;
		npc[z].velY = npc[z].velXMod;

	}


}


void NPC::enemy_logic()
{


}

void NPC::setposX(int x)
{
	posX = x;
}

void NPC::setposY(int y)
{
	posY = y;
}


void NPC::npc_move(float timeStep)
{
	for (int z = 0; z < 29; z++)
	{

		npc[z].atleastOneCollision = false;
		npc[z].inRange = false;
		npc[z].inRangeX = false;
		npc[z].collision = false;

		if (npc[z].moveNPC == true)
		{
			npc[z].posY += npc[z].velY * timeStep;
		}

		if (npc[z].posY >= application.LEVEL_HEIGHT - CHARACTER_HEIGHT)
		{
			npc[z].posY = application.LEVEL_HEIGHT - CHARACTER_HEIGHT;
			npc[z].onGround = true;
		}


		if (npc[z].posY < 0)
		{
			npc[z].posY = 0;
		}

		if (npc[z].moveNPC == true && npc[z].renderNPC == true)
		{
			if (npc[z].posX + npc[z].CHARACTER_WIDTH > player.player_getposX() - 10 && npc[z].posX < player.player_getposX() + player.CHARACTER_WIDTH - 8)
			{


				if (npc[z].velX > 0)
				{
					npc[z].velX = 0;
					npc[z].lastRight = true;
					npc[z].lastLeft = false;
				}

				if (npc[z].velX < 0)
				{
					npc[z].velX = 0;
					npc[z].lastLeft = true;
					npc[z].lastRight = false;
				}

			}
			else
			{

				npc[z].lastRight = false;

				npc[z].lastLeft = false;
			}
		}

		npc[z].gridXL = floor(npc[z].posX / 16);
		npc[z].gridYL = floor(npc[z].posY / 16);

		if (npc[z].gridYL < 10)
		{
			npc[z].gridYL = 10;
		}
		if (npc[z].gridYL > 6494)
		{
			npc[z].gridYL = 6494;
		}
		if (npc[z].gridXL < 8)
		{
			npc[z].gridXL = 8;
		}
		if (npc[z].gridXL > 6494)
		{
			npc[z].gridXL = 6494;
		}



		for (int x = npc[z].gridYL - 10; x < npc[z].gridYL + 15; x++)
		{

			for (int i = npc[z].gridXL - 8; i < npc[z].gridXL + 15; i++)
			{

				bool toTheLeft = false;
				bool toTheRight = false;
				bool above = false;
				bool under = false;
				if (world.grid[x][i].render > 0)
				{

					npc[z].atleastOneRender = true;
					if (npc[z].posX + CHARACTER_WIDTH < world.grid[x][i].x)
					{
						toTheLeft = true;

					}
					if (npc[z].posX > world.grid[x][i].x + world.grid[x][i].width)
					{
						toTheRight = true;
					}
					if (npc[z].posY + CHARACTER_HEIGHT < world.grid[x][i].y)
					{

						above = true;

					}
					if (npc[z].posY > world.grid[x][i].y + world.grid[x][i].height)
					{
						under = true;
					}


					if (npc[z].atleastOneRender == true)
					{

						if (npc[z].posY >= world.grid[x][i].y - CHARACTER_HEIGHT - 1 && npc[z].posY <= world.grid[x][i].y - CHARACTER_HEIGHT && npc[z].posX + CHARACTER_WIDTH > world.grid[x][i].x && npc[z].posX < world.grid[x][i].x + world.grid[x][i].width)
						{
							npc[z].inRange = true;
						}

						if (toTheLeft == false && toTheRight == false && above == false && under == false)
						{

							if (npc[z].velY < 0)
							{

								npc[z].posY = world.grid[x][i].y + world.grid[x][i].height + 1;
								npc[z].velY = -npc[z].velY / 3;

							}
							else
							{

								npc[z].velY = 0;
								npc[z].atleastOneCollision = true;

								//Minus one because if not it triggers x and y collision because its = to being just inside the block
								npc[z].posY = world.grid[x][i].y - CHARACTER_HEIGHT - 1;





							}

						}

					}

				}

			}

		}

		if (npc[z].atleastOneCollision == false)
		{
			npc[z].onGround = false;

		}
		if (npc[z].atleastOneCollision == true)
		{
			npc[z].onGround = true;
		}





		if (npc[z].atleastOneCollision == false && npc[z].inRange == false)
		{

			if (npc[z].velY <= 1500)
			{
				npc[z].velY += npc[z].gravity * timeStep;
			}
		}


		if (npc[z].moveNPC == true)
		{
			npc[z].posX += npc[z].velX * timeStep;
		}

		if (npc[z].posX < 0)
		{
			npc[z].posX = 0;
		}

		if (npc[z].posX >= application.LEVEL_WIDTH - CHARACTER_WIDTH)
		{
			npc[z].posX = application.LEVEL_WIDTH - CHARACTER_WIDTH;
		}


		npc[z].gridXL = floor(npc[z].posX / 16);
		npc[z].gridYL = floor(npc[z].posY / 16);



		if (npc[z].gridYL < 10)
		{
			npc[z].gridYL = 10;
		}
		if (npc[z].gridYL > 6494)
		{
			npc[z].gridYL = 6494;
		}
		if (npc[z].gridXL < 8)
		{
			npc[z].gridXL = 8;
		}
		if (npc[z].gridXL > 6494)
		{
			npc[z].gridXL = 6494;
		}



		for (int x = npc[z].gridYL - 10; x < npc[z].gridYL + 15; x++)
		{

			for (int i = npc[z].gridXL - 8; i < npc[z].gridXL + 15; i++)
			{
				bool toTheLeft = false;
				bool toTheRight = false;
				bool above = false;
				bool under = false;

				if (world.grid[x][i].render > 0)
				{
					npc[z].atleastOneRender = true;
					if (npc[z].posX + CHARACTER_WIDTH < world.grid[x][i].x)
					{
						toTheLeft = true;

					}
					if (npc[z].posX > world.grid[x][i].x + world.grid[x][i].width)
					{
						toTheRight = true;
					}
					if (npc[z].posY + CHARACTER_HEIGHT < world.grid[x][i].y)
					{
						above = true;
					}
					if (npc[z].posY > world.grid[x][i].y + world.grid[x][i].height)
					{
						under = true;
					}

					if (npc[z].atleastOneRender == true)
					{
						if (npc[z].posX + CHARACTER_WIDTH > world.grid[x][i].x - 1 && npc[z].posX < world.grid[x][i].x + world.grid[x][i].width + 1 && npc[z].posY >= world.grid[x][i].y - CHARACTER_HEIGHT - 1 && npc[z].posY <= world.grid[x][i].y - CHARACTER_HEIGHT)
						{
							inRangeX = true;
						}

						if (toTheLeft == false && toTheRight == false && above == false && under == false)
						{
							npc[z].collision = true;
							if (npc[z].velX > 0)
							{

								npc[z].posX = world.grid[x][i].x - CHARACTER_WIDTH - 1;


							}
							if (npc[z].velX < 0)
							{

								npc[z].posX = world.grid[x][i].x + world.grid[x][i].width + .5;
							}

						}

					}
				}

			}
		}


		if (npc[z].velX > 0)
		{
			npc[z].right = true;
		}
		else
		{
			npc[z].right = false;
		}
		if (npc[z].velX < 0)
		{
			npc[z].left = true;
		}
		else
		{
			npc[z].left = false;
		}
	}
}

void NPC::checkDamage()
{



}


void NPC::render_npc(float timerAdjust)
{




}


float NPC::getposX()
{
	return posX;
}

float NPC::getposY()
{
	return posY;
}