#include "Game.h"
#include <SDL3/SDL.h>
#include <iostream>

Game::Game() : running(false), targetFPS(60), frameTime(1.0f / 60.0f) {
}

Game::~Game() {
    cleanup();
}

bool Game::initialize(const std::string& title, int width, int height) {
    // Create window
    window = std::make_unique<Window>(title, width, height);
    if (!window->initialize()) {
        std::cerr << "Failed to initialize window!" << std::endl;
        return false;
    }

    // Create renderer
    renderer = std::make_unique<Renderer>(window.get());
    if (!renderer->initialize()) {
        std::cerr << "Failed to initialize renderer!" << std::endl;
        return false;
    }

    // Create input system
    input = std::make_unique<Input>();
    if (!input->initialize()) {
        std::cerr << "Failed to initialize input!" << std::endl;
        return false;
    }

    running = true;
    return true;
}

void Game::run() {
    while (running) {
        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit();
            }
            input->handleEvent(event);
        }

        // Update game logic here
        update();

        // Render
        render();

        // Frame rate limiting
        SDL_Delay(static_cast<Uint32>(frameTime * 1000));
    }
}

void Game::update() {
    // Game update logic will go here
}

void Game::render() {
    // Set background color (black) and clear screen
    renderer->setDrawColor(0, 0, 0, 255);
    renderer->clear();
    
    // Draw a blue square that moves with WASD
    renderer->setDrawColor(0, 100, 255, 255);
    
    // Simple movement based on input
    static int squareX = 640;
    static int squareY = 360;
    const int speed = 10;
    const int squareSize = 50;
    
    if (input->isKeyPressed(SDLK_W) || input->isKeyPressed(SDLK_UP)) {
        squareY -= speed;
    }
    if (input->isKeyPressed(SDLK_S) || input->isKeyPressed(SDLK_DOWN)) {
        squareY += speed;
    }
    if (input->isKeyPressed(SDLK_A) || input->isKeyPressed(SDLK_LEFT)) {
        squareX -= speed;
    }
    if (input->isKeyPressed(SDLK_D) || input->isKeyPressed(SDLK_RIGHT)) {
        squareX += speed;
    }
    
    // Keep square on screen
    if (squareX < 0) squareX = 0;
    if (squareX > 1280 - squareSize) squareX = 1280 - squareSize;
    if (squareY < 0) squareY = 0;
    if (squareY > 720 - squareSize) squareY = 720 - squareSize;
    
    renderer->drawRect(squareX, squareY, squareSize, squareSize);
    
    renderer->present();
}

void Game::cleanup() {
    if (input) input.reset();
    if (renderer) renderer->cleanup();
    if (window) window->cleanup();
}
