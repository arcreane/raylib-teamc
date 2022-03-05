#include "TLeft.h"

TLeft::TLeft()
{
	cells[0] = Vec2{ 2,1 };
	cells[1] = Vec2{ 1,2 };
	cells[2] = Vec2{ 3,1 };
	cells[3] = Vec2{ 2,2 };
}

void TLeft::Turn()
{
	//if (cells[0].getX() == cells[2].getX()) // getX==5
	//{

	//	cells[0].setX(cells[0].getX() - 1);
	//	//cells[0].setY(cells[0].getY() - 1);
	//	cells[2].setX(cells[2].getX() - 1); // 6
	//	//cells[2].setY(cells[2].getY() - 1);
	//	//cells[3].setX(cells[3].getX() + 2);
	//	//cells[3].setY(cells[3].getY() - 2);
	//}
	//else
	//{
	//	cells[0].setX(cells[0].getX() + 1);

	//	//cells[0].setY(cells[0].getY() - 1);

	//	cells[2].setX(cells[2].getX() + 1); // 5
	//	//cells[2].setY(cells[2].getY() + 1);
	//	//cells[3].setX(cells[3].getX() - 1);
	//	//cells[3].setY(cells[3].getY() + 2);

	//}
}
