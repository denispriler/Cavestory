/*
Input.cpp

Input class

SDL_Scancode -> https://wiki.libsdl.org/SDL_Scancode
SDL_LogDebug -> https://wiki.libsdl.org/SDL_LogDebug
*/

#include <Input.hpp>
#include <SDL/SDL.h>

// Calls at the begining of each new frame to reset the keys that are no longer relevant
void Input::frame() {
    this->_pressedKeys.clear();
    this->_releasedKeys.clear(); 
}

// Calls when key released
void Input::keyUpEvent(const SDL_Event& event) {
    this->_releasedKeys[event.key.keysym.scancode] = true;
    SDL_Log("Key %d was released.\n", event.key.keysym.scancode);
    this->_heldKeys[event.key.keysym.scancode] = false;
}

// Class when key pressed
void Input::keyDownEvent(const SDL_Event& event) {
    this->_pressedKeys[event.key.keysym.scancode] = true;
    SDL_Log("Key %d was pressed.\n", event.key.keysym.scancode);
    this->_heldKeys[event.key.keysym.scancode] = true;
}

bool Input::isKeyPressed(SDL_Scancode key) {
    return this->_pressedKeys[key];
}

bool Input::isKeyReleased(SDL_Scancode key) {
    return this->_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
    return this->_heldKeys[key];
}
