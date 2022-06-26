#include "Ball.h"

Ball::Ball(SDL_Window* argWindow, SDL_Renderer* argRenderer){
    rectEntity.w = 20;
    rectEntity.h = 20;
    rectEntity.x = 40;
    rectEntity.y = 240;
    velocityX = 4;
    velocityY = 4;
    window = argWindow;
    renderer = argRenderer;
    player = new Player(renderer);
}

void Ball::Update(){
    Move();
}

void Ball::Render(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &rectEntity);
}

void Ball::Event(){

}

void Ball::Move(){
    rectEntity.x += velocityX;
    rectEntity.y += velocityY;
}

void Ball::CheckCollision(){
    rectWindow = {0, 0, 640, 480};

    if (rectEntity.x + rectEntity.w >= rectWindow.x + rectWindow.w){ // kolizja z prawą ścianą
        velocityX = -velocityX;
    }
    if (rectEntity.x <= rectWindow.x){ // kolizja z lewą ścianą
        velocityX = -velocityX;
    }
    if (rectEntity.y + rectEntity.h >= rectWindow.y + rectWindow.h){ // kolizja z dolną ścianą
        velocityY = -velocityY;
    }
    if (rectEntity.y <= rectWindow.y){ // kolizja z górną ścianą
        velocityY = -velocityY;
    }
}