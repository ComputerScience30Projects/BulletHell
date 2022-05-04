#pragma once
#include <unordered_map>
#include "Math.h"

class InputManager
{
public:
    InputManager();
    ~InputManager();

    void pressKey(unsigned int p_keyID);
    void releaseKey(unsigned int p_keyID);

    bool isKeyPressed(unsigned int p_keyID);

private:

    std::unordered_map<unsigned int, bool> _keyMap;
};