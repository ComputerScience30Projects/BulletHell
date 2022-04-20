#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.h"

class Entity
{
public:

	Entity(Vector2f p_position, SDL_Texture* p_tex, size_t p_w, size_t p_h);

    /*getters*/
	Vector2f getPosition() { return _position; }
	SDL_Texture* getTexture(){ return _texture; }
	SDL_Rect getCurrentFrame(){ return _currentFrame; }
    
private:

	Vector2f _position;
	SDL_Rect _currentFrame;
	SDL_Texture* _texture;

};