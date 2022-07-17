#include "Bot.h"

Bot::Bot(SDL_Renderer* argRenderer, Ball* argBall) : Entity(argRenderer){
    renderer = argRenderer;
    rectEntity = {30,160,10,90};
    ball = argBall;
}

void Bot::MoveBot(){
    // if ((rectEntity.y + rectEntity.h <= 480) && (rectEntity.y >= 0)){ // !! naprawić, bot utyka w ścianie jak wyjdzie poza zakres
    if (ball->rectEntity.y + (ball->rectEntity.h/2) > rectEntity.y + (rectEntity.h/2)){
        rectEntity.y += ball->velY;
    }
    else if (ball->rectEntity.y + (ball->rectEntity.h/2) < rectEntity.y + (rectEntity.h/2)){
        rectEntity.y -= 4;
    }
    // }
}

void Bot::BotCollision(){
    if (ball->rectEntity.x <= rectEntity.x + rectEntity.w){
        if (ball->rectEntity.y <= rectEntity.y + rectEntity.h){
            if (ball->rectEntity.y + ball->rectEntity.h >= rectEntity.y){
                ball->velX = -ball->velX;
                ball->velY = (( (ball->rectEntity.y + (ball->rectEntity.h/2)) - (rectEntity.y+ (rectEntity.h/2)) ))/6;
            }
        }
    }
}

void Bot::BotWallCollision(){
    
}

void Bot::ResetBotPosition(){
    if (ball->playerScores | ball->botScores){
        rectEntity = {30,160,10,90};
    }
}