#include "Entity.h"

Entity::Entity(Vector2f p_position, SDL_Texture* p_texture, size_t p_w, size_t p_h):
    _position(p_position),
	_texture(p_texture)
{
	_currentFrame.x = 0;
	_currentFrame.y = 0;
	_currentFrame.w = p_w;
	_currentFrame.h = p_h;
}