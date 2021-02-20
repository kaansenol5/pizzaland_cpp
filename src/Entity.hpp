#pragma once
#include <SDL2/SDL.h>
#include <iostream>

class Entity{
public:
  Entity(SDL_Renderer* renderer, short x, short y, short width, short height, SDL_Surface* surface);
  ~Entity();
  void update();
  void move(short X_Diff, short Y_Diff);
  void render(SDL_Renderer* renderer);
  SDL_Texture* texture;
  SDL_Rect dstrect;
  struct Hitbox{
    short x;
    short y;
    short w;
    short h;
  };
  Hitbox hitbox;
  Uint8 movement_speed = 3;



};
