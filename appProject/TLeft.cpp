#include "TLeft.h"

TLeft::TLeft()
{
	cells[0] = Vec2{ 4,2 };
	cells[1] = Vec2{ 5,2 };
	cells[2] = Vec2{ 5,1 };
	cells[3] = Vec2{ 6,1 };
}

void TLeft::Turn()
{

	/*
		  2 3          0
		0 1    ==>  2 1
					 3
							*/

	switch (i) {

	case 2:
		cells[3].setY(cells[3].getY() + 1);
		cells[3].setX(cells[3].getX() - 1);
		cells[1].setX(cells[1].getX() + 1);
		cells[1].setY(cells[1].getY() + 1);
		cells[0].setX(cells[0].getX() + 2);
		break;
	case 3:
		cells[3].setY(cells[3].getY() - 1);
		cells[3].setX(cells[3].getX() + 1);
		cells[1].setX(cells[1].getX() - 1);
		cells[1].setY(cells[1].getY() - 1);
		cells[0].setX(cells[0].getX() - 2);
		i = 0;
		break;
	}

	i++;
}
