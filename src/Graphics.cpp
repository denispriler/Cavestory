#include <Graphics.hpp>

#define W 640
#define H 480

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(W, H, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
}

SDL_Surface *Graphics::loadImage(const std::string &filePath)
{
    if (this->_spriteSheets.count(filePath) == 0)
    {
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *source, SDL_Rect *sourceRectangle, SDL_Rect *destRectangle)
{
    SDL_RenderCopy(this->_renderer, source, sourceRectangle, destRectangle);
}

void Graphics::flip()
{
    // SDL_RenderPresent -> https://wiki.libsdl.org/SDL_RenderPresent
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear()
{
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer *Graphics::getRenderer() const
{
    return this->_renderer;
}
