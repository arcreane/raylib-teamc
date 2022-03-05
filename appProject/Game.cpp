#include "Game.h"
#include <assert.h>
#include "Square.h"
#include <iostream>
#include "Line.h"
#include "LRight.h"
#include "LLeft.h"
#include "Shape.h"
#include "ollo.h"
#include "TLeft.h"
#include "TRight.h"

#include <chrono>
#include <thread>



using namespace std;
void Game::setShape()
{
	if (atBottom) {
		shape = new TLeft();
		shape->getInput(4);
		//shape->getInput(4);
		atBottom = false;
	}
	//Check the previous shape if it has stopped moving, and randomly generate a new shape,set atbottom to false	
}
void Game::checkBottom()
{   //If the current shape touches the bottom, stop moving and call setShape()
	for (int i = 0; i < 4; i++)
		if (bottom[shape->getCells()[i].getX()] <= shape->getCells()[i].getY()){
			atBottom = true;
			for (int j = 0; j < 4; j++) {
				if (bottom[shape->getCells()[j].getX()] >= shape->getCells()[j].getY())
					bottom[shape->getCells()[j].getX()] = (shape->getCells()[j].getY()-1);
			}
			for (int k = 0; k < 10; k++)
				std::cout << bottom[k] << ",";
			std::cout << endl;
			break;
		}

}
void Game::Controll()
{ 
	if (IsKeyDown(KEY_RIGHT)){
		if(shape->right()<9)
			shape->getInput(3);
	}
	if (IsKeyDown(KEY_LEFT)){
		if (shape->left() > 0)
		shape->getInput(2);
	}
	if (IsKeyDown(KEY_UP)) shape->getInput(4);
	if (IsKeyDown(KEY_DOWN)) shape->getInput(1);
	
}
void Game::animation(std::vector<Vec2<int>> lastpos, std::vector<Vec2<int>> pos, Board* board)
{

	for (int i = 0; i < 4; i++){
		bool mark = false;
		for (int j = 0; j < 4; j++) {
			if (lastpos[i] == pos[j])
			{

				mark = true;
			}
		}
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

	shape = new Square();
	time = 0;
	bottom.resize(10);
	for (size_t i = 0; i < bottom.size(); i++)
	{
		printf("1>>>>>>>>>> bottom = %d\n", bottom[i]);
	}
	
	bottom.assign(10, 19);
	for (size_t i = 0; i < bottom.size(); i++)
	{
		printf("2>>>>>>>>>> bottom = %d\n", bottom[i]);
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
	setShape();
	

	//shape->getInput(1);
	//this_thread::sleep_for(chrono::milliseconds(500));

	if (!atBottom) {
		for (int i = 0; i < 4; i++)
			if (shape->getCells()[i].getY() >= 0)
				board.SetCell(shape->getCells()[i], WHITE);
		std::vector<Vec2<int>> lastpos = shape->getCells();
		Controll();
		checkBottom();
		/*	for (int c = 0; c < 4; c++) {
				std::cout << c << ":" << lastpos[c].getx() << lastpos[c].gety() << endl;
				std::cout << c << ":" << shape.getcells()[c].getx() << shape.getcells()[c].gety() << endl;
			}*/
		if (!atBottom)
			animation(lastpos, shape->getCells(), &board);
		else {
			animation(lastpos, shape->getCells(), &board);
			for (int j = 0; j < 4; j++)
				if (shape->getCells()[j].getY() >= 0)
					board.SetCell(shape->getCells()[j], WHITE);
				else
					std::cout << "game over" << endl;
		}
	}

		
	
	
	
}
