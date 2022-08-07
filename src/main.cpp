// #include <SDL2/SDL_image.h>
#include <string>
#include "Game.h"

int main( int argc, char* args[] ){

    double delta = 0;
    uint64_t a = SDL_GetTicks64();
    uint64_t b = 0;

    Game *game = NULL;
    game = new Game();
    while(game->GetRunning()){
        b = SDL_GetTicks64();
        delta = b - a; //naprawic pozniej
        if (delta > 1000/60.0){
            a = b;
            game->Event();
            game->Render();
            game->Update();
        }
    }

    return 0;
}