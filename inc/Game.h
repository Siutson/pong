#ifndef GAME_H
#define GAME_H

#include "Score.h"
#include "Entity.h"
#include "Ball.h"
#include "Player.h"

class Game {
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
    Score* score;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif