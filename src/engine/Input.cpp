#include "Input.h"

Input::Input() : mouseX(0), mouseY(0) {
}

Input::~Input() {
}

bool Input::initialize() {
    // Initialize mouse position
    float x, y;
    SDL_GetMouseState(&x, &y);
    mouseX = static_cast<int>(x);
    mouseY = static_cast<int>(y);
    
    return true;
}

void Input::handleEvent(const SDL_Event& event) {
    switch (event.type) {
        case SDL_EVENT_KEY_DOWN:
            keyStates[event.key.key] = true;
            break;
            
        case SDL_EVENT_KEY_UP:
            keyStates[event.key.key] = false;
            break;
    }
}

bool Input::isKeyPressed(SDL_Keycode key) const {
    auto it = keyStates.find(key);
    return it != keyStates.end() && it->second;
}
