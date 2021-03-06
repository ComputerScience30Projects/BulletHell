#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.h"

const size_t TILE_WIDTH = 32;
const size_t AGENT_WIDTH = 32;
const size_t AGENT_RADIUS = AGENT_WIDTH / 2;

class Entity
{
public:
	Entity(Vector2f p_position, SDL_Texture* p_texture, size_t p_w, size_t p_h);
	Entity(Vector2f p_position, Vector2f p_direction, SDL_Texture* p_texture, size_t p_w, size_t p_h);

    /*getters*/
	Vector2f getPosition() const { return _position; }
	SDL_Texture* getTexture() const { return _texture; }
	SDL_Rect getCurrentFrame() const { return _currentFrame; }
	float getAngle() const { return _angle; }

	/*setters*/
	void setPosition(Vector2f p_position) { _position = p_position; } 
	void setX(float p_x) { _position.x = p_x; }
	void setY(float p_y) { _position.y = p_y; }
	void setAngle(float p_angle) {_angle = p_angle;}
	void setTexture(SDL_Texture* p_tex) { _texture = p_tex; }

private:
	SDL_Rect _currentFrame;
	SDL_Texture* _texture;
	Vector2f _position;
	float _angle;
};