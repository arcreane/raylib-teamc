#pragma once
#include "raylibcpp.h"
#include <vector>
#include "Vec2.h"
#include <string>
#include "Cell.h"
#include "Graphics.h"
class Board :
	Graphics
{
public:
	Board(Color color);
	void SetCell(Vec2<int> pos_in, Color c, int v);
	int CheckCells(std::vector<Vec2<int>> shape);
	
	void DrawBorder() const;
	void Draw() const;
	void DrawNext(int type);
	void DrawScore(std::string score);
	void DrawLevel(std::string level);
	int getScore();//tache 4
	//int RemoveLines();
private:
	

};

