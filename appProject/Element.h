#pragma once
#include "Graphics.h"
#include "Vec2.h"
class Element :
    public Graphics
{
protected:
	void move(Vec2<int> dir);
	int i;
	virtual void Turn() {};
public:
    Element():Graphics() {};
	std::vector<Vec2<int>> getCells();
	void setCells(std::vector<Vec2<int>> c);
	void getInput(int input);
	int right();
	int left();
	//Element* getRandomShape();
};

