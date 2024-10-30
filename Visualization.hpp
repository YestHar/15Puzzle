#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include "Board.hpp"
#include <iostream>

class Visualization {
public:
    void displayBoard(const Board& board) const;
    void showInvalidMoveMessage() const;
    void showWinMessage() const;
};

#endif
