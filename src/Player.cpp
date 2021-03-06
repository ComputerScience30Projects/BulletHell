#include "Player.h"

void Player::init(float p_speed, Vector2f p_position)
{
    setPosition(p_position);
    _speed = p_speed;
}

void Player::update(InputManager &p_inputManager, const std::vector<std::string>& p_levelData)
{
    int mouseCoord_x, mouseCoord_y;
    SDL_GetMouseState(&mouseCoord_x, &mouseCoord_y);
    p_inputManager.setMouseCoordinates((float)mouseCoord_x, (float)mouseCoord_y);

    Vector2f delta(getPosition().x - mouseCoord_x, getPosition().y - mouseCoord_y);

    setAngle((atan2(-delta.y, -delta.x) * 180.0000)/ 3.14159265);

    /*Move Player Using WASD*/
    if (p_inputManager.isKeyPressed(SDLK_w))
        setY(getPosition().y - _speed);
    else if (p_inputManager.isKeyPressed(SDLK_s))
        setY(getPosition().y + _speed);
    if (p_inputManager.isKeyPressed(SDLK_a))
        setX(getPosition().x - _speed);
    else if (p_inputManager.isKeyPressed(SDLK_d))
        setX(getPosition().x + _speed);

    levelCollision(p_levelData);
}

bool Player::levelCollision(const std::vector<std::string> &p_levelData)
{
    Vector2f position = getPosition();

    std::vector<Vector2f> collideTilePositions;

    /* Check Four Corners */
    checkTilePosition(p_levelData,
                      collideTilePositions,
                      position.x,
                      position.y);

    checkTilePosition(p_levelData,
                      collideTilePositions,
                      position.x + AGENT_WIDTH,
                      position.y);


    checkTilePosition(p_levelData,
                      collideTilePositions,
                      position.x,
                      position.y + AGENT_WIDTH);

    checkTilePosition(p_levelData,
                      collideTilePositions,
                      position.x + AGENT_WIDTH,
                      position.y + AGENT_WIDTH);
    
    /* Check if there is No Collisions */
    if (collideTilePositions.size() == 0)
        return false;

    /* Do the Collisions */
    for (size_t i = 0; i < collideTilePositions.size(); i++)
        collideWithTile(collideTilePositions[i]);
        
    return true;
}

void Player::checkTilePosition(const std::vector<std::string> &p_levelData, std::vector<Vector2f> &p_collideTilePositions, float p_x, float p_y) 
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
void Player::collideWithTile(Vector2f p_tilePos) 
{
    Vector2f position = getPosition();

    const float TILE_RADIUS = (float)TILE_WIDTH / 2.0f;

    /* The minimum distance before a collision occurs */
    const float MIN_DISTANCE = AGENT_RADIUS + TILE_RADIUS;

    /* Get Center position of the Agent */
    Vector2f centerAgentPosition(position.x + AGENT_RADIUS, position.y + AGENT_RADIUS);

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
                setX(position.x - xDepth);
            else
                setX(position.x + xDepth);
        } 
        else 
        {
            /* Y Depth is smaller so Push Y Direction */
            if (distanceVector.y < 0)
                setY(position.y - yDepth);
            else
                setY(position.y + yDepth);
        }
    }
}
