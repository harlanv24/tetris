#include "TetrisBoard.h"
#include <iostream>
#include <cstdint>
#include <cstring>

TetrisBoard::TetrisBoard(): gridState(new uint16_t[ROWS]()) {}

TetrisBoard::~TetrisBoard() {
    delete[] gridState;
}

void TetrisBoard::setCell(int x, int y, bool filled) {
    if ((x < 0 || x >= ROWS) || (y < 0 || y >= ROW_SIZE)) {
        throw std::out_of_range("Index out of range");
    } 
    if(filled) {
        gridState[x] |= (1 << y);
    }
    else {
        gridState[x] &= ~(1 << y);
    }
};

const bool TetrisBoard::flipCell(int x, int y) {
    if ((x < 0 || x >= ROWS) || (y < 0 || y >= ROW_SIZE)) {
        throw std::out_of_range("Index out of range");
    } 
    gridState[x] ^= (1 << y);
    return TetrisBoard::getCell(x, y);
}

const bool TetrisBoard::getCell(int x, int y) {
    if ((x < 0 || x >= ROWS) || (y < 0 || y >= ROW_SIZE)) {
        throw std::out_of_range("Index out of range");
    }
    return (gridState[x] & (1 << y)) != 0;
}

uint16_t* TetrisBoard::getGridState() {
    return gridState;
}

void TetrisBoard::clearBoard() {
    std::memset(gridState, 0, ROWS * sizeof(uint16_t));
}

void TetrisBoard::printBoardState() {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < ROW_SIZE; c++) {
            bool filled = TetrisBoard::getCell(r, c);
            std::cout << (filled ? '1' : '0');
        }
        std::cout << std::endl;
    }
}

const bool TetrisBoard::rowCleared(int x) {
    return gridState[x] == 0;
}