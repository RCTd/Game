#include "Game.h"
#include "Map.h"

Map* map;

void Game::init(const char* Windowtitle, int x, int y, int w, int h, SDL_WindowFlags flags )
{
	if (!SDL_Init(SDL_INIT_EVERYTHING) && IMG_Init(IMG_INIT_PNG))
	{
		window = SDL_CreateWindow(Windowtitle, x, y, w, h, flags);
		if (window == NULL)
		{
			SDL_Log("Window Create ERROR %s\n", SDL_GetError());
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL)
			{
				SDL_Log("Renderer Create ERROR %s\n", SDL_GetError());
			}
			else
			{
				isRunning = true;
			}
		}
		map = new Map(renderer);
	}
	else
	{
		SDL_Log("INIT ERROR %s\n",SDL_GetError());
	}
}

void Game::update()
{
	//logica
}
void Game::events()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
	break;
	}

}
void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);
	map->DrawMap();

	//desen


	SDL_RenderPresent(renderer);
}

void Game::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}