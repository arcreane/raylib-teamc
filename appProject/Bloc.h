#pragma once
#include "Graphics.h"
#include"Shape.h"
class Bloc :
	public Graphics
{
public:
	int lineScore;
	Bloc();
	void Update(std::vector<Vec2<int>> cells);
	void DeleteLine(int posY);
	int checkCell(std::vector<Vec2<int>> cell,Shape* shape);
	void DeleteRow(Vec2<int> pos);
	
};

