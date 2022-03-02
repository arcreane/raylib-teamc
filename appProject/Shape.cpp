#include "Shape.h"
#include <stdlib.h>

Shape::Shape()
{	
	cells.resize(4);
	cells[0] = Vec2{ 0,0 };
	cells[1] = Vec2{ 0,0 };
	cells[2] = Vec2{ 0,0 };
	cells[3] = Vec2{ 0,0 };


}

std::vector<Vec2<int>> Shape::getCells()
{
	return cells;
}


void Shape::retour()
{
}

void Shape::move(Vec2<int> dir)
{
	for (int i = 0; i < 4; i++)
		cells[i] += dir;
}



void Shape::getInput(int input)
{
	if (input == 1) {
		move(Vec2{ 0,1 });
	}
	if (input == 2) {
		move(Vec2{ -1,0 });
	}
	if (input == 3) {
		move(Vec2{ 1,0 });
	}
	if (input == 4) {
		retour();
	}
	}
	

