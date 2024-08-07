#include "Game.h"

Game::Game(SDL_Renderer* renderer, SDL_Rect* bg) : renderer(renderer), bg(*bg), board(), currBlock(I) {}

void Game::drawBlocks() {
        SDL_Rect cell;
        cell.x = bg.x + CELL_SIZE * currBlock.col;
        cell.y = bg.y + CELL_SIZE * currBlock.row;
        const uint8_t* color = currBlock.getColor();
        cell.w = CELL_SIZE;
        cell.h = CELL_SIZE;
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &cell);
        SDL_RenderFillRect(renderer, &cell);
        SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
        cell.x += 1;
        cell.y += 1;
        cell.w = CELL_SIZE - 2;
        cell.h = CELL_SIZE - 2;
        SDL_RenderFillRect(renderer, &cell);
}

bool Game::spawnBlock() {
    Block newBlock = Block(blockTypes[rand() % 7]);
    uint16_t* currGridState = board.getGridState();
    const uint16_t* newShape = newBlock.getShape();
    if (newShape[1] & currGridState[1] != 0 || newShape[0] & currGridState[0] != 0) {
        return false;
    }
    currGridState[0] = newBlock.getShape()[0];
    currGridState[1] = newBlock.getShape()[1];
    currBlock = newBlock;
    return true;
}

bool Game::blockBelow() {
    const uint16_t* currShape = currBlock.getShape();
    int row  = currBlock.row;
    if (row + 2 >= board.ROWS) {
        row = board.ROWS - 2;
    }
    return (currShape[1] & board.gridState[row + 2] != 0 || currShape[0] & board.gridState[row + 1] != 0);
}

void Game::tick() {
    if (blockBelow) {
        // Spawn block logic here
    }
}