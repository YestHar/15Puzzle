#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Game.hpp"
#include "Visualization.hpp"

class Controller {
public:
    Controller();
    void play();

private:
    Game game;
    Visualization visualization;
    void processInput();
    void updateView();
};

#endif