#include "InputManager.h"

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::update() 
{
    for (auto& it : _keyMap) 
        _previousKeyMap[it.first] = it.second;
}

void InputManager::pressKey(unsigned int p_keyID)
{
    _keyMap[p_keyID] = true;
}

void InputManager::releaseKey(unsigned int p_keyID)
{
    _keyMap[p_keyID] = false;
}

void InputManager::setMouseCoordinates(float x, float y) 
{
    _mouseCoordinates.x = x;
    _mouseCoordinates.y = y;
}

bool InputManager::isKeyPressed(unsigned int p_keyID)
{
    auto it = _keyMap.find(p_keyID);
    
    if (it != _keyMap.end())
        return it->second;
        
    return false;
}

bool InputManager::isKeyDown(unsigned int keyID) 
{
    auto it = _keyMap.find(keyID);
    if (it != _keyMap.end())
        return it->second;
    else
        return false;
}

bool InputManager::wasKeyDown(unsigned int keyID) 
{
    auto it = _previousKeyMap.find(keyID);
    if (it != _previousKeyMap.end())
        return it->second;
    else
        return false;
}