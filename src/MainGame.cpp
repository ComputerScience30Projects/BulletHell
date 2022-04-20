#include "MainGame.h"


MainGame::MainGame():
    _screenWidth(1280), _screenHeight(720), 
    _gameState(PLAY)
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
		Error("SDL_Init has failed.");

    /*Initialize SDL_IMG*/
	if (!(IMG_Init(IMG_INIT_PNG)))
		Error("IMG_init has failed.");

    /*Initialize Window*/
    _renderer.initWindow("Survival", _screenWidth, _screenHeight);

    loadTextures();
}

void MainGame::loadTextures()
{
    /*Load Textures*/
    SDL_Texture* grassTexture = _renderer.loadTexture("res/gfx/Survivor/handgun/idle/survivor-idle_handgun_0.png");

    _entities.push_back(Entity(Vector2f(10, 20), grassTexture, 253, 216));
}

void MainGame::gameloop()
{

    const float timeStep = 0.01f;

    float accumulator = 0.0f;
    float initialTime = utils::elapsedTime();

	SDL_Event event;

    while (_gameState == PLAY)
	{
        float newTime = utils::elapsedTime();
        float frameTime = newTime - initialTime;

        initialTime = newTime;

        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
		    {
			    if (event.type == SDL_QUIT)
				    _gameState = EXIT;
		    }

            accumulator -= timeStep;
        }

        const float alpha = accumulator / timeStep;

        /*Render Window*/
		_renderer.clear();
		
        for(Entity &entity : _entities)
		    _renderer.render(entity);

		_renderer.display();
	}

    _renderer.cleanUp();
    SDL_Quit();
}