#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "board.h"

class GameHandler {

private:
    Board board;

public:
    GameHandler();
    void initialize(int argc, char* argv[]);
    void handleGame();
};

#endif // GAMEHANDLER_H
