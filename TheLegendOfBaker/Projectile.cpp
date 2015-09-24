#include "Projectile.h"


Projectile projectileObj;

Projectile projectArray[30];

Projectile::Projectile()
{
	for (int q = 0; q < 30; q++)
	{
		projectArray[q].posX = 0;
		projectArray[q].posY = 0;
		projectArray[q].velX = 0;
		projectArray[q].velY = 0;
	}

}



float Projectile::getposX()
{
	return posX;
}

float Projectile::getposY()
{
	return posY;
}

void Projectile::projectile_move(float timeStep)
{

	for (int q = 0; q < 30; q++)
	{
		projectArray[q].atleastOneCollision = false;
		projectArray[q].inRange = false;
		projectArray[q].inRangeX = false;
		projectArray[q].collision = false;

		projectArray[q].posY += projectArray[q].velY * timeStep;




		if (projectArray[q].posY < 0)
		{
			projectArray[q].posY = 0;
		}


		projectArray[q].gridXL = floor(projectArray[q].posX / 16);
		projectArray[q].gridYL = floor(projectArray[q].posY / 16);

		if (projectArray[q].gridYL < 10)
		{
			projectArray[q].gridYL = 10;
		}
		if (projectArray[q].gridYL > 6494)
		{
			projectArray[q].gridYL = 6494;
		}
		if (projectArray[q].gridXL < 8)
		{
			projectArray[q].gridXL = 8;
		}
		if (projectArray[q].gridXL > 6494)
		{
			projectArray[q].gridXL = 6494;
		}


		for (int z = 0; z < 29; z++)
		{
			if (projectArray[q].renderProjectile == true && npc[z].renderNPC == true)
			{
				bool toTheLeft = false;
				bool toTheRight = false;
				bool above = false;
				bool under = false;
				if (projectArray[q].posX + projectArray[q].CHARACTER_WIDTH < npc[z].getposX())
				{
					toTheLeft = true;

				}

				if (projectArray[q].posX > npc[z].getposX() + npc[z].CHARACTER_WIDTH)
				{
					toTheRight = true;
				}

				if (projectArray[q].posY + projectArray[q].CHARACTER_HEIGHT < npc[z].getposY())
				{
					above = true;
				}

				if (projectArray[q].posY > npc[z].getposY() + npc[z].CHARACTER_HEIGHT)
				{
					under = true;
				}

				if (toTheLeft == false && toTheRight == false && above == false && under == false)
				{
					projectArray[q].renderProjectile = false;
					npc[z].renderNPC = false;
				}
			}
		}


		for (int x = projectArray[q].gridYL - 10; x < projectArray[q].gridYL + 15; x++)
		{

			for (int i = projectArray[q].gridXL - 8; i < projectArray[q].gridXL + 15; i++)
			{

				bool toTheLeft = false;
				bool toTheRight = false;
				bool above = false;
				bool under = false;
				if (world.grid[x][i].render > 0)
				{

					projectArray[q].atleastOneRender = true;
					if (projectArray[q].posX + 30 < world.grid[x][i].x)
					{
						toTheLeft = true;

					}
					if (projectArray[q].posX > world.grid[x][i].x + world.grid[x][i].width)
					{
						toTheRight = true;
					}
					if (projectArray[q].posY + 30 < world.grid[x][i].y)
					{

						above = true;

					}
					if (projectArray[q].posY > world.grid[x][i].y + world.grid[x][i].height)
					{
						under = true;
					}


					if (atleastOneRender == true)
					{

						if (projectArray[q].posY > world.grid[x][i].y - 30 && projectArray[q].posY < world.grid[x][i].y - 30 && projectArray[q].posX + 30 > world.grid[x][i].x && projectArray[q].posX < world.grid[x][i].x + world.grid[x][i].width)
						{
							projectArray[q].inRange = true;
						}

						if (toTheLeft == false && toTheRight == false && above == false && under == false)
						{
							//std::cout << "Projectile #: " << q << " just collided" << std::endl;
							projectArray[q].collision = true;
							if (projectArray[q].velY < 0)
							{

								projectArray[q].posY = world.grid[x][i].y + world.grid[x][i].height;
								projectArray[q].velX = 0;
								projectArray[q].velY = 0;


							}
							else
							{


								projectArray[q].atleastOneCollision = true;

								//Minus one because if not it triggers x and y collision because its = to being just inside the block
								projectArray[q].posY = world.grid[x][i].y - 30;


								projectArray[q].velX = 0;
								projectArray[q].velY = 0;


							}

						}

					}

				}

			}

		}










		projectArray[q].posX += projectArray[q].velX * timeStep;

		if (projectArray[q].posX < 0)
		{
			projectArray[q].posX = 0;
		}

		if (projectArray[q].posX >= application.LEVEL_WIDTH - 30)
		{
			projectArray[q].posX = application.LEVEL_WIDTH - 30;
		}


		projectArray[q].gridXL = floor(projectArray[q].posX / 16);
		projectArray[q].gridYL = floor(projectArray[q].posY / 16);



		if (projectArray[q].gridYL < 10)
		{
			projectArray[q].gridYL = 10;
		}
		if (projectArray[q].gridYL > 6494)
		{
			projectArray[q].gridYL = 6494;
		}
		if (projectArray[q].gridXL < 8)
		{
			projectArray[q].gridXL = 8;
		}
		if (projectArray[q].gridXL > 6494)
		{
			projectArray[q].gridXL = 6494;
		}



		for (int x = projectArray[q].gridYL - 10; x < projectArray[q].gridYL + 15; x++)
		{

			for (int i = projectArray[q].gridXL - 8; i < projectArray[q].gridXL + 15; i++)
			{
				bool toTheLeft = false;
				bool toTheRight = false;
				bool above = false;
				bool under = false;

				if (world.grid[x][i].render > 0)
				{
					projectArray[q].atleastOneRender = true;
					if (projectArray[q].posX + 30 < world.grid[x][i].x)
					{
						toTheLeft = true;

					}
					if (projectArray[q].posX > world.grid[x][i].x + world.grid[x][i].width)
					{
						toTheRight = true;
					}
					if (projectArray[q].posY + 30 < world.grid[x][i].y)
					{
						above = true;
					}
					if (projectArray[q].posY > world.grid[x][i].y + world.grid[x][i].height)
					{
						under = true;
					}

					if (projectArray[q].atleastOneRender == true)
					{
						if (projectArray[q].posX + projectArray[q].CHARACTER_WIDTH > world.grid[x][i].x - 1 && projectArray[q].posX < world.grid[x][i].x + world.grid[x][i].width + 1 && projectArray[q].posY > world.grid[x][i].y - projectArray[q].CHARACTER_HEIGHT - 1 && projectArray[q].posY < world.grid[x][i].y - projectArray[q].CHARACTER_HEIGHT)
						{
							inRangeX = true;
						}
						if (toTheLeft == false && toTheRight == false && above == false && under == false)
						{
							projectArray[q].collision = true;
							//std::cout << "Projectile #: " << q << " just collided" << std::endl;
							if (projectArray[q].velX > 0)
							{

								projectArray[q].posX = world.grid[x][i].x;
								projectArray[q].velX = 0;
								projectArray[q].velY = 0;


							}
							if (projectArray[q].velX < 0)
							{
								projectArray[q].posX = world.grid[x][i].x + world.grid[x][i].width;
								projectArray[q].velX = 0;
								projectArray[q].velY = 0;

							}

						}
					}
				}

			}
		}
	}


}


void Projectile::render_projectile(float timerAdjust)
{

	for (int i = 0; i < 30; i++)
	{
		if (projectArray[i].renderProjectile == true)
		{
			projectile.render(projectArray[i].posX - player.playerCam.x, projectArray[i].posY - player.playerCam.y);
		}


	}




}

void Projectile::throwProjectile(float mX, float mY, int num)
{
	float xDist, yDist;

	float degrees;

	projectArray[num].posX = player.player_getposX() + (player.CHARACTER_WIDTH / 2);
	projectArray[num].posY = player.player_getposY() + (player.CHARACTER_HEIGHT / 2);

	xDist = std::abs(mX - (player.player_getposX() - player.playerCam.x + (player.CHARACTER_WIDTH / 2)));
	yDist = std::abs(mY - (player.player_getposY() - player.playerCam.y + (player.CHARACTER_HEIGHT / 2)));


	float param = yDist / xDist;

	degrees = atan(param) * (180 / M_PI);

	int mainVel = 1400;

	if (mX > (player.player_getposX() - player.playerCam.x + (player.CHARACTER_WIDTH / 2)))
	{
		projectArray[num].velX = cos((degrees)* (M_PI / 180.0f)) * mainVel;
	}

	if (mX < (player.player_getposX() - player.playerCam.x + (player.CHARACTER_WIDTH / 2)))
	{
		projectArray[num].velX = (cos((degrees)* (M_PI / 180.0f)) * mainVel) * (-1);
	}

	if (mY >(player.player_getposY() - player.playerCam.y + (player.CHARACTER_HEIGHT / 2)))
	{
		projectArray[num].velY = sin((degrees)* (M_PI / 180.0f)) * mainVel;
	}

	if (mY < (player.player_getposY() - player.playerCam.y + (player.CHARACTER_HEIGHT / 2)))
	{
		projectArray[num].velY = (sin((degrees)* (M_PI / 180.0f)) * mainVel) * (-1);
	}

	projectArray[num].renderProjectile = true;

	std::cout << "velX: " << projectArray[num].velX << ", velY: " << projectArray[num].velY << std::endl;


	std::cout << "Degrees: " << degrees << std::endl;





}