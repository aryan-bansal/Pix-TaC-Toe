#ifndef ANIMATION_H 
#define ANIMATION_H

#include <SDL2/SDL.h>

extern SDL_Renderer* Renderer;

void Scroll_Background(SDL_Texture* texture, int* scroller, int i, const size_t width, const size_t height);

#endif
