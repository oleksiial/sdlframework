#include <SDL2/SDL.h>

#include "input.h"

Input::Input() {
    for (int i = 0; i < 255; ++i) {
        _keyboard[i] = false;
        _keyboardEnter[i] = false;
        _keyboardLeave[i] = false;
    }
}

Input::~Input() {

}

Input& Input::getInstance() {
    static Input instance;
    return instance;
}

void Input::processEvent(const SDL_Event & event) {
    SDL_GetMouseState(&_mousePos.x, &_mousePos.y);
    switch (event.type) {
    case SDL_KEYDOWN:
        if (event.key.keysym.sym < 255) {
            _keyboard[event.key.keysym.sym] = true;
            if (event.key.repeat == 0) {
                _keyboardEnter[event.key.keysym.sym] = true;
            }
        }
        break;
    case SDL_KEYUP:
        if (event.key.keysym.sym < 255) {
            _keyboard[event.key.keysym.sym] = false;
            _keyboardLeave[event.key.keysym.sym] = true;
        }
        break;
    case SDL_MOUSEBUTTONDOWN:
        _keyboard[event.button.button] = true;
        _keyboardEnter[event.button.button] = true;
        break;
    case SDL_MOUSEBUTTONUP:
        _keyboard[event.button.button] = false;
        _keyboardLeave[event.button.button] = true;
        break;
    default:
        break;
    }
}

bool Input::get(int id) const {
    return _keyboard[id];
}

bool Input::getEnter(int id) const {
    return _keyboardEnter[id];
}

bool Input::getLeave(int id) const {
    return _keyboardLeave[id];
}

const MousePos& Input::getMousePos() const {
    return _mousePos;
}

void Input::endFrame() {
    for (int i = 0; i < 255; ++i) {
        _keyboardEnter[i] = false;
        _keyboardLeave[i] = false;
    }
}
