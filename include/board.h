#ifndef BOARD_H
#define BOARD_H

class Board{

private:
    static const int HEIGHT = 20;
    static const int WIDTH = 10;
    static const int MAX_CLEAR = 3;
    int board[HEIGHT][WIDTH];

    void clearLine(int row);
    void collapseLines();
    void copyRow(int from, int to);
public:
    Board();
    int checkClearLines();

};

#endif // BOARD_H
