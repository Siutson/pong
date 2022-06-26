#ifndef BALL_H
#define BALL_H

#include "Entity.h"
#include "Player.h"

class Ball : public Entity {
public:
    Ball(SDL_Window* argWindow, SDL_Renderer* argRenderer);
    ~Ball();
    void Update();
    void Event();
    void Render();
    void CheckCollision();
private:
    Player* player;
    int velocityX;
    int velocityY;
    void Move();
};


#endif