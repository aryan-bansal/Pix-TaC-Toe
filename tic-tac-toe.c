#include <stdio.h>

#include "Headers/window.h"
#include "Headers/event.h"
#include "Headers/animation.h"
#include "Headers/gameplay.h"


int main(int argc, char* argv[])
{
    const size_t WIDTH = 700;
    const size_t HEIGHT = 700;

    SDL_Start(WIDTH, HEIGHT);

    SDL_Texture* Texture_Home = IMG_LoadTexture(Renderer, "Resources/Home.png");
    SDL_Rect Home_Size = {9*WIDTH/40, HEIGHT/20, 11*WIDTH/20, 9*HEIGHT/10};

    int Scroller_1 = 0, Scroller_2 = 0;

    SDL_Texture* Background_1 = IMG_LoadTexture(Renderer, "Resources/B_1.png");
    SDL_Texture* Background_2 = IMG_LoadTexture(Renderer, "Resources/B_2.png");

    SDL_Texture* Texture_X = IMG_LoadTexture(Renderer, "Resources/X.png");
    SDL_Texture* Texture_O = IMG_LoadTexture(Renderer, "Resources/O.png");

    enum Shape State[3][3] = {{empty}};

    SDL_Texture * Texture_Win_X = IMG_LoadTexture(Renderer, "Resources/Win_X.png");
    SDL_Texture * Texture_Win_O = IMG_LoadTexture(Renderer, "Resources/Win_O.png");
    SDL_Texture* Texture_Tie = IMG_LoadTexture(Renderer, "Resources/Tie.png");


    while(Runner){

        switch(Button){
            case home:
            SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
            SDL_RenderClear(Renderer);

            Scroll_Background(Background_1, &Scroller_1, 5, WIDTH, HEIGHT);
            Scroll_Background(Background_2, &Scroller_2, 8, WIDTH, HEIGHT);
            
            SDL_RenderCopy(Renderer, Texture_Home, NULL, &Home_Size);
            SDL_RenderPresent(Renderer);
            break;

            case play:
            Maker(Texture_X, Texture_O, Texture_Win_O, Texture_Win_X, Texture_Tie, State, WIDTH/3, HEIGHT/3);
            break;

            default:
            break;
        }

        Event_Handler(State, &Button, WIDTH, HEIGHT);
    }
    
    SDL_End();

	return EXIT_SUCCESS;
}