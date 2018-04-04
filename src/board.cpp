#include "board.h"

// Board default constructor
Board::Board() {

    // initializes the board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = 0;
        }
    }
}

void Board::clearLine(int row) {
}

// check the lines of the board to see if lines need to be cleared
// TODO: return the score increase
int Board::checkClearLines() {

    // since this is Tritris, the most lines the player can clear at once is 3
    int clearedLines[MAX_CLEAR] = {0, 0, 0};
    int numCleared = 0;
    int base = -1;
    bool toClear = true;
    // check each row
    for (int i = 0; i < height; i++) {

        // can only clear 3 blocks, so don't check above
        if (base != -1 && i > base + MAX_CLEAR) {
            break;
        }
        // check along the columns
        for (int j = 0; j < width && toClear; j++) {
            if (!this.board[i][j]) {
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

    }

    return 0;
}
