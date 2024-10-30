#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"

class Game {
public:
    Game();
    void startNewGame();
    bool moveTile(int direction);
    bool gameCompleted() const;
    const Board& getBoard() const; 
private:
    Board board;
};

#endif //GAME_HPP