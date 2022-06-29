#include "Entity.h"

Entity::Entity(SDL_Renderer* argRenderer){
    renderer = argRenderer;
    velX = 4;
    velY = 4;
}


void Entity::Render(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &rectEntity);
}