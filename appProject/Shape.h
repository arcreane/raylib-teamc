#pragma once
#include "Vec2.h"
#include <raylib.h>
#include <vector>

class Shape
{ private:

protected:
	std::vector<Vec2<int>> cells;
	void move(Vec2<int> dir);
public:
	Shape();
	std::vector<Vec2<int>> getCells();
	void getInput(int input);
	virtual void Turn();

};

