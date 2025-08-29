#pragma once
#include <memory>
#include "../engine/Window.h"
#include "../engine/Renderer.h"
#include "../engine/Input.h"

/**
 * Simple game class
 */
class Game {
private:
    std::unique_ptr<Window> window;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Input> input;
    
    bool running;
    int targetFPS;
    float frameTime;

public:
    Game();
    ~Game();

    /**
     * Initialize the game
     */
    bool initialize(const std::string& title = "Vampire Game", int width = 1280, int height = 720);

    /**
     * Run the main game loop
     */
    void run();

    /**
     * Update game logic
     */
    void update();

    /**
     * Render game
     */
    void render();

    /**
     * Clean up resources
     */
    void cleanup();

    // Getters
    Window* getWindow() const { return window.get(); }
    Renderer* getRenderer() const { return renderer.get(); }
    Input* getInput() const { return input.get(); }
    
    bool isRunning() const { return running; }
    void quit() { running = false; }
};
