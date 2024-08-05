#ifndef TETRISBOARD_H
#define TETRISBOARD_H

#include <vector>
#include <bitset>

class TetrisBoard {
public:
    TetrisBoard();

    ~TetrisBoard();

    void setCell(int x, int y, bool filled);
    const bool flipCell(int x, int y);
    const bool getCell(int x, int y);
    const uint16_t* getGridState();
    void clearBoard();
    void printBoardState();
    const int ROWS = 20;
    const int ROW_SIZE = 10;

private:
    uint16_t* gridState;
};

#endif