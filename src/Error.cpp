#include "Error.h"


void Error(std::string error)
{
    /*Print Error*/
    std::cout << error << " SDL_ERROR: " << SDL_GetError() << std::endl;
}