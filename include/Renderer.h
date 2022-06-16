#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.h"
#include "Bullet.h"
#include "Error.h"

class Renderer
{
public:
	Renderer();
	
	void initWindow(const char* p_title, int p_w, int p_h);
	
	SDL_Texture* loadTexture(const char* p_filePath);

	void cleanUp();
	void clear();
	void render(Entity &p_entity);
	void renderRotating(Entity &p_entity);
	void renderBullet(Bullet &p_entity);

	void display();

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};