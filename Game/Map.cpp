#include "Map.h"
#include "TextureManager.h"
#include <SDL.h>
#include <string>

int lvl1[16][28] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 1818, 1923, 2079, 0, 0, 0, 0, 0, 1878, 1923, 2070, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 2092, 2103, 2103, 2103, 2103, 2103, 2103, 2103, 2103, 2103, 2100, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 2082, 2082, 2082, 2082, 2082, 1779, 2082, 2082, 2082, 2082, 2082, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 2082, 1094, 2082, 2082, 2082, 1779, 2082, 2082, 2082, 1415, 2082, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 2082, 2082, 2082, 2082, 2082, 1779, 2082, 2082, 2082, 2082, 2082, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 2092, 2103, 2103, 2103, 2103, 2103, 2103, 2103, 2103, 2103, 2100, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 2061, 1923, 2040, 0, 0, 0, 0, 0, 2004, 1923, 1995, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
//int lvl1[16][28] = {};


Map::Map(SDL_Renderer* renderer)
{
	this->renderer = renderer;
	dirt = TextureManager::LoadTexture("Sprites/baba_0_1.png", renderer);
	grass = TextureManager::LoadTexture("sprites/wall_0_1.png", renderer);
	water = TextureManager::LoadTexture("sprites/text_baba.png", renderer);

	LoadMap(lvl1);

	src.x = 0;
	src.y = 0;
	src.w = 24;
	src.h = 24;
	dest.x = 0;
	dest.y = 0;
	dest.w = 24;
	dest.h = 24;

}

Map::~Map()
{

}

void Map::LoadMap(int arr[16][28])
{
	for (int row = 0; row < 16; row++)
	{
		for (int column = 0; column < 28; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;
			switch (type)
			{
			case 0:
			{
				TextureManager::Draw(water, src, dest, renderer);
				break;
			}
			case 1:
			{
				TextureManager::Draw(grass, src, dest, renderer);
				break;
			}
			case 1094:
			{
				TextureManager::Draw(dirt, src, dest, renderer);
				break;
			}
			default:
				TextureManager::Draw(water, src, dest, renderer);
				break;
			}
		}
	}
}
