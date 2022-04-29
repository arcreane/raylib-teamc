#pragma once
#include "Graphics.h"
#include"Shape.h"
class Bloc :
	public Graphics
{
public:
	int lineScore;
	Bloc();
	void Update(std::vector<Vec2<int>> cells,int size);
	void DeleteLine(int posY);
	int checkCell(std::vector<Vec2<int>> cell,Element* shape,int size);
	void DeleteRow(Vec2<int> pos);
	
};

