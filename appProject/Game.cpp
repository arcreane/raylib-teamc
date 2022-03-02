#include "Game.h"
#include <assert.h>
#include "Square.h"
#include <iostream>

using namespace std;
void Game::animation(std::vector<Vec2<int>> lastpos, std::vector<Vec2<int>> pos, Board* board)
{

	for (int i = 0; i < 4; i++){
		bool mark = false;
		for (int j = 0; j < 4; j++) {
			std::cout << i << "lastpos x" << lastpos[i].getX() << "lastpos y" << lastpos[i].getY() << endl;
			std::cout << pos[j].getX() << pos[j].getY() << endl;
			cout << (lastpos[i] == pos[j]) << endl;
			if (lastpos[i] == pos[j])
			{

				mark = true;
			}
		}
		cout << "mark" << mark << endl;
		if (mark == false)
			if(lastpos[i].getX()>=0 && lastpos[i].getY() >= 0)
				(*board).SetCell(lastpos[i], RED);
	}
}
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
	shape = Square();
	time = 0;


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
		if(shape.getCells()[3].getY()<=19){
		for (int i = 0; i < 4; i++)
			if (shape.getCells()[i].getY() >= 0)
				board.SetCell(shape.getCells()[i], WHITE);
		std::vector<Vec2<int>> lastpos = shape.getCells();
		shape.getInput(1);
	/*	for (int c = 0; c < 4; c++) {
			std::cout << c << ":" << lastpos[c].getx() << lastpos[c].gety() << endl;
			std::cout << c << ":" << shape.getcells()[c].getx() << shape.getcells()[c].gety() << endl;
		}*/
		if (shape.getCells()[3].getY() <=19)
			animation(lastpos, shape.getCells(), &board);
		//Compare the previous position and the moved position, 
		//and set the different points in the previous position to red
		}

		
	
	
	
}
