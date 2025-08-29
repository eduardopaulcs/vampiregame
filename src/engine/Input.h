#pragma once
#include <SDL3/SDL.h>
#include <unordered_map>

/**
 * Simple input handling system
 */
class Input {
private:
    std::unordered_map<SDL_Keycode, bool> keyStates;
    int mouseX, mouseY;

public:
    Input();
    ~Input();

    /**
     * Initialize input system
     */
    bool initialize();

    /**
     * Handle SDL event
     */
    void handleEvent(const SDL_Event& event);

    // Keyboard input
    bool isKeyPressed(SDL_Keycode key) const;
};
