#include "SDL2/SDL_ttf.h"
#include <string>

class Text{
public:
  Text(SDL_Color color, SDL_Rect rect);
  ~Text();
  void updateText(SDL_Renderer* renderer, std::string text, Uint8 extra_val);
  void render(SDL_Renderer* renderer);
private:
  TTF_Font* font;
  SDL_Texture* texture;
  SDL_Color color;
  SDL_Rect Message_rect;
};
