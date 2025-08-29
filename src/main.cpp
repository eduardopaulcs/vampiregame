#include <iostream>
#include "game/Game.h"

int main() {
    std::cout << "Starting Vampire Game..." << std::endl;
    
    Game game;
    
    if (!game.initialize("Vampire Game", 1280, 720)) {
        std::cerr << "Failed to initialize game!" << std::endl;
        return 1;
    }
    
    std::cout << "Game initialized successfully!" << std::endl;
    std::cout << "Use WASD or arrow keys to move the blue square" << std::endl;
    std::cout << "Close the window to quit" << std::endl;
    
    game.run();
    
    std::cout << "Game finished!" << std::endl;
    return 0;
}
