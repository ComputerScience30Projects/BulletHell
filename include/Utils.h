#pragma once

#include <SDL2/SDL.h>

namespace utils
{
    inline float elapsedTime()
    {
        /*Get Seconds Since Start*/
        float t = SDL_GetTicks(); //Get ms
        t *= 0.001f; //Turn ms to s
        
        return t;
    }
}