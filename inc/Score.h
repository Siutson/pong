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
    void FreeFontResources();
private:
    SDL_Renderer* scoreRenderer;
    const char* scoreKeeper;
    Ball* ball;
    int playerScoreInt;
    std::string playerScore;
    SDL_Rect textRectangle;
    TTF_Font* textFont;
    SDL_Color textColor;
    SDL_Texture* textTexture;
    SDL_Surface* textSurface;
};


#endif