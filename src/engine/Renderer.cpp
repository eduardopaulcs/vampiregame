#include "Renderer.h"
#include "Window.h"
#include <iostream>

Renderer::Renderer(Window* window) : renderer(nullptr), window(window) {
}

Renderer::~Renderer() {
    cleanup();
}

bool Renderer::initialize() {
    if (!window) {
        std::cerr << "Window is not valid!" << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window->getWindow(), nullptr);
    
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Set default draw color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    return true;
}

void Renderer::cleanup() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }
}

void Renderer::clear() {
    if (renderer) {
        SDL_RenderClear(renderer);
    }
}

void Renderer::present() {
    if (renderer) {
        SDL_RenderPresent(renderer);
    }
}

void Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    if (renderer) {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
    }
}

void Renderer::drawRect(int x, int y, int width, int height) {
    if (renderer) {
        SDL_FRect rect = { static_cast<float>(x), static_cast<float>(y), 
                          static_cast<float>(width), static_cast<float>(height) };
        SDL_RenderFillRect(renderer, &rect);
    }
}
