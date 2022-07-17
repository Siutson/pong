#ifndef BALL_H
#define BALL_H

#include "Entity.h"
#include "Player.h"

class Ball : public Entity {
public:
    Ball(SDL_Renderer* argRenderer, Player* argPlayer);
    ~Ball();
    void Update();
    void Event();
    void CheckWallCollision();
    void CheckPlayerCollision();
    bool botScores;
    bool playerScores;
private:
    Player* player;
    void Move();
};


#endif