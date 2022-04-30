#include "Game.h"
#include <assert.h>
#include "Square.h"
#include <iostream>
#include "Line.h"
#include "LRight.h"
#include "LLeft.h"
#include "Element.h"
#include "Bomb.h"
#include<stdlib.h>


#include "ollo.h"
#include "TLeft.h"
#include "TRight.h"

#include "TimerClock.hpp"
#include <thread>


#include <chrono>
#include <thread>
#include "Settings.h"

#include <fstream>
#include <vector>
#include <sstream>


using std::this_thread::sleep_for;
using namespace std::chrono_literals;
TimerClock tc;
double now = 0;
int level = 1;
int flage = 1;
int nextNum = rand() % 7 + 1;
#define P 0.95


using namespace std;
void Game::setShape()

{
	int number = nextNum;
	double prob = rand() % 1000 / (double)1000;
	if (atBottom) {
		if (prob < P)
		{
			switch (number)
			{
			case 1:shape = new Square(); break;
			case 2:shape = new Line(); break;
			case 3:shape = new LRight(); break;
			case 4:shape = new LLeft(); break;
			case 5:shape = new ollo(); break;//Ã¤Â¸Â
			case 6:shape = new TLeft(); break;
			default:shape = new TRight(); break;//Zright
				break;
			}
		}
		else
		{
			shape = new Bomb();
		}
		nextNum = rand() % 7 + 1;


	}
	//Check the previous shape if it has stopped moving, and randomly generate a new shape,set atbottom to false	
}

void Game::checkBottom()
{   //supprimer plus tard
	for (int i = 0; i < shape->getCells().size(); i++)
		if (shape->getCells()[i].getY() == 19) {
			atBottom = true;
			break;
		}
}

void Game::Controll()
{

	if (IsKeyDown(KEY_RIGHT)) {
		if (shape->right() < 9)
			shape->getInput(3);
		//sleep_for(100ms);
	}
	if (IsKeyDown(KEY_LEFT)) {
		if (shape->left() > 0)
			shape->getInput(2);
		//sleep_for(100ms);
	}
	if (IsKeyDown(KEY_UP)) {
		shape->getInput(4);
		//sleep_for(125ms);
	}
	if (IsKeyDown(KEY_DOWN)) {
		/*int max = 0;
		for (int i = 0; i < 4; i++)
		{
			int y = shape->getCells()[i].getY();
			if (max < y)
			{
				max = y;
			}
		}
		int step = 19 - max;
		for (int i = 0; i < step; i++)
		{*/
		shape->getInput(1);
		//}
		//sleep_for(100ms);
	}

}

//Element* Game::getRandomShape()
//{
//	return nullptr;
//}

Game::Game(int width, int height, std::string title)
	:board(RED), bloc()
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
	//bomb = Bomb();
	bomb.getInput(4);
	score = 0;
	time = 0;
	atBottom = false;
	bottom.resize(10);
	bottom.assign(10, 19);

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
	score = 100 * bloc.lineScore;
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
	shape->Draw();
	//bomb.Draw();
	bloc.Draw();
	board.DrawBorder();
	board.DrawNext(nextNum);
	board.DrawLevel(to_string(level));
	board.DrawScore(to_string(score));  //change value later
	board.DrawPlayersScore();



}

void Game::Controll2()
{
	int ct = tc.getTimerSecond();

	if (ct - now > 0)
	{
		if (score < 300)//level 1 in 5000 scores
		{
			now++;//down once per 1 sec 
		}
		else if (score < 600)// level up after 10000scores
		{
			//	now += 0.5;//down once per 0.5sec
			now += 0.5;//down once per 0.5sec
			level = 2;
		}
		else// level up after 10000 scores
		{
			//		now += 0.1;//down once per 0.1sec
			now += 0.1;//down once per 0.1sec
			level = 3;
		}

		shape->getInput(1);
	}
}

void Game::Update()
{
	Element shape2{ *shape };
	std::vector<Vec2<int>> lastpos;
	std::vector<Vec2<int>> oripos;
	//initShape();
	if (atBottom)
	{
		lastpos = shape->getCells();
	}
	setShape();
	if (!atBottom) {
		oripos = shape->getCells();
		//Timer
		Controll2();
		Controll();
		// changer plus tard
		if (bloc.checkCell(oripos, shape, shape->getCells().size()) == 0) {
			atBottom = true;
		}//(oripos, currpos)
		checkBottom();
	}
	else {
		bloc.Update(lastpos, shape2.getCells().size());
		atBottom = false;
		for (int j = 0; j < bloc.cells.size(); j++)
		{
			if (bloc.cells[j].getY() <= 2)
			{
				std::cout << "game over" << endl;

				char name[20];
				std::cout << "Enter your name: ";
				std::cin >> name;
				fstream ifs("score.txt", ios::in);
				vector<string> Pseudo = {};
				vector<int> Score = {};
				if (ifs)
				{
					string nom;
					string point;
					/*cout << "Pseudo  Score" << endl;*/
					while (!ifs.eof())
					{
						ifs >> nom;
						if (!ifs.fail()) {
							//cout << name;
							Pseudo.push_back(nom);

						}
						ifs >> point;

						if (!ifs.fail()) {
							int numero;
							istringstream(point) >> numero;
							//cout << " " << score << endl;
							Score.push_back(numero);
						}

					}
					int compt = 0;
					//score = score + 10023;
					for (auto& elm : Score) {
						if (score <= elm) {
							compt++;
						}

					}
					cout << compt << endl;
					//cout << "Les compteurs " << compt << endl;
					ifs.close();
					if (score == 0)
					{
						ofstream file("score.txt", ios::app);
						file << name << " " << score << endl;
						file.close();
					}
					else
					{
						std::ofstream file("score.txt", ios::out);
						int compteur = 0;

						cout << score << endl;
						for (size_t i = 0; i < Score.size(); i++)

						{
							if (score == 0) {

							}
							else
							{
								if (compteur == compt) {
									file << name << " " << score << endl;
									file << Pseudo[i] << " " << Score[i] << endl;
								}
								else
								{
									file << Pseudo[i] << " " << Score[i] << endl;
								}
								compteur++;
							}
						}
						file.close();
					}



				}
				exit(1);
			}
		}
	}
}
	// changer plus tard
