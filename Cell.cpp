#include "Cell.h"

Cell::Cell()
	:bExists{ false },
	c{ WHITE }, val{ 1 }{
	
}

void Cell::setColor(Color c_in)
{
	c = c_in;
	bExists = true;
}

void Cell::Remove()
{
	bExists = false;
}

Color Cell::getColor() const
{
	return c;
}

void Cell::setVal(int v)
{
	val = v;
}

int Cell::getVal()
{
	return val;
}