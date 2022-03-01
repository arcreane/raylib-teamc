#include "Game.h"
#include <assert.h>
#include "Square.h"
Game::Game(int width, int height, std::string title)
	:board({ 200,120 }, { 10, 20 }, 20, 2)
{	
	assert(!GetWindowHandle());
	InitWindow(width, height, title.c_str());
	SetTargetFPS(60);
	for (int iY = 0; iY < 20; iY++)
		for (int iX = 0; iX < 10; iX++)
		{
			board.SetCell({ iX, iY }, RED);
		}


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
	

	ClearBackground(BLACK);
	board.Draw();


	
}

void Game::Update()
{
	Square square;
	square.getInput(1);
	square.getInput(1);
	for (int i = 0; i < 4; i++)
		board.SetCell(square.getCells()[i], BLUE);
	
}
