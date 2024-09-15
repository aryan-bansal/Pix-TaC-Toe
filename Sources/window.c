#include "../Headers/window.h"

SDL_Window* Window;

extern SDL_Renderer* Renderer;

void SDL_Start(const size_t width, const size_t height)
{
    SDL_Init(SDL_INIT_EVERYTHING);
		Window = SDL_CreateWindow( "TIC TAC TOE", SDL_WINDOWPOS_CENTERED, 
                            SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
		Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
}

void SDL_End()
{
    SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}
