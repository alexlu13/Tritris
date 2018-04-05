#include "board.h"
#include <iostream>

// Board default constructor
Board::Board() {

    // initializes the board
    for (int i = 0; i < Board::HEIGHT; i++) {
        for (int j = 0; j < Board::WIDTH; j++) {
            this->board[i][j] = 0;
        }
    }
}

Board::Board(const int b[Board::HEIGHT][Board::WIDTH]) {
    for (int i = 0; i < Board::HEIGHT; i++) {
        for (int j = 0; j < Board::WIDTH; j++) {
            this->board[i][j] = b[i][j];
        }
    }
}

// clear one line
void Board::clearLine(int row) {
    for (int i = 0; i < Board::WIDTH; i++) {
        this->board[row][i] = 0;
    }
}

void Board::copyRow(int from, int to) {
    for (int i = 0; i < Board::WIDTH; i++) {
        this->board[to][i] = this->board[from][i];
    }
}

// collapse all of the lines after clearing a line
void Board::collapseLines(const int cleared[]) {
    int base;
    int top;
    for (int i = 0; i < Board::MAX_CLEAR && cleared[i] != -1; i++) {
        base = cleared[i];
        top = (i == Board::MAX_CLEAR - 1
                || cleared[i + 1] == -1) ? Board::HEIGHT : cleared[i + 1];
        std::cout << "top: " << top << std::endl;
        for (int j = base + 1; j < top; j++) {
            copyRow(j, j-1);
            clearLine(j);
        }
    }
}

// check the lines of the board to see if lines need to be cleared
// TODO: return the score increase
int Board::checkClearLines() {

    // since this is Tritris, the most lines the player can clear at once is 3
    int clearedLines[Board::MAX_CLEAR] = {-1, -1, -1};
    int numCleared = 0;
    int base = -1;
    bool toClear;
    // check each row
    for (int i = 0; i < Board::HEIGHT; i++) {
        toClear = true;
        // can only clear 3 blocks, so don't check above
        if (base != -1 && i > base + Board::MAX_CLEAR - 1) {
            break;
        }
        // check along the columns
        for (int j = 0; j < Board::WIDTH && toClear; j++) {
            if (!this->board[i][j]) {
                toClear = false;
            }
        }

        // need to clear this line as well
        if (toClear) {
            clearedLines[numCleared] = i;
            numCleared++;
            if (base == -1) {
                base = i;
            }
        }
    }

    for (int i = 0; i < numCleared; i++) {
        this->clearLine(clearedLines[i]);
    }

    collapseLines(clearedLines);
    return 0;
}

// overloaded output operator
std::ostream& operator<<(std::ostream &os, const Board &board) {

    for (int i = Board::HEIGHT - 1; i >= 0; i--) {
        for (int j = 0; j < Board::WIDTH; j++) {
            os << board.board[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}
