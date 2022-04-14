#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Error.h"

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);    
    
    void cleanUp();
    
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
};