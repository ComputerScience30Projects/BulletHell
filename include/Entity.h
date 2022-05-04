#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.h"

class Entity
{
public:
	Entity();
	Entity(Vector2f p_position, SDL_Texture* p_tex, size_t p_w, size_t p_h);

    /*getters*/
	Vector2f getPosition() const { return _position; }
	SDL_Texture* getTexture() const { return _texture; }
	SDL_Rect getCurrentFrame() const { return _currentFrame; }

	/*getters*/
	void setPosition(Vector2f p_position) { _position = p_position; } 
	void setX(float p_x) { _position.x = p_x; }
	void setY(float p_y) { _position.y = p_y; }
private:

	Vector2f _position;
	SDL_Rect _currentFrame;
	SDL_Texture* _texture;

};