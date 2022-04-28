#include "Square.h"
#include <iostream>

Square::Square()
{
	cells[0] = Vec2{ 4,0};
	cells[1] = Vec2{ 5,0 };
	cells[2] = Vec2{ 4,1 };
	cells[3] = Vec2{ 5,1 };

}

void Square::Turn()
{
	std::cout << "tourner" << std::endl;
}
