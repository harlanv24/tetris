#include "Game.h"
#include "Block.h"

Game::Game(SDL_Renderer* renderer, SDL_Rect* bg, Block& currBlock) : renderer(renderer), bg(*bg), board(), currBlock(currBlock) {
}

void Game::drawBlocks() {
    const uint16_t* shape = currBlock.getShape();
    
    for (int i = 0; i < 2; i++) { // Iterate through the two rows of the block shape
        for (int j = 0; j < board.ROW_SIZE; j++) { // Iterate through each bit in the `uint16_t`
            if (shape[i] & (1 << j)) { // Check if the j-th bit is set in the i-th row
                SDL_Rect cell;
                printf("%d\n", j);
                cell.x = bg.x + CELL_SIZE * j;
                cell.y = bg.y + CELL_SIZE * (currBlock.row + i);
                cell.w = CELL_SIZE;
                cell.h = CELL_SIZE;

                // Draw the cell background (outline)
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawRect(renderer, &cell);
                SDL_RenderFillRect(renderer, &cell);

                // Draw the cell fill (actual block color)
                const uint8_t* color = currBlock.getColor();
                SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], 255);
                cell.x += 1;
                cell.y += 1;
                cell.w = CELL_SIZE - 2;
                cell.h = CELL_SIZE - 2;
                SDL_RenderFillRect(renderer, &cell);
            }
        }
    }
}


bool Game::spawnBlock() {
    int idx = rand() % 7;
    //std::cout << idx << std::endl;
    Block newBlock = Block(blockTypes[idx]);
    uint16_t* currGridState = board.getGridState();
    const uint16_t* newShape = newBlock.getShape();
    if (newShape[1] & currGridState[1] != 0 || newShape[0] & currGridState[0] != 0) {
        return false;
    }
    currGridState[0] = newBlock.getShape()[0];
    currGridState[1] = newBlock.getShape()[1];
    //board.printBoardState();
    currBlock = newBlock;
    return true;
}

bool Game::blockBelow() {
    const uint16_t* currShape = currBlock.getShape();
    int row  = currBlock.row;
    // TODO: Fix this. Need better logic to prevent out of bounds checks on bottom rows
    if (row + 1 >= board.ROWS) {
        row = board.ROWS - 1;
    }
    // int x = ((currShape[1] & board.gridState[row + 2]) != 0);
    // int y = ((currShape[0] & board.gridState[row + 1]) != 0);
    // int z = currBlock.row == board.ROWS - 1;
    // std::cout << x << " " << y << " " << z << std::endl;
    // printf("Row: %d\n", row);
    // printf("Board: %d\n", board.gridState[0]);
    // printf("Board 1: %d\n", board.gridState[1]);
    return (((currShape[1] & board.gridState[row + 2]) != 0) || ((currShape[0] & board.gridState[row + 1]) != 0) || (currBlock.row == board.ROWS - 1));
}

void Game::tick() {
    if (blockBelow()) {
        // Spawn block logic here
        //std::cout << "Hello!" << std::endl;
        spawnBlock();
    }
    else {
        //std::cout << currBlock->row << std::endl;
        std::cout << currBlock.row << std::endl;
        uint16_t* currGridState = board.getGridState();
        for (int r = 0; r < board.ROWS; r++) {
            for (int c = 0; c < board.ROW_SIZE; c++) {
                bool filled = board.getCell(r, c);
                std::cout << (filled ? '1' : '0');
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        
        currGridState[currBlock.row] -= currBlock.getShape()[0];
        currGridState[currBlock.row + 1] -= currBlock.getShape()[1];
        currBlock.row += 1;
        currGridState[currBlock.row] += currBlock.getShape()[0];
        currGridState[currBlock.row + 1] += currBlock.getShape()[1];
        for (int r = 0; r < board.ROWS; r++) {
            for (int c = 0; c < board.ROW_SIZE; c++) {
                bool filled = board.getCell(r, c);
                std::cout << (filled ? '1' : '0');
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

    }
    drawBlocks();
    SDL_Delay(500);
}