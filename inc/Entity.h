#ifndef ENTITY_H
#define ENTITY_H
#include "SDL2/SDL.h"
#include <stdio.h>

class Entity {
public:
    Entity();
    void Render();
    void Update();
    void Move();
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect rectEntity;
    SDL_Rect rectWindow;
private:
};


#endif