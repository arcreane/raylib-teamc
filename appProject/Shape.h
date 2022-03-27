#pragma once
#include "Vec2.h"
#include <raylib.h>
#include <vector>

class Shape
{ private:
	

protected:
	std::vector<Vec2<int>> cells;
	std::vector<Color> colors;
	int i;
	void move(Vec2<int> dir);
	virtual void Turn() {};
public:
	Shape();
	std::vector<Vec2<int>> getCells();
	std::vector<Color> getColors();
	void setCells(std::vector<Vec2<int>> c);
	void getInput(int input);
	int right();
	int left();
	

};

