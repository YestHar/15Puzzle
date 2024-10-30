#include <iostream>
#include "Controller.hpp"

// Constructor initializes the Controller
Controller::Controller() {}

// Main game loop to handle gameplay
void Controller::play() {
    game.startNewGame(); // Start a new game
    updateView(); // Display the initial state of the game

    while (!game.gameCompleted()) { // Continue until the game is solved
        processInput(); // Get user input
        updateView(); // Update the display
    }

    std::cout << "Congratulations! You've solved the puzzle!" << std::endl; // Notify the player when solved
}

// Processes user input for moving tiles
void Controller::processInput() {
    int direction;
    std::cout << "Enter move direction (8: Up, 2: Down, 4: Left, 6: Right): ";
    std::cin >> direction;

    if (!game.moveTile(direction)) {
        std::cout << "Invalid move. Try again." << std::endl; // Handle invalid moves
    }
}

// Updates the visual representation of the game board
void Controller::updateView() {
    visualization.displayBoard(game.getBoard()); // Display the current state of the board
}
