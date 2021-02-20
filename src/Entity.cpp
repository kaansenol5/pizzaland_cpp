#include "Entity.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Entity::Entity(SDL_Renderer* renderer, short x, short y, short width, short height, SDL_Surface* surface){
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  dstrect.x = x;
  dstrect.y = y;
  dstrect.h = height;
  dstrect.w = width;

  std::cout << "New entity initialized with asset directory " << std::endl;

}

void Entity::render(SDL_Renderer* renderer){
  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
  SDL_RenderDrawRect(renderer, &dstrect);

}

Entity::~Entity(){
  SDL_DestroyTexture(texture);
}

void Entity::update(){

}

void Entity::move(short X_Diff, short Y_Diff){
  dstrect.x += X_Diff * movement_speed;
  dstrect.y += Y_Diff * movement_speed;
}
