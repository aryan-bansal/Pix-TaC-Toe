#include "../Headers/event.h"

enum Key Button; 

SDL_Event Event;

enum Shape Player = cross;

bool Runner = true;

int Shape_Count = 0;

void Keys(enum Shape array[][3], enum Key* choice)
{
    switch(Event.key.keysym.sym){
        case SDLK_h: 
        *choice = home; 
        for (int i=0; i<3; ++i){
            for (int j=0; j<3; ++j){
                array[i][j] = empty;
            }
        }
        Shape_Count = 0;
        break;

        case SDLK_p: 
        *choice = play;
        break;

        case SDLK_r:
        for (int i=0; i<3; ++i){
            for (int j=0; j<3; ++j){
                array[i][j] = empty;
            }
        }
        Shape_Count = 0;
        break;

        case SDLK_q: 
        Runner = false; 
        break;
    }
}

void Turn(enum Shape array[][3], int i, int j)
{
    if(array[i][j]==empty){
        array[i][j] = Player;
        Shape_Count++;
        Player = (Player==cross) ? circle:cross;
    }
}

void Event_Handler(enum Shape array[][3], enum Key* choice, const size_t width, const size_t height)
{
    int Abscissa, Ordinate;

    while(SDL_PollEvent(&Event)){
        switch(Event.type){
            case SDL_QUIT: 
            Runner = false;
            break;
            
            case SDL_KEYDOWN:
            Keys(array, choice);
            break;

            case SDL_MOUSEBUTTONDOWN:
            SDL_GetMouseState(&Abscissa, &Ordinate);
            int X=Abscissa/(width/3);
            int Y=Ordinate/(height/3);

            Turn(array, X, Y);

            break;
        }
    }
}
