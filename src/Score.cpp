#include "Score.h"

Score::Score(SDL_Renderer* argRenderer, Ball* argBall){
    textRectangle = {20,0,80,30};
    ball = argBall;
    playerScoreInt = 0;
    playerScore = std::to_string(playerScoreInt);
    scoreRenderer = argRenderer;
    TTF_Init();
    textFont = TTF_OpenFont("../JtbMM.ttf", 25);

}

void Score::InitializeAndRenderFont(){
    // if (!textFont) printf("problem loading font\n%s", TTF_GetError());
    if (ball->botScores){
        playerScoreInt++;
        playerScore = std::to_string(playerScoreInt);
        ball->botScores = false;
    }
    textSurface = TTF_RenderText_Solid(textFont, playerScore.c_str(), textColor);
    textTexture = SDL_CreateTextureFromSurface(scoreRenderer, textSurface);
    SDL_QueryTexture(textTexture, NULL, NULL, &textRectangle.w, &textRectangle.h);
    SDL_RenderCopy(scoreRenderer, textTexture, NULL, &textRectangle);
    SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);
}

void Score::FreeFontResources(){
    SDL_DestroyTexture(textTexture);
    // TTF_Quit();
    // TTF_CloseFont(textFont);
}