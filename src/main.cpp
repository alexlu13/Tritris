#include "gamehandler.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "board.h"
#include <string>

const bool TEST = true;
const int TEST_CASE = 6;

void testMain(int argc, char **argv) {
    // read in test board
    int board[Board::HEIGHT][Board::WIDTH];

    std::ifstream in;
    std::ostringstream file;
    file << "tests/testboard" << TEST_CASE << ".txt";
    std::string filename(file.str());
    std::cout << filename << std::endl;
    in.open(filename.c_str(), std::ifstream::in);
    if (!in) {
        std::cerr << "error opening file" << std::endl;
        return;
    }
    for (int i = Board::HEIGHT - 1; i >= 0; i--) {
        for (int j = 0; j < Board::WIDTH; j++) {
            in >> board[i][j];
        }
    }

    in.close();

    GameHandler gh = GameHandler(board);
    gh.testFunction();
    gh.initialize(argc, argv);
}

int main(int argc, char **argv) {
    if (TEST) {
        testMain(argc, argv);
    } else {
        GameHandler gh;
        gh.initialize(argc, argv);
    }
	return 0;
}
