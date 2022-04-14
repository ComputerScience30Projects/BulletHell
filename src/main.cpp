#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Error.h"
#include "RenderWindow.h"

int main(int argc, char* args[])
{
    /*Init SDL*/
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        Error("SDL_Init has failed.");

    /*Init SDL_image*/
    if(!IMG_Init(IMG_INIT_PNG)) //Set to PNG
        Error("IMG_Init has failed.");

    RenderWindow window("Bullet Hell", 1280, 720);
    
    /*Game Loop*/
    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                gameRunning = false;
        }
    }
    
    window.cleanUp();
    SDL_Quit();

    return 0;
}