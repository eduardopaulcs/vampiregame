#include "Window.h"
#include <iostream>

Window::Window(const std::string& title, int width, int height)
    : window(nullptr), width(width), height(height), title(title) {
}

Window::~Window() {
    cleanup();
}

bool Window::initialize() {
    // Initialize SDL if not already done
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create window
    window = SDL_CreateWindow(
        title.c_str(),
        width,
        height,
        SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void Window::cleanup() {
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
}
