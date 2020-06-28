/*
Game.cpp

Main game class.

SDL_Init -> https://wiki.libsdl.org/SDL_Init
*/

#include <SDL/SDL.h>
#include <Game.hpp>
#include <Graphics.hpp>
#include <Input.hpp>

namespace {
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->loop();
}

Game::~Game() {

}

void Game::loop() {
    Graphics graphics;
    Input input;
    SDL_Event event;

    int LAST_UPDATE_TIME_MS = SDL_GetTicks();
    // Start the loop
    while(true) {
        input.frame();

        if(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                if(!event.key.repeat) {
                    input.keyDownEvent(event);
                }
                break;

            case SDL_KEYUP:
                input.keyUpEvent(event);
                break; 
            
            case SDL_QUIT:
                return;
                break;
            
            default:
                break;
            }
        }

        if(input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
            return;
        }

        const int CURRENT_TIME_MS = SDL_GetTicks();
        const int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME_MS;

        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));

        LAST_UPDATE_TIME_MS = CURRENT_TIME_MS;
    }
}

void Game::draw(Graphics &graphics) {

}

void Game::update(float elapsedTime) {
    SDL_Log("Update. %f\n", elapsedTime);
}
