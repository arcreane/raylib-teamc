#pragma once
#include <string>
#include <raylib.h>
#include "Board.h"
#include "Shape.h"
#include <vector>
#include "ctime"
#include "Bloc.h"
#include "Bomb.h"
class Game
{
private:
	void Draw();
	void Update();
	Board board;
	Element* shape;
	Bomb bomb;
	Bloc bloc;
	void setShape();
	int score;
	std::vector<int> bottom;
	bool atBottom;
	void checkBottom();
	void Controll();
	void Controll2();
	//int score; //tache4
	//Element* getRandomShape();//tache3
	int time;
	void animation(std::vector<Vec2<int>> lastpos, Shape* shape, Board* board);
public:
	
	Game(int width, int height, std::string title);
	Game(const Game& other) = delete;
	Game& operator = (const Game & other) = delete;
	~Game() noexcept;
	void Tick();
	bool GameShouldClose() const;
	
};

