#include "RenderLogic.h"

RenderLogic render;

RenderLogic::RenderLogic()
{

}

void RenderLogic::handle_rendering(float timer)
{
	mapTexture.render(0, 0);

	world.render_tile();

	projectileObj.render_projectile(timer);

	player.render_player(timer);

	npcObj.enemy_logic();

	introRendering();

	SDL_RenderPresent(application.renderer);


}

void RenderLogic::introRendering()
{
	


}