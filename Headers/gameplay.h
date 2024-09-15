#ifndef GAMEPLAY_H 
#define GAMEPLAY_H

#include "event.h"

void Box(SDL_Rect rect, int R, int G, int B);

void Drawer(SDL_Texture* texture_1, SDL_Texture* texture_2, enum Shape array[][3], SDL_Rect rect, int i, int j);

bool Result(enum Shape array[][3]);

void Maker(SDL_Texture* texture_1, SDL_Texture* texture_2, SDL_Texture* texture_3, SDL_Texture* texture_4, SDL_Texture* texture_5, enum Shape array[][3], const size_t width, const size_t height);

#endif

