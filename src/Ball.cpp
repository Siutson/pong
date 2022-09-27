#include "Ball.h"

Ball::Ball(SDL_Renderer* argRenderer, Player* argPlayer) : Entity(argRenderer){
    rectEntity = {320,240,20,20};
    botScores = false;
    playerScores = false;
    renderer = argRenderer;
    player = argPlayer;
    // bot = argBot;
}

void Ball::Update(){
    Move();
}

void Ball::Event(){

}

void Ball::Move(){
    rectEntity.x += velX;
    rectEntity.y += velY;
}

void Ball::CheckWallCollision(){
    rectWindow = {0, 0, 640, 480};

    if (rectEntity.x + rectEntity.w >= rectWindow.w){ // kolizja z prawą ścianą
        botScores = true;
        rectEntity = {320,240,20,20};
        player->rectEntity = {600,160,10,80};
        // bot->rectEntity = {30,160,10,90};
        velX = 4;
        velY = 4;
        // velX = -velX;
    }
    if (rectEntity.x <= rectWindow.x){ // kolizja z lewą ścianą
        playerScores = true;
        rectEntity = {320,240,20,20};
        player->rectEntity = {600,160,10,80};
        // bot->rectEntity = {30,160,10,90};
        velX = 4;
        velY = 4;
        // velX = -velX;
    }
    if (rectEntity.y + rectEntity.h >= rectWindow.h){ // kolizja z dolną ścianą
        velY = -velY;
    }
    if (rectEntity.y <= rectWindow.y){ // kolizja z górną ścianą
        velY = -velY;
    }
}

void Ball::CheckPlayerCollision(){
    if (rectEntity.x + rectEntity.w >= player->rectEntity.x){ // brak wsparcia dla kolizji boków paletki gracza
        if (rectEntity.y <= player->rectEntity.y + player->rectEntity.h){ // sprawdzenie góry piłki z dołem paletki

            if (rectEntity.y + rectEntity.h >= player->rectEntity.y ){ //sprawdzenue dołu piłki z górą paletki
                velX = -velX;
                velY = (( (rectEntity.y + (rectEntity.h/2)) - (player->rectEntity.y+ (player->rectEntity.h/2)) ))/8;
            }
        }
    }
}