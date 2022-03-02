#include "Game.h"
#include <assert.h>
Game::Game(int Width, int Height, std::string title)
	:width{Width},
	height{Height}
{ 
	assert(!GetWindowHandle());
	InitWindow(width, height, title.c_str());
	SetTargetFPS(60);
	
	// Hi

}

Game::~Game() noexcept
{	
	
	assert(GetWindowHandle());
	CloseWindow();
}

void Game::Tick()
{	
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}

bool Game::GameShouldClose() const
{

	return WindowShouldClose();
}

void Game::Draw()
{
	

	ClearBackground(RAYWHITE);


	
}

void Game::Update()
{
	
}
