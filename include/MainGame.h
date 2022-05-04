#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <fstream>

#include "Error.h"
#include "Renderer.h"
#include "Entity.h"
#include "Player.h"
#include "TimeStep.h"
#include "Math.h"
#include "Utils.h"
#include "InputManager.h"

enum GameState {MENU, PLAY, EXIT};

const size_t TILE_WIDTH = 32;

const float PLAYER_SPEED = 5.0f;
const float HUMAN_SPEED = 3.0f;
const float ZOMBIE_SPEED = 3.0f;

class MainGame
{
public:
    MainGame();
    void run();

private:
    void initSystems();
    void initLevel(std::string p_filepath);
    void processInput();
    void gameloop();

    /*Window and Rendering*/
    Renderer _renderer;
    std::vector<Entity> _entities;

    size_t _screenWidth;
    size_t _screenHeight;
    
    /*Timestepping*/
    TimeStep _timeStep;

    /*Game State*/
    GameState _gameState;

    /*Input Manager*/
    InputManager _inputManager;
    
    /*Level Data*/
    std::vector<std::string> _levelData;

    /*Player*/
    Player* _player;

};
