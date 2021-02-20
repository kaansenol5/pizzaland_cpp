#include "Game.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Entity.hpp"
#include <string>
#include <fstream>

Game::Game(const char* title, int x, int y, int w, int h){
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    TTF_Init();
    std::cout << "Init" << std::endl;

    window = SDL_CreateWindow(title, x, y, w, h, 0);
    if(window){
      std::cout << "window created" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer){
      SDL_SetRenderDrawColor(renderer, 255,255,255,255);
      std::cout << "renderer created" << std::endl;
    }
    isRunning = true;

    //initialize entities that are displayed on window
    player = new Entity(renderer,50,320,96,96,IMG_Load("assets/canvas.png"));;
    background = new Entity(renderer,0,0,500,500,IMG_Load("assets/bg.jpg"));;
    pizza = new Entity(renderer,0,0,96,96,IMG_Load("assets/pizza.png"));;
    scoreText = new Text({0,255,0},{0,0,130,70});
    missesText = new Text({255,0,0},{370,0,130,70});
  }
  else{
    isRunning = false;
  }
}

void Game::handleEvents(){
  SDL_Event event;
  const Uint8 *state = SDL_GetKeyboardState(NULL);

  if(state[SDL_SCANCODE_A]){
    player->dstrect.x -= player->movement_speed;
  }
  if(state[SDL_SCANCODE_D]){
    player->dstrect.x += player->movement_speed;
  }
  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    default:
      break;
  }
}

void Game::update(){
  pizza->dstrect.y += pizza->movement_speed;
  if(calculateCollusion(pizza->dstrect, player->dstrect)){
    score++;
    levelSystem();
    pizza->dstrect.y=0;
    pizza->dstrect.x = rand() % 404;
  }
  else if(pizza->dstrect.y > player->dstrect.y + player->dstrect.h){
    misses++;
    pizza->dstrect.y=0;
    pizza->dstrect.x = rand() % 404;

  }
  scoreText->updateText(renderer, "Score: ", score);
  missesText->updateText(renderer, "Misses: ", misses);
  if(score==0){
    level=0;
    player->movement_speed=3;
    pizza->movement_speed=3;
  }
  if(misses>5){
    score=0;
    misses=0;
  }
}

void Game::render(){
  SDL_RenderClear(renderer);
//render entities
  background->render(renderer);
  player->render(renderer);
  pizza->render(renderer);

//render text
  scoreText->render(renderer);
  missesText->render(renderer);
  SDL_RenderPresent(renderer);


}

Game::~Game(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Bye" << std::endl;
  delete player;
  delete background;
}

bool Game::calculateCollusion(SDL_Rect obj1, SDL_Rect obj2){
  if((obj1.x >= obj2.x && obj1.x <= obj2.x + obj2.w) || (obj1.x+obj1.w > obj2.x && obj1.x+obj1.w < obj2.x+obj2.w) ){
    if(obj1.y + obj1.h >= obj2.y && obj1.y <= obj2.y + obj2.h){
      return true;
    }
  }
  return false;
  }


bool Game::running(){
  return isRunning;
}

void Game::levelSystem(){
  if(score % 10 == 0 && score != 0){
    level++;
    std::cout << unsigned(level) << std::endl;
    std::cout << unsigned(player->movement_speed) << std::endl;
    std::cout << unsigned(pizza->movement_speed) << std::endl;

    if(player->movement_speed < 9){
      player->movement_speed += level;
    }
    if(pizza->movement_speed < 9){
      pizza->movement_speed += level;
    }
  }
}
