#include "Player.h"
#include <stdio.h>

Player::Player(SDL_Renderer* argRenderer) : Entity(argRenderer){
    velX = 0;
    velY = 0;
    rectEntity.w = 10;
    rectEntity.h = 90;
    rectEntity.x = 600;
    rectEntity.y = 160;

    renderer = argRenderer;
}

void Player::Move(){
    if (keystates[SDL_SCANCODE_W] && rectEntity.y > 0){
        velY = -6;
    }
    else if (keystates[SDL_SCANCODE_S] && rectEntity.y < 480){
        velY = 6;
    }
    else { velY = 0;}
}

void Player::Update(){
    rectEntity.y += velY;
}

void Player::LimitPlayerMovement(){
    rectWindow = {0, 0, 640, 480};

    if(rectEntity.y + rectEntity.h >= rectWindow.h){ // ograniczenie poruszania pionowego z dolną krawędzią
        rectEntity.y = rectWindow.h - rectEntity.h;
    }
    if(rectEntity.y <= rectWindow.y){ // ograniczenie poruszania pionowego z górną krawędzią
        rectEntity.y = rectWindow.y;
    }
}