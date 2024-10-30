#include "Game.hpp"

// Constructor initializes a new game by setting up the board
Game::Game() {
    startNewGame();
}

// Starts a new game by reinitializing the board
void Game::startNewGame() {
    board.initialize();
}

// Moves a tile in the specified direction: 
// 2 for down, 8 for up, 4 for left, and 6 for right
bool Game::moveTile(int direction) {
    auto zeroPos = board.findZero();
    int row = zeroPos.first;
    int col = zeroPos.second;

    switch (direction) {
        case 2: // Move down
            return board.swap(row, col, row - 1, col);
        case 8: // Move up
            return board.swap(row, col, row + 1, col);
        case 4: // Move left
            return board.swap(row, col, row, col + 1);
        case 6: // Move right
            return board.swap(row, col, row, col - 1);
        default:
            return false; // Invalid direction
    }
}

// Checks if the current board configuration is solved
bool Game::gameCompleted() const {
    return board.isBoardSolved();
}

const Board& Game::getBoard() const {
    return board; 
}