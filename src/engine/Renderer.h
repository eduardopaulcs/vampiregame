#pragma once
#include <SDL3/SDL.h>
#include <string>

// Forward declaration
class Window;

/**
 * Simple rendering system
 */
class Renderer {
private:
    SDL_Renderer* renderer;
    Window* window;

public:
    Renderer(Window* window);
    ~Renderer();

    /**
     * Initialize renderer
     */
    bool initialize();

    /**
     * Clean up resources
     */
    void cleanup();

    /**
     * Clear screen
     */
    void clear();

    /**
     * Present rendered content
     */
    void present();

    /**
     * Set draw color
     */
    void setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

    /**
     * Draw a filled rectangle
     */
    void drawRect(int x, int y, int width, int height);

    /**
     * Get SDL renderer
     */
    SDL_Renderer* getRenderer() const { return renderer; }
};
