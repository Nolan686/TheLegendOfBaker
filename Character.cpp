#include "Character.h"

Character player;

Character::Character()
{
	posX = 486.36;
	posY = 1203;

	velX = 0;
	velY = velYMod;





	playerCam = { 0.0f, 0.0f, application.SCREEN_WIDTH, application.SCREEN_HEIGHT };

	playerCam.x = (player_getposX() + CHARACTER_WIDTH / 2.0) - (application.SCREEN_WIDTH / 2.0);
	playerCam.y = (player_getposY() + CHARACTER_HEIGHT / 2.0) - (application.SCREEN_HEIGHT / 2.0);

}

float Character::player_getposX()
{
	return posX;
}

float  Character::player_getposY()
{
	return posY;
}

void Character::set_player_data()
{
	
	posX = 400;
	if (currentChunkY > 0)
	{
		highestChunk = currentChunkY - 1;
	}
	else
	{
		highestChunk = currentChunkY;
	}
	if (currentChunkY < 55)
	{
		lowestChunk = currentChunkY + 1;
	}
	else
	{
		lowestChunk = currentChunkY;
	}

	if (currentChunkX < 55)
	{
		farRightChunk = currentChunkX + 1;
	}
	else
	{
		farRightChunk = currentChunkX;
	}
	if (currentChunkX > 0)
	{
		farLeftChunk = currentChunkX - 1;
	}
	else
	{
		farLeftChunk = currentChunkX;
	}

	if (currentChunkY == 0)
	{
		lowestChunk = currentChunkY + 2;
	}

	if (currentChunkX == 0)
	{
		farRightChunk = currentChunkX + 2;
	}
	doneSettingChunk = true;
}

void Character::player_input(SDL_Event event)
{
	keyboardState = SDL_GetKeyboardState(NULL);


	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{


		case SDLK_SPACE:
			if (atleastOneCollision == true || inRange == true)
			{

				velY = -velYMod;
			}


		}

	}

	if (event.type == SDL_MOUSEMOTION)
	{
		mouseX = event.motion.x;
		mouseY = event.motion.y;
	}

	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{

			if (projNum == 30)
			{
				projNum = 0;
			}

			projectileObj.throwProjectile(mouseX, mouseY, projNum);
			projNum++;
		}
	}

	handleWalking();





	if (event.type == SDL_KEYUP && event.key.repeat == 0)
	{
		switch (event.key.keysym.sym)
		{


		case SDLK_t:

			break;

		}
	}
}

void Character::handleWalking()
{

	if (keyboardState[SDL_SCANCODE_D] == false)
	{
		if (keyboardState[SDL_SCANCODE_A])
		{
			if (keyboardState[SDL_SCANCODE_LSHIFT])
			{
				if (inRange || atleastOneCollision)
				{
					velXMod = 360;
					runLeft = true;
					runRight = true;
					walkLeft = false;
					walkRight = false;
				}
			}
			if (keyboardState[SDL_SCANCODE_LSHIFT] == false)
			{
				if (inRange || atleastOneCollision)
				{
					velXMod = 200;
					runLeft = false;
					runRight = false;
					walkLeft = true;
					walkRight = true;
				}
			}
			velX = -velXMod;
			left = true;
		}
		if (keyboardState[SDL_SCANCODE_A] == false)
		{
			if (keyboardState[SDL_SCANCODE_LSHIFT] == false)
			{

				if (inRange || atleastOneCollision)
				{
					velXMod = 200;
					runLeft = false;
					runRight = false;
					walkLeft = true;
					walkRight = true;
				}
			}
			if (keyboardState[SDL_SCANCODE_LSHIFT])
			{
				if (inRange || atleastOneCollision)
				{
					velXMod = 360;
					runLeft = true;
					runRight = true;
					walkLeft = false;
					walkRight = false;
				}
			}
			if (velX < 0)
			{
				lastLeft = true;
				lastRight = false;
			}
			if (velX > 0)
			{
				lastLeft = false;
				lastRight = true;
			}
			velX = 0;
		}
		right = false;
	}


	if (keyboardState[SDL_SCANCODE_A] == false)
	{
		if (keyboardState[SDL_SCANCODE_D])
		{
			if (keyboardState[SDL_SCANCODE_LSHIFT])
			{
				if (inRange || atleastOneCollision)
				{
					velXMod = 360;
					runLeft = true;
					runRight = true;
					walkLeft = false;
					walkRight = false;
				}
			}
			if (keyboardState[SDL_SCANCODE_LSHIFT] == false)
			{
				if (inRange || atleastOneCollision)
				{
					velXMod = 200;
					runLeft = false;
					runRight = false;
					walkLeft = true;
					walkRight = true;
				}
			}
			velX = velXMod;
			right = true;
		}
		if (keyboardState[SDL_SCANCODE_D] == false)
		{
			if (keyboardState[SDL_SCANCODE_LSHIFT] == false)
			{
				if (inRange || atleastOneCollision)
				{
					velXMod = 200;
					runLeft = false;
					runRight = false;
					walkLeft = true;
					walkRight = true;
				}
			}
			if (keyboardState[SDL_SCANCODE_LSHIFT])
			{
				if (inRange || atleastOneCollision)
				{
					velXMod = 360;
					runLeft = true;
					runRight = true;
					walkLeft = false;
					walkRight = false;
				}
			}
			if (velX < 0)
			{
				lastLeft = true;
				lastRight = false;
			}
			if (velX > 0)
			{
				lastLeft = false;
				lastRight = true;
			}
			velX = 0;
		}
		left = false;
	}



}


void Character::set_posX(int x)
{
	posX = x;
}

void Character::set_posY(int y)
{
	posY = y;
}

void Character::player_move(float timeStep)
{
	//std::cout << "PosX: " << posX << ", PosY: " << posY << std::endl;
	atleastOneCollision = false;
	inRange = false;

	posY += velY * timeStep;

	if (posY >= application.LEVEL_HEIGHT - CHARACTER_HEIGHT)
	{
		posY = application.LEVEL_HEIGHT - CHARACTER_HEIGHT;
		onGround = true;
	}



	if (posY < 0)
	{
		posY = 0;
	}




	gridXL = floor(posX / 16);
	gridYL = floor(posY / 16);

	if (gridYL < 10)
	{
		gridYL = 10;
	}
	if (gridYL > 7990)
	{
		gridYL = 7990;
	}
	if (gridXL < 8)
	{
		gridXL = 8;
	}
	if (gridXL > 15990)
	{
		gridXL = 15990;
	}



	for (int x = gridYL - 10; x < gridYL + 15; x++)
	{

		for (int i = gridXL - 8; i < gridXL + 15; i++)
		{

			bool toTheLeft = false;
			bool toTheRight = false;
			bool above = false;
			bool under = false;
			if (world.grid[x][i].render > 0)
			{

				atleastOneRender = true;
				if (posX + CHARACTER_WIDTH < world.grid[x][i].x)
				{
					toTheLeft = true;

				}
				if (posX > world.grid[x][i].x + world.grid[x][i].width)
				{
					toTheRight = true;
				}
				if (posY + CHARACTER_HEIGHT < world.grid[x][i].y)
				{

					above = true;

				}
				if (posY > world.grid[x][i].y + world.grid[x][i].height)
				{
					under = true;
				}


				if (atleastOneRender == true)
				{

					if (posY >= world.grid[x][i].y - CHARACTER_HEIGHT - 1 && posY <= world.grid[x][i].y - CHARACTER_HEIGHT && posX + CHARACTER_WIDTH > world.grid[x][i].x && posX < world.grid[x][i].x + world.grid[x][i].width)
					{
						inRange = true;
					}

					if (toTheLeft == false && toTheRight == false && above == false && under == false)
					{

						if (velY < 0)
						{

							posY = world.grid[x][i].y + world.grid[x][i].height + 1;
							velY = -velY / 3;

						}
						else
						{
							velY = 0;
							atleastOneCollision = true;

							//Minus one because if not it triggers x and y collision because its = to being just inside the block
							posY = world.grid[x][i].y - CHARACTER_HEIGHT - 1;


							velY = 0;


						}

					}

				}

			}

		}

	}

	if (atleastOneCollision == false)
	{
		onGround = false;

	}
	if (atleastOneCollision == true)
	{
		onGround = true;
	}


	

	if (currentChunkY > 0)
	{
		highestChunk = currentChunkY - 1;
	}
	else
	{
		highestChunk = currentChunkY;
	}
	if (currentChunkY < 55)
	{
		lowestChunk = currentChunkY + 1;
	}
	else
	{
		lowestChunk = currentChunkY;
	}

	if (currentChunkX < 55)
	{
		farRightChunk = currentChunkX + 1;
	}
	else
	{
		farRightChunk = currentChunkX;
	}
	if (currentChunkX > 0)
	{
		farLeftChunk = currentChunkX - 1;
	}
	else
	{
		farLeftChunk = currentChunkX;
	}

	if (currentChunkY == 0)
	{
		lowestChunk = currentChunkY + 2;
	}

	if (currentChunkX == 0)
	{
		farRightChunk = currentChunkX + 2;
	}


	//std::cout << "Current X Chunk: " << currentChunkX << ", Current Y Chunk: " << currentChunkY << ", Above Chunk: " << highestChunk << ", Lowest Chunk: " << LowestChunk << ", Leftmost Chunk: " << farLeftChunk << ", Rightmost Chunk: " << farRightChunk << std::endl;


	if (atleastOneCollision == false && inRange == false)
	{

		if (velY <= 1500)
		{
			velY += gravity * timeStep;
		}
	}


	posX += velX * timeStep;

	if (posX < 0)
	{
		posX = 0;
	}

	if (posX >= application.LEVEL_WIDTH - CHARACTER_WIDTH)
	{
		posX = application.LEVEL_WIDTH - CHARACTER_WIDTH;
	}


	gridXL = floor(posX / 16);
	gridYL = floor(posY / 16);



	if (gridYL < 10)
	{
		gridYL = 10;
	}
	if (gridYL > 7990)
	{
		gridYL = 7990;
	}
	if (gridXL < 8)
	{
		gridXL = 8;
	}
	if (gridXL > 15990)
	{
		gridXL = 15990;
	}



	for (int x = gridYL - 10; x < gridYL + 15; x++)
	{

		for (int i = gridXL - 8; i < gridXL + 15; i++)
		{
			bool toTheLeft = false;
			bool toTheRight = false;
			bool above = false;
			bool under = false;

			if (world.grid[x][i].render > 0)
			{
				atleastOneRender = true;
				if (posX + CHARACTER_WIDTH < world.grid[x][i].x)
				{
					toTheLeft = true;

				}
				if (posX > world.grid[x][i].x + world.grid[x][i].width)
				{
					toTheRight = true;
				}
				if (posY + CHARACTER_HEIGHT < world.grid[x][i].y)
				{
					above = true;
				}
				if (posY > world.grid[x][i].y + world.grid[x][i].height)
				{
					under = true;
				}

				if (atleastOneRender == true)
				{
					if (toTheLeft == false && toTheRight == false && above == false && under == false)
					{

						if (velX > 0)
						{

							posX = world.grid[x][i].x - CHARACTER_WIDTH - 1;


						}
						if (velX < 0)
						{
							posX = world.grid[x][i].x + world.grid[x][i].width + .5;
						}

					}
				}
			}

		}
	}

	playerCam.x = (player_getposX() + CHARACTER_WIDTH / 2.0) - (application.SCREEN_WIDTH / 2.0);
	playerCam.y = (player_getposY() + CHARACTER_HEIGHT / 2.0) - (application.SCREEN_HEIGHT / 2.0);

	
	//camera bounds
	if (playerCam.x < 0)
	{
		playerCam.x = 0;
	}
	//Keep camera in bounds
	if (playerCam.y < 0)
	{
		playerCam.y = 0;
	}
	//Keep camera in boundsd
	if (playerCam.x > application.LEVEL_WIDTH - playerCam.w)
	{
		playerCam.x = application.LEVEL_WIDTH - playerCam.w;
	}
	//Keep camera in bounds
	if (playerCam.y > application.LEVEL_HEIGHT - playerCam.h)
	{
		playerCam.y = application.LEVEL_HEIGHT - playerCam.h;
	}


	if (right && left)
	{
		velX = 0;
	}

}






void Character::render_player(float timerAdjust)
{
	playerStandRight.render(posX - player.playerCam.x - 24, posY - player.playerCam.y - 24);

}