#pragma once
#include <SDL3/SDL.h>
#include <string>

/**
 * Simple window management
 */
class Window {
private:
    SDL_Window* window;
    int width;
    int height;
    std::string title;

public:
    Window(const std::string& title, int width, int height);
    ~Window();

    /**
     * Initialize window
     */
    bool initialize();

    /**
     * Clean up resources
     */
    void cleanup();

    /**
     * Get SDL window
     */
    SDL_Window* getWindow() const { return window; }

    /**
     * Get window dimensions
     */
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};
