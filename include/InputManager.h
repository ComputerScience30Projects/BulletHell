#pragma once
#include <unordered_map>
#include "Math.h"

class InputManager
{
public:
    InputManager();
    ~InputManager();

    void update();
    
    void pressKey(unsigned int p_keyID);
    void releaseKey(unsigned int p_keyID);

    bool isKeyDown(unsigned int p_keyID);
    bool isKeyPressed(unsigned int p_keyID);

    void setMouseCoordinates(float x, float y);

    //getters
    Vector2f getMouseCoordinates() const { return _mouseCoordinates; }
    
private:
    
    bool wasKeyDown(unsigned int keyID);

    std::unordered_map<unsigned int, bool> _keyMap;
    std::unordered_map<unsigned int, bool> _previousKeyMap;
    Vector2f _mouseCoordinates;
};