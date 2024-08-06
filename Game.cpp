#include "Game.h"

Game::Game(SDL_Renderer* renderer, SDL_Rect* bg) : renderer(renderer), bg(*bg), board() {}