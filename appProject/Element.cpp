#include "Element.h"

std::vector<Vec2<int>> Element::getCells()
{
	return cells;
}

void Element::setCells(std::vector<Vec2<int>> c)
{
	cells = c;
}



void Element::move(Vec2<int> dir)
{
	for (int i = 0; i < cells.size(); i++)
		cells[i] += dir;
}



void Element::getInput(int input)
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
		Turn();
	}
}

int Element::right()
{
	int max = 0;
	for (int i = 0; i < cells.size(); i++) {

		if (cells[i].getX() > max) {
			max = cells[i].getX();
		}

	}

	return max;
}

int Element::left()
{
	int min = 9;
	for (int i = 0; i < cells.size(); i++) {

		if (cells[i].getX() < min) {
			min = cells[i].getX();
		}

	}

	return min;
}
