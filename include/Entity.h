#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_texture);
    ~Entity();

    //getters
    float getX() { return _x; }
    float getY() { return _y; }
    SDL_Texture* getTexture() { return _texture; }
    SDL_Rect getCurrentFrame() { return _currentFrame; }


private:
    float _x, _y;
    SDL_Texture* _texture;
    SDL_Rect _currentFrame;

};
