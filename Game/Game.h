#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Game {
private:
	bool isRunning = false;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
public:
	Game() :window(NULL), renderer(NULL), event({ 0 }) {}
	//functii
	void init(const char* Windowtitle, int x,int y,int w,int h,SDL_WindowFlags flags);
	void update();
	void events();
	void render();
	void close();
	inline bool getRunning() { return isRunning; }
};