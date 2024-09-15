#ifndef EVENT_H 
#define EVENT_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern enum Key{
    home, play,
} Button;

enum Shape{
    empty, cross, circle,
};

extern enum Shape Player;

extern bool Runner;

extern int Shape_Count;

void Keys(enum Shape array[][3], enum Key* choice);

void Turn(enum Shape array[][3], int i, int j);

void Event_Handler(enum Shape array[][3], enum Key* choice, const size_t width, const size_t height);

#endif