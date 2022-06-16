#include "Bullet.h"

Bullet::Bullet(Vector2f p_position, Vector2f p_direction, SDL_Texture* p_texture, size_t p_w, size_t p_h):
    _position(p_position),
	_texture(p_texture),
	_direction(p_direction)
{
    std::cout << std::to_string(_position.x) << " " << std::to_string(_position.y) << std::endl;

	_currentFrame.x = 0;
	_currentFrame.y = 0;
	_currentFrame.w = p_w;
	_currentFrame.h = p_h;
}

bool Bullet::update(const std::vector<std::string>& p_levelData)
{
    /* Move Bullet */
    _position = _position + Vector2f(_direction.x * _speed, _direction.y * _speed);
    return levelCollision(p_levelData);
}   

bool Bullet::levelCollision(const std::vector<std::string> &p_levelData)
{

    std::vector<Vector2f> collideTilePositions;

    /* Check Four Corners */
    checkTilePosition(p_levelData,
                      collideTilePositions,
                      _position.x,
                      _position.y);

    checkTilePosition(p_levelData,
                      collideTilePositions,
                      _position.x + AGENT_WIDTH,
                      _position.y);


    checkTilePosition(p_levelData,
                      collideTilePositions,
                      _position.x,
                      _position.y + AGENT_WIDTH);

    checkTilePosition(p_levelData,
                      collideTilePositions,
                      _position.x + AGENT_WIDTH,
                      _position.y + AGENT_WIDTH);
    
    /* Check if there is No Collisions */
    if (collideTilePositions.size() == 0)
        return false;

    /* Do the Collisions */
    for (size_t i = 0; i < collideTilePositions.size(); i++)
        collideWithTile(collideTilePositions[i]);

    return true;
}

void Bullet::checkTilePosition(const std::vector<std::string> &p_levelData, std::vector<Vector2f> &p_collideTilePositions, float p_x, float p_y) 
{
    /* Get the position of this corner in grid-space */
    Vector2f gridPosition = Vector2f(floor(p_x / (float)TILE_WIDTH), floor(p_y / (float)TILE_WIDTH));

    /* If we are Outside the World, just return*/
    if (gridPosition.x < 0 || gridPosition.x >= p_levelData[0].size() || gridPosition.y < 0 || gridPosition.y >= p_levelData.size())
        return;

    /* If not an air tile collide*/
    if (p_levelData[gridPosition.y][gridPosition.x] != '.')
        p_collideTilePositions.push_back(Vector2f(gridPosition.x * (float)TILE_WIDTH, gridPosition.y * (float)TILE_WIDTH) + Vector2f((float)TILE_WIDTH / 2.0f, (float)TILE_WIDTH / 2.0f));
}

// Axis Aligned Bounding Box Collision from MakingGamesWithBen Tutorial
void Bullet::collideWithTile(Vector2f p_tilePos) 
{
    const float TILE_RADIUS = (float)TILE_WIDTH / 2.0f;

    /* The minimum distance before a collision occurs */
    const float MIN_DISTANCE = AGENT_RADIUS + TILE_RADIUS;

    /* Get Center position of the Agent */
    Vector2f centerAgentPosition(_position.x + AGENT_RADIUS, _position.y + AGENT_RADIUS);

    /* Vector From the Agent to the Tile */
    Vector2f distanceVector = centerAgentPosition - p_tilePos;

    /* Get Collision Depth */
    float xDepth = MIN_DISTANCE - abs(distanceVector.x);
    float yDepth = MIN_DISTANCE - abs(distanceVector.y);

    /* If Both the Depths are > 0, Collided */
    if (xDepth > 0 && yDepth > 0) 
    {

        /* Check which collision depth is less */
        if (std::max(xDepth, 0.0f) < std::max(yDepth, 0.0f)) 
        {
            /* X Depth is smaller so Push X Direction */
            if (distanceVector.x < 0) 
                _position.x -= xDepth;
            else
                _position.x += xDepth;
        } 
        else 
        {
            /* Y Depth is smaller so Push Y Direction */
            if (distanceVector.y < 0)
                _position.y -= yDepth;
            else
                _position.y += yDepth;
        }
    }
}
