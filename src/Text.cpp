#include "Text.hpp"
#include <SDL2/SDL_ttf.h>
#include <iostream>

Text::Text(SDL_Color color, SDL_Rect rect){
  this->color = color;
  this->Message_rect = rect;
  font = TTF_OpenFont("/home/kaan/software/PizzaLand_cpp/assets/Tinos-Regular.ttf", 24);
  std::cout << font << std::endl;
}

void Text::updateText(SDL_Renderer* renderer, std::string text, Uint8 extra_val){
  text=text + std::to_string(extra_val);
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), color);
  texture = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture
  SDL_FreeSurface(surfaceMessage);

}

void Text::render(SDL_Renderer* renderer){
  SDL_RenderCopy(renderer, texture, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture

}
