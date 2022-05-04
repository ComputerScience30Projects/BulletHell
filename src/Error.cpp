#include "Error.h"


void errorSDL(std::string error)
{
    /*Print Error*/
    std::cout << error << " SDL_ERROR: " << SDL_GetError() << std::endl;
}

void error(std::string error)
{
    /*Print Error*/
    std::cout <<  "ERROR: " << error << std::endl;
}