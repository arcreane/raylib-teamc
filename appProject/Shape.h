#pragma once
#include "Vec2.h"
#include <raylib.h>
#include <vector>
#include "Element.h"

class Shape :
	public Element
{ private:

protected:
	
	int i;
	void move(Vec2<int> dir);
	virtual void Turn() {};
public:
	Shape();
	std::vector<Vec2<int>> getCells();
	void setCells(std::vector<Vec2<int>> c);
	void getInput(int input);
	int right();
	int left();
	void destroy();

};

