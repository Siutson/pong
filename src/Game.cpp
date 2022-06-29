#include "Game.h"

Game::Game(){
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	}

    window = SDL_CreateWindow( "Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    if(window){
        printf("Window created");
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer){
        printf("Successfully created renderer");
    }

    player = new Player(renderer);
    ball = new Ball(window, renderer, player);
    score = new Score(renderer, ball);
}

Game::~Game(){}

void Game::Event(){
    SDL_Event event;
    while( SDL_PollEvent( &event ) != 0  ){
        if( event.type == SDL_QUIT )//User requests quit
        {
            isRunning = false;
        }

    }
    player->Move();
    player->Update();

    // ball->Event();
}

void Game::Render(){
    SDL_RenderClear(renderer);
    player->Render();
    ball->Render();
    score->InitializeAndRenderFont();
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
}

bool Game::GetRunning(){
    return isRunning;
}

void Game::Update(){
    // player->Update();
    ball->Update();
    ball->CheckWallCollision();
    ball->CheckPlayerCollision();
    player->LimitPlayerMovement();
}