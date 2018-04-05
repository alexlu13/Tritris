#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include "board.h"

class GameHandler {

private:
    Board board;

public:
    GameHandler();
    GameHandler(const int b[Board::HEIGHT][Board::WIDTH]);
    void initialize(int argc, char* argv[]);
    void handleGame();
    void testFunction();
};

#endif // GAMEHANDLER_H
