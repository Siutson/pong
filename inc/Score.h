#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "Ball.h"
#include <string>

class Score{
public:
    Score(SDL_Renderer* argRenderer, Ball* argBall);
    ~Score();
    void InitializeAndRenderFont();
private:
    SDL_Renderer* scoreRenderer;

    SDL_Rect botScoreRect;
    std::string botScore;
    const char* botScoreKeeper;
    int botScoreInt;

    SDL_Rect playerScoreRect;
    std::string playerScore;
    const char* playerScoreKeeper;
    int playerScoreInt;

    Ball* ball;
    TTF_Font* textFont;
    SDL_Color textColor;
    SDL_Texture* botTextTexture;
    SDL_Surface* botTextSurface;

    SDL_Texture* playerTextTexture;
    SDL_Surface* playerTextSurface;
};


#endif