#ifndef BOT_H
#define BOT_H

#include "Entity.h"
#include "Ball.h"

class Bot : public Entity {
public:
    Bot(SDL_Renderer* argRenderer, Ball* argBall); 
    ~Bot();
    void MoveBot();
    void BotCollision();
    void ResetBotPosition();
    void BotWallCollision();
private:
    Ball* ball;
    SDL_Renderer* renderer;
};


#endif