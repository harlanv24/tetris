#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>

enum BlockType {
    I, O, T, S, Z, J, L
};

class Block {
public:
    Block(BlockType type);

    ~Block();

    const BlockType getType();
    const uint16_t* getShape();
    void rotate();
    void moveLeft();
    void moveRight();
    void moveDown();

private:
    BlockType type;
    uint16_t shape[2];
    uint8_t color[3];
    int row, col;
    void initializeBlock();
};

#endif