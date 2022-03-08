#include "LLeft.h"
#include <iostream>
using namespace std;
LLeft::LLeft()
{
	cells[0] = Vec2{ 9,1 };
	cells[1] = Vec2{ 9,2 };
	cells[2] = Vec2{ 9,3 };
	cells[3] = Vec2{ 8,3 };
}

void LLeft::Turn() 
{
	if (cells[2].getX() - cells[3].getX() == 0) {
		if (cells[2].getY() - cells[3].getY()>0) {
			/* 0        00
			   000  ==> 0
						0*/
			cells[0].setX(cells[0].getX() - 1);
			cells[0].setY(cells[0].getY() + 1);
			cells[2].setX(cells[2].getX() + 1);
			cells[2].setY(cells[2].getY() - 1);
			cells[3].setX(cells[3].getX() + 2);
			cells[3].setY(cells[3].getY() + 0);
		}
		else
		{
			/* 000       0
			     0  ==>  0
						00*/
			cells[0].setX(cells[0].getX() + 1);
			cells[0].setY(cells[0].getY() - 1);
			cells[2].setX(cells[2].getX() - 1);
			cells[2].setY(cells[2].getY() + 1);
			cells[3].setX(cells[3].getX() - 2);
			cells[3].setY(cells[3].getY() + 0);
		}
	}
	else
	{
		if (cells[2].getX() - cells[3].getX() > 0) {
			int i;
			switch (cells[2].getX())
			{
			case(9):
				i = -1;
				break;
			default:
				i = 0;
				break;
			}
			cells[0].setX(cells[0].getX() + 1 + i);
			cells[0].setY(cells[0].getY() + 1);
			cells[1].setX(cells[1].getX() + i);
			cells[2].setX(cells[2].getX() - 1 + i);
			cells[2].setY(cells[2].getY() - 1);
			cells[3].setX(cells[3].getX() + 0 + i);
			cells[3].setY(cells[3].getY() - 2);
		}
		else
		{
			int i;
			switch (cells[2].getX())
			{
			case(0):
				i = 1;
				break;
			default:
				i = 0;
				break;
			}
			cells[0].setX(cells[0].getX() - 1 + i);
			cells[0].setY(cells[0].getY() - 1);
			cells[1].setX(cells[1].getX() + i);
			cells[2].setX(cells[2].getX() + 1 + i);
			cells[2].setY(cells[2].getY() + 1);
			cells[3].setX(cells[3].getX() + 0 + i);
			cells[3].setY(cells[3].getY() + 2);
		}

	}

}
