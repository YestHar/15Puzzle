#ifndef BOARD_HPP
#define BOARD_HPP

#include <utility>

const int SIZE = 4;

class Board {
public:
    Board();
    void initialize();
    int getTile(int row, int col) const;
    bool isBoardSolved() const;
    bool swap(int row1, int col1, int row2, int col2);
    std::pair<int, int> findZero() const;
    int getSize() const;
private:
    int grid[SIZE][SIZE];
    bool isSolvable(int numbers[]) const;
    
};

#endif
