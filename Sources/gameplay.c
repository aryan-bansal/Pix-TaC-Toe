#include "../Headers/gameplay.h"

extern SDL_Renderer* Renderer;

void Box(SDL_Rect rect, int R, int G, int B)
{
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    SDL_RenderFillRect(Renderer, &rect);
}

void Drawer(SDL_Texture* texture_1, SDL_Texture* texture_2, enum Shape array[][3], SDL_Rect rect, int i, int j)
{   
    switch(array[i][j]){
    case cross:
    SDL_RenderCopy(Renderer, texture_1, NULL, &rect);
    break;

    case circle:
    SDL_RenderCopy(Renderer, texture_2, NULL, &rect);
    break;

    default: ;
    }
}

bool Result(enum Shape array[][3])
{
    for(int j=0; j<3; ++j){
        if(array[0][j]==array[1][j] && array[0][j]==array[2][j] && array[0][j]!=empty){
            return true;
        }
        else if(array[j][0]==array[j][1] && array[j][0]==array[j][2] && array[j][0]!=empty){
            return true; 
        }
    }
    if(array[0][0]==array[2][2] && array[0][0]==array[1][1] && array[0][0]!=empty){
        return true;
    }
    else if(array[2][0]==array[0][2] && array[2][0]==array[1][1] && array[2][0]!=empty){
        return true;
    }

    return false;  
}

void Maker(SDL_Texture* texture_1, SDL_Texture* texture_2, SDL_Texture* texture_3, SDL_Texture* texture_4, SDL_Texture* texture_5, enum Shape array[][3], const size_t width, const size_t height)
{
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);

    SDL_Rect Wall_3 = {0, 0, 3*width, 3*height};

    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            SDL_Rect Block = {i*width, j*height, width, height};

            if((i+j)%2==0){
                Box(Block, 249, 97, 103);
            }
            else{
                Box(Block, 252, 231, 125);
            }

            Drawer(texture_1, texture_2, array, Block, i, j);
        }
    }

    if(Result(array)==true && Player==cross){
        SDL_RenderCopy(Renderer, texture_3, NULL, &Wall_3);
        
    }
    else if(Result(array)==true && Player==circle){
        SDL_RenderCopy(Renderer, texture_4, NULL, &Wall_3);
    }
    else if(Shape_Count==9){
        SDL_RenderCopy(Renderer, texture_5, NULL, &Wall_3);
    }

    SDL_RenderPresent(Renderer);
}
