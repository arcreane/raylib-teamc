#include "Line.h"
#include <iostream>
#include "Vec2.h"
using namespace std;
Line::Line()
{
//	cells[0] = Vec2{ 5,-3 };
//	cells[1] = Vec2{ 5,-2 };
//	cells[2] = Vec2{ 5,-1 };
//	cells[3] = Vec2{ 5,0 };

	cells[0] = Vec2{ 4,1 };
	cells[1] = Vec2{ 5,1 };
	cells[2] = Vec2{ 6,1 };
	cells[3] = Vec2{ 7,1 };


}

void Line::Turn()
{/*
	if (cells[1].getX()==cells[2].getX())
	{
		if (cells[1].getY() - cells[2].getY() < 0) {
			cells[0].setX(cells[0].getX() + 1);
			cells[0].setY(cells[0].getY() + 1);
			cells[2].setX(cells[2].getX() - 1);
			cells[2].setY(cells[2].getY() - 1);
			cells[3].setX(cells[3].getX() - 2);
			cells[3].setY(cells[3].getY() - 2);
		}
		else
		{
			cells[0].setX(cells[0].getX() - 2);
			cells[0].setY(cells[0].getY() - 2);
			cells[1].setX(cells[1].getX() - 1);
			cells[1].setY(cells[1].getY() - 1);
			cells[3].setX(cells[3].getX() + 1);
			cells[3].setY(cells[3].getY() + 1);
		}
	}
	else
	{
		if (cells[1].getX()-cells[2].getX() > 0)
		{
			cells[0].setX(cells[0].getX() - 2);
			cells[0].setY(cells[0].getY() + 2);
			cells[1].setX(cells[1].getX() - 1);
			cells[1].setY(cells[1].getY() + 1);
			cells[3].setX(cells[3].getX() + 1);
			cells[3].setY(cells[3].getY() - 1);
		}
		else {
			cells[0].setX(cells[0].getX() + 1);
			cells[0].setY(cells[0].getY() - 1);
			cells[2].setX(cells[2].getX() - 1);
			cells[2].setY(cells[2].getY() + 1);
			cells[3].setX(cells[3].getX() - 2);
			cells[3].setY(cells[3].getY() + 2);
		}
	}
 */

	if (cells[1].getX()==cells[2].getX()) // cells[1].getX()==5 cells[2].getX()==6
	{
		int i;
		switch (cells[2].getX())
		{
		case(0):
			i = 1;
			break;
		case(9):
			i = -2;
			break;
		default:
			i = 0;
			break;
		}
			cells[0].setX(cells[0].getX() - 1 + i);
			cells[0].setY(cells[0].getY() + 1);
			cells[1].setX(cells[1].getX() + i);
			cells[2].setX(cells[2].getX() + 1 + i);
			cells[2].setY(cells[2].getY() - 1);
			cells[3].setX(cells[3].getX() + 2 + i);

			cells[3].setY(cells[3].getY() - 2);
	}
	else
	{

		cells[0].setX(cells[0].getX() + 1);
		cells[0].setY(cells[0].getY() - 1);
		cells[2].setX(cells[2].getX() - 1); // cells[1].getX()==5 cells[2].getX()==5
		cells[2].setY(cells[2].getY() + 1);
		cells[3].setX(cells[3].getX() - 2);
		cells[3].setY(cells[3].getY() + 2);
		
	}
	
	
}
