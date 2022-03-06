#pragma once
#include "Vec2.h"
#include <raylib.h>
#include <vector>

class Shape
{ private:
	
protected:
	std::vector<Vec2<int>> cells;
	void move(Vec2<int> dir);
	virtual void Turn() {};
	int i=1;
public:
	Shape();
	std::vector<Vec2<int>> getCells();
	void getInput(int input);
	int right();
	int left();

};

