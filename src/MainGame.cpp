#include "MainGame.h"


MainGame::MainGame():
    _screenWidth(1280), _screenHeight(720), 
    _gameState(PLAY),
    _player(nullptr)
{

}

void MainGame::run()
{
    initSystems();
    gameloop();
}

void MainGame::initSystems()
{
    /*Initialize SDL*/
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
		errorSDL("SDL_Init has failed.");

    /*Initialize SDL_IMG*/
	if (!(IMG_Init(IMG_INIT_PNG)))
		errorSDL("IMG_init has failed.");

    /*Initialize Window and Renderer*/
    _renderer.initWindow("Survival", _screenWidth, _screenHeight);

    initLevel("Levels/level1.txt");
}

void MainGame::initLevel(std::string p_filepath)
{
    /*Open Level File*/
    std::ifstream file(p_filepath);

    if (!file.is_open())
        error("Failed to open " + p_filepath);

    /*Get Number of Humans From First Line*/
    std::string tmp;

    /*Read the Level Data*/
    while (std::getline(file, tmp)) 
        _levelData.emplace_back(tmp);    
    
    /*Load Tile Textures*/
    SDL_Texture* redBrick = _renderer.loadTexture("res/gfx/LevelTiles/red_bricks.png");
    SDL_Texture* glass = _renderer.loadTexture("res/gfx/LevelTiles/glass.png");
    SDL_Texture* lightBrick = _renderer.loadTexture("res/gfx/LevelTiles/light_bricks.png");
    SDL_Texture* playerTex = _renderer.loadTexture("res/gfx/player.png");

    /*Interpret the Data and Render the Tiles*/
    for (size_t y = 0; y < _levelData.size(); y++) 
        for (size_t x = 0; x < _levelData[y].size(); x++) 
        {
            /* Grab the Tile */
            char tile = _levelData[y][x];

            Vector2f position(x * TILE_WIDTH, y * TILE_WIDTH);

            /* Process Tile Data */
            switch (tile) {
                case 'R': //Red Bricks
                    _entities.push_back(Entity(position, redBrick, TILE_WIDTH, TILE_WIDTH));
                    break;

                case 'G': //Glass
                    _entities.push_back(Entity(position, glass, TILE_WIDTH, TILE_WIDTH));
                    break;

                case 'L': //Light Bricks
                    _entities.push_back(Entity(position, lightBrick, TILE_WIDTH, TILE_WIDTH));
                    break;

                case '@': //Player
                    _levelData[y][x] = '.'; // So we dont collide with it
                    
                    _player = new Player(position, playerTex, TILE_WIDTH, TILE_WIDTH);
                    _player->init(PLAYER_SPEED, position);
                    break;

                case 'Z': //Zombie
                    _levelData[y][x] = '.'; // So we dont collide with it
                    break;

                case '.':
                    break;

                default:
                    error("Unexpected symbol in " + p_filepath);
                    break;
            }
        }
}


void MainGame::processInput() 
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                _gameState = EXIT;
                break;
            case SDL_KEYDOWN:
                _inputManager.pressKey(event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                _inputManager.releaseKey(event.key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
                _inputManager.pressKey(event.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                _inputManager.releaseKey(event.button.button);
                break;
        }
    }
}

void MainGame::gameloop()
{
	SDL_Event event;

    _timeStep.start();

    /*Game Loop*/
    while (_gameState == PLAY)
	{
        while (!_timeStep.isAccumulatorFull())
        {
            processInput();
            _player->update(_inputManager);
            _timeStep.addToAccumulator();
        }       
        _timeStep.resetAccumulator();

        /*Render Entities*/
		_renderer.clear();
		
        for(Entity &entity : _entities)
		    _renderer.render(entity);
        
        _renderer.render(*_player);
        		
        _renderer.display();
	}

    _renderer.cleanUp();
    SDL_Quit();
}