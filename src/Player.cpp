#include "Player.h"

void Player::init(float p_speed, Vector2f p_position)
{
    setPosition(p_position);
    _speed = p_speed;
}

void Player::update(InputManager &p_inputManager)
{
    /*Move Player Using WASD*/
    if (p_inputManager.isKeyPressed(SDLK_w))
    {
        setY(getPosition().y - _speed);
    }
    else if (p_inputManager.isKeyPressed(SDLK_s))
    {
        setY(getPosition().y + _speed);
    }
    if (p_inputManager.isKeyPressed(SDLK_a))
        setX(getPosition().x - _speed);
    else if (p_inputManager.isKeyPressed(SDLK_d))
        setX(getPosition().x + _speed);
}