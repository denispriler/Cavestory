#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL/SDL.h>

/*
Input class

SDL_Scancode -> https://wiki.libsdl.org/SDL_Scancode
SDL_LogDebug -> https://wiki.libsdl.org/SDL_LogDebug
*/

#include <map>
#include <SDL/SDL.h>

class Input
{
private:
    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;
public:
    void frame();
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);

    bool isKeyPressed(SDL_Scancode key);
    bool isKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);
};
#endif
