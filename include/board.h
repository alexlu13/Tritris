#ifndef BOARD_H
#define BOARD_H
#include <iostream>

class Board{

public:

    static const int HEIGHT = 20;
    static const int WIDTH = 10;
    static const int MAX_CLEAR = 3;

    Board();
    Board(const int b[HEIGHT][WIDTH]);
    int checkClearLines();
    friend std::ostream& operator<<(std::ostream &os, const Board &board);

private:
    int board[HEIGHT][WIDTH];

    void clearLine(int row);
    void collapseLines(const int cleared[]);
    void copyRow(int from, int to);
};

#endif // BOARD_H
