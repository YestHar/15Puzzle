#include "Game.hpp"

Game::Game() {
    startNewGame();
}

void Game::startNewGame() {
    board.initialize();
}


bool Game::moveTile(int direction) {
    auto zeroPos = board.findZero();
    int row = zeroPos.first;
    int col = zeroPos.second;

    switch (direction) {
        case 2: 
            return board.swap(row, col, row - 1, col);
        case 8: 
            return board.swap(row, col, row + 1, col);
        case 4: 
            return board.swap(row, col, row, col + 1);
        case 6: 
            return board.swap(row, col, row, col - 1);
        default:
            return false; 
    }
}

bool Game::gameCompleted() const {
    return board.isBoardSolved();
}

const Board& Game::getBoard() const {
    return board; 
}