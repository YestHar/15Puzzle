#include "Visualization.hpp"

void Visualization::displayBoard(const Board& board) const {
    const int SIZE = board.getSize(); 
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int tileValue = board.getTile(i, j);
            if (tileValue == 0) {
                std::cout << " \t"; 
            } else {
                std::cout << tileValue << "\t";
            }
        }
        std::cout << std::endl; 
    }
}
