#ifndef SPRITE_HPP
#define SPRITE_HPP

/*
    Holds on all information about individual sprite.
*/

#include <string>
#include <SDL/SDL.h>

class Graphics;

class Sprite
{
private:
    SDL_Rect _sourceRect;
    SDL_Texture *_spriteSheet;

    float _x, _y;

public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filePath,
           int sourceX, int sourceY,
           int width, int height,
           float posX, float posY);
    virtual ~Sprite();
    virtual void update();

    void draw(Graphics &graphics, int x, int y);
};

#endif
