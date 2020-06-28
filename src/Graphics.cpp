#include <SDL/SDL.h>
#include <Graphics.hpp>

#define W 640
#define H 480

/*
Graphics.cpp

Main graphics class dealing with graphics.

SDL Window Flags -> https://wiki.libsdl.org/SDL_WindowFlags
*/

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(W, H, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->_window);
}
