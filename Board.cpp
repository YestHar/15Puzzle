#include "Board.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

Board::Board() {
    initialize();
}

// Initializes the board with a solvable random configuration
void Board::initialize() {
    int numbers[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; i++) {
        numbers[i] = i;
    }

    // Shuffle until the grid is solvable
    do {
        std::srand(std::time(0));
        std::random_shuffle(std::begin(numbers), std::end(numbers));
    } while (!isSolvable(numbers));

    // Fill the grid with shuffled numbers
    int index = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = numbers[index++];
        }
    }
}

// Checks if the grid is in the solved state
bool Board::isBoardSolved() const {
    int counter = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == SIZE - 1 && j == SIZE - 1) {
                return grid[i][j] == 0; // Bottom-right should be the empty tile
            }
            if (grid[i][j] != counter++) {
                return false;
            }
        }
    }
    return true;
}

// Returns the tile value at a specific position
int Board::getTile(int row, int col) const {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
        return grid[row][col];
    }
    return -1; // Invalid position
}

// Swaps two tiles in the grid
bool Board::swap(int row1, int col1, int row2, int col2) {
    if (row1 >= 0 && row1 < SIZE && col1 >= 0 && col1 < SIZE &&
        row2 >= 0 && row2 < SIZE && col2 >= 0 && col2 < SIZE) {
        std::swap(grid[row1][col1], grid[row2][col2]);
        return true;
    }
    return false;
}

// Helper function to check if the current puzzle configuration is solvable
bool Board::isSolvable(int numbers[]) const {
    int inversions = 0;
    for (int i = 0; i < SIZE * SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE * SIZE; j++) {
            if (numbers[i] > numbers[j] && numbers[i] != 0 && numbers[j] != 0) {
                inversions++;
            }
        }
    }
    return inversions % 2 == 0;
}

// Finds the position of the empty tile (0) in the grid
std::pair<int, int> Board::findZero() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                return {i, j};
            }
        }
    }
    return {-1, -1}; // This should never happen if the grid is properly initialized
}


int Board::getSize() const{
    return SIZE;
}