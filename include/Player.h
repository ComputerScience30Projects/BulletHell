#pragma once
#include "Entity.h"
#include "InputManager.h"

class Player: public Entity
{
public:
    using Entity::Entity;

    void init(float p_speed, Vector2f p_position);

    void update(InputManager &p_inputManager);

private:
    float _speed;
};