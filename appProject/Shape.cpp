#include "Shape.h"
#include <stdlib.h>
#include <iostream>

Shape::Shape()
{	
	cells.resize(4);
	colors.resize(4);
	for (int i = 0; i < 4; i++)
		colors[i] = WHITE;
		cells[i] = Vec2{ 0,0 };

}

std::vector<Vec2<int>> Shape::getCells()
{
	return cells;
}

std::vector<Color> Shape::getColors()
{
	return colors;
}

void Shape::setCells(std::vector<Vec2<int>> c)
{
	cells = c;
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
		Turn();
	}
	}

int Shape::right()
{
	int max=0;
	for (int i = 0; i < 4; i++) {
	
		if (cells[i].getX() > max){
			max = cells[i].getX();
		}
	
		}

	return max;
}

int Shape::left()
{
	int min = 9;
	for (int i = 0; i < 4; i++) {
		
		if (cells[i].getX() < min) {
			min = cells[i].getX();
		}
	
		}

	return min;
}
	

