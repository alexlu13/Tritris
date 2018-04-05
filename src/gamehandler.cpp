#include "gamehandler.h"
#include "renderer.h"
#include <iostream>
#include "board.h"

GameHandler::GameHandler() {}

GameHandler::GameHandler(const int b[Board::HEIGHT][Board::WIDTH]) {
    this->board = Board(b);
}

// function to test stuff
void GameHandler::testFunction(){
    std::cout << "Before" << std::endl;
    std::cout << this->board << std::endl;
    this->board.checkClearLines();
    std::cout << "After" << std::endl;
    std::cout << this->board << std::endl;
}

void GameHandler::handleGame() {
    // TODO
}

void GameHandler::initialize(int argc, char* argv[]) {
    // for now, just do text output and get game logic going
    // renderer::initialize(argc, argv);


}
