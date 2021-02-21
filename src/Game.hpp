#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Entity.hpp"
#include <SDL2/SDL_ttf.h>
#include "Text.hpp"

class Game{

public:
  Game(const char* title, int x, int y, int w, int h);
  ~Game();

  void update();
  void render();
  void handleEvents();
  bool running();
  bool calculateCollusion(SDL_Rect a, SDL_Rect b);


private:
  void levelSystem();
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
  Uint8 score = 0;
  Uint8 misses = 0;
  Uint8 level =0;
  Entity* player;
  Entity* background;
  Entity* pizza;
  Text* scoreText;
  Text* missesText;
  Text* levelText;
  Text* GameWonText;
  Text* MaxSpeedText;
  bool over = false;

};
