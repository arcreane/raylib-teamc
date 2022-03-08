#include "LLeft.h"
#include <iostream>
using namespace std;
LLeft::LLeft()
{
	cells[0] = Vec2{ 5,0 };
	cells[1] = Vec2{ 5,1 };
	cells[2] = Vec2{ 5,2 };
	cells[3] = Vec2{ 4,2 };
}

void LLeft::Turn() 
{
	
	
	if (cells[2].getX() - cells[3].getX() == 0) {
		if (cells[2].getY() - cells[3].getY()>0) {
			/* 0        00
			   000  ==> 0
						0*/

			cells[0].setX(cells[0].getX() - 2);
			cells[0].setY(cells[0].getY() + 2);
			cells[1].setX(cells[1].getX() - 1);
			cells[1].setY(cells[1].getY() + 1);
			cells[3].setX(cells[3].getX() + 1);
			cells[3].setY(cells[3].getY() + 1);
		}
		else
		{
			/* 000       0
			     0  ==>  0
						00*/
			cells[0].setX(cells[0].getX() + 2);
			cells[0].setY(cells[0].getY() - 2);
			cells[1].setX(cells[1].getX() + 1);
			cells[1].setY(cells[1].getY() - 1);
			cells[3].setX(cells[3].getX() - 1);
			cells[3].setY(cells[3].getY() - 1);
		}
	}
	else
	{
		if (cells[2].getX() - cells[3].getX() > 0) {
			cells[0].setX(cells[0].getX() + 2);
			cells[0].setY(cells[0].getY() + 2);
			cells[1].setX(cells[1].getX() + 1);
			cells[1].setY(cells[1].getY() + 1);
			cells[3].setX(cells[3].getX() + 1);
			cells[3].setY(cells[3].getY() - 1);
		}
		else
		{
			cells[0].setX(cells[0].getX() - 2);
			cells[0].setY(cells[0].getY() - 2);
			cells[1].setX(cells[1].getX() - 1);
			cells[1].setY(cells[1].getY() - 1);
			cells[3].setX(cells[3].getX() - 1);
			cells[3].setY(cells[3].getY() + 1);
		}

	}

}
