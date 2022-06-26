#ifndef GAME_H
#define GAME_H

#include "Entity.h"
#include "Ball.h"
#include "Player.h"

class Game : public Entity{
public:
    Game();
    ~Game();
    void Update();
    void Event();
    void Render();
    bool GetRunning();
private:
    bool isRunning;
    Ball* ball;
    Player* player;
};

#endif