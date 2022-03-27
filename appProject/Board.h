#pragma once
#include "raylibcpp.h"
#include <vector>
#include "Vec2.h"
class Board
{
private:
	class Cell
	{
	public:
		Cell();
		void setColor(Color c_in);
		void Remove();
		Color getColor() const;
	private:
		bool bExists;
		Color c;
	};

public:
	Board(Vec2<int> pos, Vec2<int> shape, int size,int padding_in);
	void SetCell(Vec2<int> pos_in,Color c);
	int CheckCells(std::vector<Vec2<int>> postpos, std::vector<Vec2<int>> shape);
	void DrawCell(Vec2<int> pos_in) const;
	void Draw() const;
	int getScore();//tache 4
private:
	std::vector<Cell> cells;
	int width;
	int height;
	const int cellSize;
	const int padding;
	Vec2<int> ScreenPos;

};

