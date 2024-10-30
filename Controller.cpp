#include <iostream>
#include "Controller.hpp"

Controller::Controller() {}

void Controller::play() {
    game.startNewGame(); 
    updateView();

    while (!game.gameCompleted()) { 
        processInput(); 
        updateView(); 
    }

    std::cout << "Congratulations! You've solved the puzzle!" << std::endl; 
}

void Controller::processInput() {
    int direction;
    std::cout << "Enter move direction (8: Up, 2: Down, 4: Left, 6: Right): ";
    std::cin >> direction;

    if (!game.moveTile(direction)) {
        std::cout << "Invalid move. Try again." << std::endl; 
    }
}

void Controller::updateView() {
    visualization.displayBoard(game.getBoard()); 
}
