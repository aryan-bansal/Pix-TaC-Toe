#include "../Headers/animation.h"

SDL_Renderer* Renderer;

void Scroll_Background(SDL_Texture *texture, int* scroller, int i, const size_t width, const size_t height)
{
    *scroller-=i;
    if(*scroller<-width){
        *scroller=0;
    }

    SDL_Rect Wall_1 = {*scroller, 0, width, height};
    SDL_RenderCopy(Renderer, texture, NULL, &Wall_1);

    SDL_Rect Wall_2 = {*scroller+width, 0, width, height};
    SDL_RenderCopy(Renderer, texture, NULL, &Wall_2);
}