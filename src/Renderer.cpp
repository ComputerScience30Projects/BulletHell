#include "Renderer.h"


Renderer::Renderer():
	_window(NULL), _renderer(NULL)
{
}

void Renderer::initWindow(const char* p_title, int p_w, int p_h)
{
	_window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (_window == NULL)
		errorSDL("Window failed to initialize.");

	/*Create Renderer*/
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			
	if (_renderer == NULL)
		errorSDL("Renderer failed to initialize.");
	
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
}

SDL_Texture* Renderer::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(_renderer, p_filePath);

	if (texture == NULL)
		errorSDL("Failed to load texture.");

	return texture;
}

void Renderer::cleanUp()
{
	SDL_DestroyWindow(_window);
}

void Renderer::clear()
{
	SDL_RenderClear(_renderer);
}

void Renderer::render(Entity& p_entity)
{
	SDL_Rect src; 
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPosition().x;
	dst.y = p_entity.getPosition().y;
	dst.w = p_entity.getCurrentFrame().w;
	dst.h = p_entity.getCurrentFrame().h;

	SDL_RenderCopy(_renderer, p_entity.getTexture(), &src, &dst);
}

void Renderer::renderBullet(Bullet &p_entity)
{
	SDL_Rect src; 
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPosition().x;
	dst.y = p_entity.getPosition().y;
	dst.w = p_entity.getCurrentFrame().w;
	dst.h = p_entity.getCurrentFrame().h;

	SDL_RenderCopy(_renderer, p_entity.getTexture(), &src, &dst);
}


void Renderer::renderRotating(Entity &p_entity)
{
	SDL_Rect src; 
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPosition().x;
	dst.y = p_entity.getPosition().y;
	dst.w = p_entity.getCurrentFrame().w;
	dst.h = p_entity.getCurrentFrame().h;

	SDL_RenderCopyEx(_renderer, p_entity.getTexture(), &src, &dst, p_entity.getAngle(), NULL, SDL_FLIP_NONE);
}

void Renderer::display()
{
	SDL_RenderPresent(_renderer);
}