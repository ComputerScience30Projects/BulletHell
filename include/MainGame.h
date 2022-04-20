#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Error.h"
#include "Renderer.h"
#include "Entity.h"
#include "Math.h"
#include "Utils.h"

enum GameState {MENU, PLAY, EXIT};

class MainGame
{
public:
    MainGame();
    void run();

private:
    void initSystems();
    void loadTextures();

    void gameloop();

    /*Window and Rendering*/
    Renderer _renderer;
    std::vector<Entity> _entities;

    size_t _screenWidth;
    size_t _screenHeight;
    

    /*Game State*/
    GameState _gameState;

};
