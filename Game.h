#ifndef GAME_H
#define GAME_H

#include <vector>
#include <bitset>
#include <SDL2/SDL.h>
#include "TetrisBoard.h"
#include "Block.h"
const int CELL_SIZE = 35;

class Game {
public:
    Game(SDL_Renderer* renderer, SDL_Rect* bg);

    ~Game();
    
    void drawBlocks();
    bool blockBelow();
    bool spawnBlock();
    void tick();

private:
    BlockType blockTypes[7] = {I, O, T, S, Z, J, L};
    Block currBlock;
    TetrisBoard board;
    SDL_Renderer* renderer;
    SDL_Rect bg;
};

#endif