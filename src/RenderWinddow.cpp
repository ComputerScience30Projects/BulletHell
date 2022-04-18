#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h):
    _window(NULL), _renderer(NULL)
{
    /*Create Window*/
    _window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    
    if(_window == NULL)
        Error("Window failed to initialize.");

    /*Create Renderer*/
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filepath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(_renderer, p_filepath);

    if(texture == NULL)
        Error("Failed to load texture.");

    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(_renderer);
}

void RenderWindow::render(Entity &p_entity)
{
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getX() * 4;
    dst.y = p_entity.getY() * 4;
    dst.w == p_entity.getCurrentFrame().w * 4;
    dst.h = p_entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(_renderer, p_entity.getTexture(), &src, &dst);
}

void RenderWindow::cleanUp()
{
    /*Destroy Window*/
    SDL_DestroyWindow(_window);
}

void RenderWindow::display()
{
    /*Display to Window*/
    SDL_RenderPresent(_renderer);
}