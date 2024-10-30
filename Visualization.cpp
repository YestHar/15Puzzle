#include "Visualization.hpp"

// Displays the current state of the board in a grid format
void Visualization::displayBoard(const Board& board) const {
    const int SIZE = board.getSize(); // Assuming getSize() method is implemented in Board
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int tileValue = board.getTile(i, j); // Assuming getTile(row, col) method is implemented in Board
            if (tileValue == 0) {
                std::cout << " \t"; // Represent empty space
            } else {
                std::cout << tileValue << "\t";
            }
        }
        std::cout << std::endl; // Newline after each row
    }
}


void Visualization::showInvalidMoveMessage() const {
    std::cout << "Invalid move! Try a different direction." << std::endl;
}

void Visualization::showWinMessage() const {
    std::cout << "Congratulations! You solved the puzzle!" << std::endl;
}
