#include "SDL2/SDL.h"
#include "Game.hpp"





int main(int argc, char const *argv[]) {

  const int FPS = 60;
  const int frameDelay = 1000 / FPS;
  Uint32 frameStart;
  int frameTime;

  Game *game = new Game("PizzaLand", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500);
  while(game->running()){

    frameStart = SDL_GetTicks();

    game->render();
    game->handleEvents();
    game->update();

    frameTime = SDL_GetTicks() - frameStart;
  //  std::cout << "processing frame took " << frameTime << "ms" << std::endl;

    if(frameDelay > frameTime){
      SDL_Delay(frameDelay - frameTime);
    }
  }
  delete game;
  return 0;
}
