#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity{
public:
    Player(SDL_Renderer* renderer);
    ~Player();
    void Update();
    void Move();
    void LimitPlayerMovement();
private:
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    SDL_Event e;
    int velX;
    int velY;
};
#endif