#pragma once
#include "raylibcpp.h"
#include <vector>
#include "Vec2.h"
#include <string>
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
		void setVal(int v);
		int getVal();
	private:
		bool bExists;
		Color c;
		int val;
	};

public:
	Board(Vec2<int> pos, Vec2<int> shape, int size,int padding_in);
	void SetCell(Vec2<int> pos_in,Color c, int v);
	int CheckCells(std::vector<Vec2<int>> shape);
	void DrawCell(Vec2<int> pos_in) const;
	void DrawBorder() const;
	void Draw() const;
	void DrawNext(int type);
	void DrawScore(std::string score);
	void DrawLevel(std::string level);
	int getScore();//tache 4
private:
	std::vector<Cell> cells;
	int width;
	int height;
	const int cellSize;
	const int padding;
	Vec2<int> ScreenPos;

};

