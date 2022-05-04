#include "InputManager.h"

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}


void InputManager::pressKey(unsigned int p_keyID)
{
    _keyMap[p_keyID] = true;
}

void InputManager::releaseKey(unsigned int p_keyID)
{
    _keyMap[p_keyID] = false;
}

bool InputManager::isKeyPressed(unsigned int p_keyID)
{
    auto it = _keyMap.find(p_keyID);
    
    if (it != _keyMap.end())
        return it->second;
        
    return false;

}