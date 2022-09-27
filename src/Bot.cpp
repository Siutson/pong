#include "Bot.h"

Bot::Bot(SDL_Renderer *argRenderer, Ball *argBall) : Entity(argRenderer)
{
    renderer = argRenderer;
    rectEntity = {30, 160, 10, 90};
    ball = argBall;
}

void Bot::MoveBot()
{
    if ((rectEntity.y + rectEntity.h <= 480) && (rectEntity.y >= 0))
    { // !! naprawić, bot utyka w ścianie jak wyjdzie poza zakres
        if (ball->rectEntity.y + (ball->rectEntity.h / 2) > rectEntity.y + (rectEntity.h / 2))
        {
            rectEntity.y += ball->velY;
        }
        else if (ball->rectEntity.y + (ball->rectEntity.h / 2) < rectEntity.y + (rectEntity.h / 2))
        {
            rectEntity.y -= ball->velY;
        }
    }
    else if (rectEntity.y < 0)
    {
        rectEntity.y = 0;
    }
    else
    {
        rectEntity.y = 480 - rectEntity.h;
    }
}

void Bot::BotCollision()
{
    if (ball->rectEntity.x <= rectEntity.x + rectEntity.w) // checking right side of palette
    {
        if (ball->rectEntity.y >= rectEntity.y) // checking top of palette
        {
            ball->velX = -ball->velX;
            ball->velY = (((ball->rectEntity.y + (ball->rectEntity.h / 2)) - (rectEntity.y + (rectEntity.h / 2)))) / 6;
        }
        else
        {
            ball->velX = -ball->velX;
            ball->velY = (((ball->rectEntity.y + (ball->rectEntity.h / 2)) - (rectEntity.y + (rectEntity.h / 2)))) / 6;
        }
        // if (ball->rectEntity.y + ball->rectEntity.h <= rectEntity.y + rectEntity.h) // checking bottom of palette
        // {
        //     ball->velX = -ball->velX;
        //     ball->velY = (((ball->rectEntity.y + (ball->rectEntity.h / 2)) - (rectEntity.y + (rectEntity.h / 2)))) / 6;
        // }
    }
}

void Bot::BotWallCollision()
{
}

void Bot::ResetBotPosition()
{
    if (ball->playerScores | ball->botScores)
    {
        rectEntity = {30, 160, 10, 90};
    }
}