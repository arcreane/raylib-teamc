#include "Game.h"
#include <assert.h>
#include "Square.h"
#include <iostream>
#include "Line.h"
#include "LRight.h"
#include "LLeft.h"
#include "Shape.h"
#include "squareC.h"
#include<stdlib.h>
#include "lineC.h"
#include "lleftC.h"
#include "tleftC.h"
#include "lrightC.h"
#include "trightC.h"
#include "olloC.h"
#include "ollo.h"
#include "TLeft.h"
#include "TRight.h"
#include "TimerClock.hpp"
#include <thread>

#define N  999 

#include <chrono>
#include <thread>

using namespace std;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;
TimerClock tc;
double now = 0;


using namespace std;
void Game::setShape()
{	int number= rand() % 7  + 1;
	float prob = rand() % (N + 1) / (float)(N + 1);

	if (atBottom) {
		if (prob<0.6) {
			switch (number)
			{
			case 1:shape = new Square(); break;
			case 2:shape = new lineC(); break;
			case 3:shape = new lrightC(); break;
			case 4:shape = new lleftC(); break;
			case 5:shape = new olloC(); break;
			case 6:shape = new tleftC(); break;
			default:shape = new trightC(); break;
				break;
			}
		}
		else {
			switch (number)
			{
			case 1:shape = new Square(); break;
			case 2:shape = new Line(); break;
			case 3:shape = new LRight(); break;
			case 4:shape = new LLeft(); break;
			case 5:shape = new ollo(); break;
			case 6:shape = new TLeft(); break;
			default:shape = new TRight(); break;
				break;
			}

		}
		
		atBottom = false;
	}
	//Check the previous shape if it has stopped moving, and randomly generate a new shape,set atbottom to false	
}
void Game::checkBottom()
{   //supprimer plus tard
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
	bool can = false;
	if(canmove){
	
	std::vector<Vec2<int>> lastpos = shape->getCells();
	//Controll2(lastpos);
	sleep_for(100ms);
	if (IsKeyDown(KEY_RIGHT)){
	if(shape->right()<9)
	{
		shape->getInput(3); canmove = false;
		for (int i = 0; i < 4; i++)
			if (lastpos[i] != shape->getCells()[i])
				can = true;
		if(can)
			animation(lastpos, shape, &board);
	}
	}
	if (IsKeyDown(KEY_LEFT)){
		if (shape->left() > 0)
		{
			shape->getInput(2);  canmove = false; for (int i = 0; i < 4; i++)
				if (lastpos[i] != shape->getCells()[i])
					can = true;
			if (can)
				animation(lastpos, shape, &board);
		}
	}
	if (IsKeyDown(KEY_UP)) { shape->getInput(4); canmove = false; for (int i = 0; i < 4; i++)
		if (lastpos[i] != shape->getCells()[i])
			can = true;
	if (can)
		animation(lastpos, shape, &board);
	}
	if (IsKeyDown(KEY_DOWN)) {
		shape->getInput(1);  canmove = false; for (int i = 0; i < 4; i++)
			if (lastpos[i] != shape->getCells()[i])
				can = true;
		if (can)
			animation(lastpos, shape, &board);
	}
	}
	
}
void Game::Controll2(std::vector<Vec2<int>> lastpos)
{
	int ct = tc.getTimerSecond();

	if (ct - now > 0)
	{
		if (ct <= 5)//level 1 in 5 sec
		{
			now++;//down once per 1 sec 
		}
		else if (ct <= 10)// level up after 5 sec
		{
			now += 0;//down once per 0.5sec
		}
		else// level up after 10 sec
		{
			now += 0;//down once per 0.1sec
		}

		shape->getInput(1);
		animation(lastpos, shape, &board);
	}
}
Shape* Game::getRandomShape()
{
	return nullptr;
}
/*
The main purpose of this function is to animate when our chessboard actually changes.
But whether our chessboard can change needs to be judged by the CheckCells function.
So, you will judge all the changes we can make in CheckCell, because CheckCell belongs to chessboard class, 
which contains all the information of our chessboard.
When you successfully implement this function, the CheckBottom function in this class can be deleted,
because it is only used to judge a situation of the chessboard.

All the animation effects have been written, you just need to implement the judgment of the chessboard situation.
*/
void Game::animation(std::vector<Vec2<int>> lastpos, Shape* shape, Board* board)
{	//Vérifiez l'état de la carte avant de vous déplacer.
	int juge = board->CheckCells(lastpos, shape->getCells());
	//S'il est possible de se déplacer, déplacez-vous, sinon revenez à la position d'origine
	if (juge == 1) {
		//Toutes les fonctions de cette branche sont utilisées pour animer le mouvement des graphiques.
		for (int i = 0; i < 4; i++)
			if (shape->getCells()[i].getY() >= 0)
				(*board).SetCell(shape->getCells()[i], shape->getColors()[i]);
		for (int i = 0; i < 4; i++) {
			bool mark = false;
			for (int j = 0; j < 4; j++) {
				if (lastpos[i] == shape->getCells()[j])
				{

					mark = true;
				}
			}
			
			if (mark == false)
				if (lastpos[i].getX() >= 0 && lastpos[i].getY() >= 0)
					(*board).SetCell(lastpos[i], RED);
					
		}
	}
	else {
		if (juge == 2)
			//sinon revenez à la position d'origine
			shape->setCells(lastpos);
		else
		{	//Si le bas touche une autre forme, placez-la sur le plateau
			
			for (int j = 0; j < 4; j++)
				if (shape->getCells()[j].getY() >= 0){
					for (int i = 0; i < 4; i++) {
						bool mark = false;
						for (int j = 0; j < 4; j++) {
							if (lastpos[i] == shape->getCells()[j])
							{

								mark = true;
							}
						}

						if (mark == false)
							if (lastpos[i].getX() >= 0 && lastpos[i].getY() >= 0)
								(*board).SetCell(lastpos[i], RED);
					}
					//printf("x=%d,y=%d\n", shape->getCells()[j].getX(), shape->getCells()[j].getY());
					(*board).SetCell(shape->getCells()[j], shape->getColors()[j]);
					
				}
					//Here, a figure is stacked on the board because its bottom touches the lower bound of the board, 
					//or some other figure.
					//So, after the placement is complete, we should check if there is a row that can be eliminated
					//so we call (*board).getScore(); here
				else
					std::cout << "game over" << endl;
			atBottom = true;
		}
	}
	canmove = true;
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
	score = 0;
	time = 0;
	bottom.resize(10);
	bottom.assign(10, 19);
	canmove = true;

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
	//tache 2 Info-bulle score next shape level
	//
	board.Draw();


	
}

void Game::Update()
{

	setShape();
	std::vector<Vec2<int>> lastpos = shape->getCells();
	if (!atBottom) {

		//Timer
		//Controll2();
		Controll();
		// changer plus tard
		
		/*
		checkBottom();
	
		if (atBottom)

			for (int j = 0; j < 4; j++)
				if (shape->getCells()[j].getY() >= 0)
					board.SetCell(shape->getCells()[j], shape->getColors()[j]);
				else
					std::cout << "game over" << endl;
		}
		*/
		// changer plus tard



	}
	
	
	
}
