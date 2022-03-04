#pragma once
#include <string>
#include <raylib.h>
#include "Board.h"
#include "Shape.h"
#include "LLeft.h"
class Game
{
private:
	void Draw();
	void Update();
	Board board;
	Shape *shape;
	int time;
	void animation(std::vector<Vec2<int>> lastpos, std::vector<Vec2<int>> pos, Board* board);
public:
	Game(int width, int height, std::string title);
	Game(const Game& other) = delete;
	Game& operator = (const Game & other) = delete;
	~Game() noexcept;
	void Tick();
	bool GameShouldClose() const;
	
};

