#ifndef GAME_HPP
#define GAME_HPP

#include <SDL/SDL.h>
#include <Graphics.hpp>
#include <Input.hpp>
#include <Sprite.hpp>

/*

Main game class.

SDL_Init -> https://wiki.libsdl.org/SDL_Init
*/

class Graphics;

class Game
{
private:
    void loop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    Sprite _player;

public:
    Game();
    ~Game();
};

#endif
