#pragma once
#include <string>
#include <raylib.h>
#include "Board.h"
class Game
{
private:
	void Draw();
	void Update();
	Board board;
public:
	Game(int width, int height, std::string title);
	Game(const Game& other) = delete;
	Game& operator = (const Game & other) = delete;
	~Game() noexcept;
	void Tick();
	bool GameShouldClose() const;
	
};

