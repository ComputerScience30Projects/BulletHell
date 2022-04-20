#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "MainGame.h"

int main(int argc, char* args[])
{
	MainGame maingame;

	maingame.run();
	
	return 0;
}