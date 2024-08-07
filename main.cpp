#include <SDL2/SDL.h>
#include <iostream>
#include "TetrisBoard.h"
#include "Block.h"
#include "Game.h"

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;


int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_EVENTS) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Rect bg;
    // 10 x 20 canvas of 35 x 35 px squares
    bg.x = WINDOW_WIDTH  * 17 / 48;
    bg.y = WINDOW_HEIGHT / 16;
    bg.w = WINDOW_WIDTH * 7 / 24; // 350 px 
    bg.h = WINDOW_HEIGHT * 7 / 8; // 700 px

    Game game(renderer, &bg);

    // Main game loop
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear the screen with a black color
        SDL_SetRenderDrawColor(renderer, 214, 186, 196, 255);
        SDL_RenderClear(renderer);

        // Render your game here
        if (SDL_RenderDrawRect(renderer, &bg) != 0) {
            std::cerr << "SDL_RenderDrawRect Error: " << SDL_GetError() << std::endl;
        }

        SDL_SetRenderDrawColor(renderer, 85, 106, 181, 255);
        if (SDL_RenderFillRect(renderer, &bg) != 0) {
            std::cerr << "SDL_RenderFillRect Error: " << SDL_GetError() << std::endl;
        }
        

        // Present the backbuffer
        SDL_RenderPresent(renderer);
    }



    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

