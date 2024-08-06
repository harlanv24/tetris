#include "Block.h"

Block::Block(BlockType type) : type(type), row(0), col(3) {
    initializeBlock();
}

const BlockType Block::getType() {
    return type;
}

const uint16_t* Block::getShape() {
    return shape;
}

void Block::rotate() {
    // TODO: Implement movement
}

void Block::moveLeft() {
    // TODO: Implement movement
}

void Block::moveRight() {
    // TODO: Implement movement
}

void Block::moveDown() {
    // TODO: Implement movement
}

void Block::initializeBlock() {
    switch(type) {
        case I:
            shape[0] = 0b0001111000;
            shape[1] = 0b0000000000;
            color[0] = 0;
            color[1] = 255;
            color[2] = 255;
            break;
        case O:
            shape[0] = 0b0001100000;
            shape[1] = 0b0001100000;
            color[0] = 255;
            color[1] = 255;
            color[2] = 0;
            break;
        case T:
            shape[0] = 0b0001110000;
            shape[1] = 0b0000100000;
            color[0] = 128;
            color[1] = 0;
            color[2] = 128;
            break;
        case S:
            shape[0] = 0b0000110000;
            shape[1] = 0b0001100000;
            color[0] = 0;
            color[1] = 255;
            color[2] = 0;
            break;
        case Z:
            shape[0] = 0b0000110000;
            shape[1] = 0b0000011000;
            color[0] = 255;
            color[1] = 0;
            color[2] = 0;
            break;
        case J:
            shape[0] = 0b0001000000;
            shape[1] = 0b0001110000;
            color[0] = 0;
            color[1] = 0;
            color[2] = 255;
            break;
        case L:
            shape[0] = 0b0000010000;
            shape[1] = 0b0001110000;
            color[0] = 255;
            color[1] = 165;
            color[2] = 0;
            break;
    }
}