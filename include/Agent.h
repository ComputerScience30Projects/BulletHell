#pragma once

#include "Entity.h"
#include <vector>
#include <string>

class Agent: public Entity
{

public:
    using Entity::Entity;

    bool levelCollision(const std::vector<std::string> &levelData);
private:

};
