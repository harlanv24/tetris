#ifndef TETRISBOARD_H
#define TETRISBOARD_H

#include <bitset>

class TetrisBoard {
public:
    TetrisBoard();

    ~TetrisBoard();

    void setCell(int x, int y, bool filled);
    const bool flipCell(int x, int y);
    const bool getCell(int x, int y);
    uint16_t* getGridState();
    const bool rowCleared(int x);
    void clearBoard();
    void printBoardState();
    const int ROWS = 20;
    const int ROW_SIZE = 10;
    uint16_t* gridState;
};

#endif