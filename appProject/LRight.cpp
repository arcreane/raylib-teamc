#include "LRight.h"
#include <iostream>
using namespace std;
LRight::LRight()
{
	cells[0] = Vec2{ 8,0 };
	cells[1] = Vec2{ 8,1 };
	cells[2] = Vec2{ 8,2 };
	cells[3] = Vec2{ 9,2 };
}

void LRight::Turn()
{
	if (cells[2].getX() - cells[3].getX() == 0) {

		if (cells[2].getY() - cells[3].getY() > 0) {
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
			cells[0].setX(cells[0].getX() + 2 + i);
			cells[0].setY(cells[0].getY() - 2);
			cells[1].setX(cells[1].getX() + 1 + i);
			cells[1].setY(cells[1].getY() - 1);
			cells[3].setX(cells[3].getX() + 1 + i);
			cells[3].setY(cells[3].getY() + 1);
			cells[2].setX(cells[2].getX() + i);
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
			cells[0].setX(cells[0].getX() - 2 + i);
			cells[0].setY(cells[0].getY() + 2);
			cells[1].setX(cells[1].getX() - 1 + i);
			cells[1].setY(cells[1].getY() + 1);
			
			cells[3].setX(cells[3].getX() - 1 + i);
			cells[3].setY(cells[3].getY() - 1);
			cells[2].setX(cells[2].getX() + i);
		}
	}
	else
	{
		if (cells[2].getX() - cells[3].getX() > 0) {
			int i;
			switch (cells[2].getX())
			{
			case(1):
				i = 1;
				break;
			default:
				i = 0;
				break;
			}
			cells[0].setX(cells[0].getX() - 2 + i);
			cells[0].setY(cells[0].getY() - 2);
			cells[1].setX(cells[1].getX() - 1 + i);
			cells[1].setY(cells[1].getY() - 1);
			
			cells[3].setX(cells[3].getX() + 1 + i);
			cells[3].setY(cells[3].getY() - 1);
			cells[2].setX(cells[2].getX() + i);
		}
		else
		{
			int i=0;
			switch (cells[2].getX())
			{

			case(8):
				i = -1;
				break;
			default:
				i = 0;
				break;
			}

			cells[0].setX(cells[0].getX() + 2 + i);
			cells[0].setY(cells[0].getY() + 2);
			cells[1].setX(cells[1].getX() + 1 + i);
			cells[1].setY(cells[1].getY() + 1);
			
			cells[3].setX(cells[3].getX() - 1 + i);
			cells[3].setY(cells[3].getY() + 1);
			cells[2].setX(cells[2].getX() + i);
		}

	}
}
