#ifndef BOARD_H
#define BOARD_H

class Board{

private:
    const int HEIGHT = 20;
    const int WIDTH = 10;
    const int MAX_CLEAR = 3;
    int board[HEIGHT][WIDTH];

    void clearLine(int row);

public:
    Board();
    int checkClearLines();

};

#endif // BOARD_H
