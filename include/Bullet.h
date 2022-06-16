#pragma once
#include <vector>
#include "Entity.h"

const unsigned int BULLET_RADIUS = 5;

class Bullet
{
public:
    Bullet(Vector2f p_position, Vector2f p_direction, SDL_Texture* p_texture, size_t p_w, size_t p_h);

    bool update(const std::vector<std::string>& p_levelData);
    bool levelCollision(const std::vector<std::string> &p_levelData);

    /*getters*/
	Vector2f getPosition() const { return _position; }
	SDL_Texture* getTexture() const { return _texture; }
	SDL_Rect getCurrentFrame() const { return _currentFrame; }

	/*setters*/
	void setPosition(Vector2f p_position) { _position = p_position; } 
	void setX(float p_x) { _position.x = p_x; }
	void setY(float p_y) { _position.y = p_y; }
	void setTexture(SDL_Texture* p_tex) { _texture = p_tex; }

private:
    void checkTilePosition(const std::vector<std::string> &p_levelData, std::vector<Vector2f> &p_collideTilePositions, float p_x, float p_y);
    void collideWithTile(Vector2f p_tilePos);

    Vector2f _direction;
	SDL_Rect _currentFrame;
	SDL_Texture* _texture;
	Vector2f _position;
    float _speed = 0.1;
};
