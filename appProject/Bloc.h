#pragma once
#include "Graphics.h"
class Bloc :
	public Graphics
{
public:
	int lineScore;
	Bloc();
	void Update(std::vector<Vec2<int>> cells);
	void DeleteLine(int posY);
};

