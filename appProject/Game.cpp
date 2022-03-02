#include "Game.h"
#include <assert.h>
Game::Game(int Width, int Height, std::string title)
	:width{Width},
	height{Height}
{ 
	assert(!GetWindowHandle());
	InitWindow(width, height, title.c_str());
	SetTargetFPS(60);
	

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
		if(shape.getCells()[3].getY()<=19){
		for (int i = 0; i < 4; i++)
			if (shape.getCells()[i].getY() >= 0)
				board.SetCell(shape.getCells()[i], WHITE);
		std::vector<Vec2<int>> lastpos = shape.getCells();
		shape.getInput(1);

		if (shape.getCells()[3].getY() <=19)
			animation(lastpos, shape.getCells(), &board);
		//Compare the previous position and the moved position, 
		//and set the different points in the previous position to red
		}

		
	
	
	
}
