#include "Line.h"
#include <iostream>
#include "Vec2.h"
using namespace std;
Line::Line()
{

	cells[0] = Vec2{ 4,1 };
	cells[1] = Vec2{ 5,1 };
	cells[2] = Vec2{ 6,1 };
	cells[3] = Vec2{ 7,1 };


}

void Line::Draw() 
{
	
}

void Line::Turn()
{
	if (cells[1].getX()==cells[2].getX())
	{
			cells[0].setX(cells[0].getX() - 1);
			cells[0].setY(cells[0].getY() + 1);
			cells[2].setX(cells[2].getX() + 1);
			cells[2].setY(cells[2].getY() - 1);
			cells[3].setX(cells[3].getX() + 2);
			cells[3].setY(cells[3].getY() - 2);
	}
	else
	{

		cells[0].setX(cells[0].getX() + 1);
		cells[0].setY(cells[0].getY() - 1);
		cells[2].setX(cells[2].getX() - 1);
		cells[2].setY(cells[2].getY() + 1);
		cells[3].setX(cells[3].getX() - 2);
		cells[3].setY(cells[3].getY() + 2);
		
	}
	
	
}
