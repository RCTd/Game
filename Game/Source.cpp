#include "Game.h"
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc,char* argv[])
{
	Game* game = new Game();
	game->init("Baba is You", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

	while (game->getRunning())
	{
		game->events();
		game->update();
		game->render();		
	}
	game->close();
	return 0;
}