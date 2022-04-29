#include "Shape.h"
#include <stdlib.h>
#include <iostream>
#include"Vec2.h"

Shape::Shape():
	Element()
{	
	i = 0;
	cells.resize(4);
	cells[0] = Vec2{ 0,0 };
	cells[1] = Vec2{ 0,0 };
	cells[2] = Vec2{ 0,0 };
	cells[3] = Vec2{ 0,0 };

}



	

