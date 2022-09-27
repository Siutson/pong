#include "Score.h"

Score::Score(SDL_Renderer *argRenderer, Ball *argBall)
{
    ball = argBall;
    scoreRenderer = argRenderer;

    botScoreRect = {40, 0, 40, 30};
    playerScoreRect = {560, 0, 40, 30};
    botScoreInt = 0;
    botScore = std::to_string(botScoreInt);

    playerScoreInt = 0;
    playerScore = std::to_string(playerScoreInt);

    TTF_Init();
    textFont = TTF_OpenFont("D:/dev/sdl_projects/pong/JtbMM.ttf", 25);
}

void Score::InitializeAndRenderFont()
{
    if (!textFont)
        printf("problem loading font\n%s", TTF_GetError());
    if (ball->botScores)
    {
        botScoreInt++;
        botScore = std::to_string(botScoreInt);
        ball->botScores = false;
    }

    if (ball->playerScores)
    {
        playerScoreInt++;
        playerScore = std::to_string(playerScoreInt);
        ball->playerScores = false;
    }

    botTextSurface = TTF_RenderText_Solid(textFont, botScore.c_str(), textColor);
    botTextTexture = SDL_CreateTextureFromSurface(scoreRenderer, botTextSurface);
    SDL_QueryTexture(botTextTexture, NULL, NULL, &botScoreRect.w, &botScoreRect.h);
    SDL_RenderCopy(scoreRenderer, botTextTexture, NULL, &botScoreRect);
    SDL_DestroyTexture(botTextTexture);
    SDL_FreeSurface(botTextSurface);

    playerTextSurface = TTF_RenderText_Solid(textFont, playerScore.c_str(), textColor);
    playerTextTexture = SDL_CreateTextureFromSurface(scoreRenderer, playerTextSurface);
    SDL_QueryTexture(playerTextTexture, NULL, NULL, &playerScoreRect.w, &playerScoreRect.h);
    SDL_RenderCopy(scoreRenderer, playerTextTexture, NULL, &playerScoreRect);
    SDL_DestroyTexture(playerTextTexture);
    SDL_FreeSurface(playerTextSurface);
}