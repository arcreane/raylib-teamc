#include "Bomb.h"

Bomb::Bomb() :
	Element()
{
	cells.resize(1);
	cells[0] = Vec2{ 5,0 };
	color = YELLOW;
}



