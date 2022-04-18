#include "Entity.h"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_texture):
    _texture(p_texture), _x(p_x), _y(p_y)
{
    _currentFrame.x = 0;
    _currentFrame.y = 0;
    _currentFrame.w = 32;
    _currentFrame.h = 32;
}

Entity::~Entity()
{

}