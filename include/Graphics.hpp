#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <SDL/SDL.h>
#include <SDL_Image/SDL_image.h>
#include <map>
#include <string>

/*
Main graphics class dealing with graphics.

SDL Window Flags -> https://wiki.libsdl.org/SDL_WindowFlags
*/

struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
public:
    Graphics();
    ~Graphics();

    /* SDL_Surface* loadImage
    *  Loads image into the _spriteSheets map if it doesn't exist (each image is gonna load only once).
    */
    SDL_Surface *loadImage(const std::string &filePath);

    /* void blitSurface
    *  Draws a texture to the certain part of the screen.
    */
    void blitSurface(SDL_Texture *source, SDL_Rect *sourceRectangle, SDL_Rect *destRectangle);

    /* void flit
    *  Renders everything to the screen.
    */
    void flip();

    /* void clear
    *  Clears the screen.
    */
    void clear();

    /* SDL_Renderer* getRenderer
    *  Returns the renderer. 
    */
    SDL_Renderer *getRenderer() const;

private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;

    std::map<std::string, SDL_Surface *> _spriteSheets;
};

#endif
