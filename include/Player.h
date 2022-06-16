#pragma once

#include "Entity.h"
#include "InputManager.h"
#include "Bullet.h"
#include "Renderer.h"
#include <vector>

class Player: public Entity
{
public:
    using Entity::Entity;

    const float TILE_RADIUS = (float)TILE_WIDTH / 2.0f;

    void init(float p_speed, Vector2f p_position);

    void update(InputManager &p_inputManager, const std::vector<std::string>& p_levelData);

    bool levelCollision(const std::vector<std::string> &p_levelData);
    

private:
    void collideWithTile(Vector2f p_position);
    void checkTilePosition(const std::vector<std::string> &p_levelData, std::vector<Vector2f> &p_collideTilePositions, float p_x, float p_y);
    
    float _speed;
};