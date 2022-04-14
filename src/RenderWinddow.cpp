#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h):
    _window(NULL), _renderer(NULL)
{
    SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    
    if(_window == NULL)
        Error("Window failed to initialize.");

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(_window);
}