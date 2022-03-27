#include "Shapebonus.h"
#include<stdlib.h>
Shapebonus::Shapebonus()
{
	
	for (int i = 0; i < 4; i++)
		colors[i] = ranColor();	

}

Color Shapebonus::ranColor()
{
	int number;
	Color color;
	number = rand() % 3 + 1;
	switch (number) {
	case 1:color = BLUE; break;
	case 2:color = GRAY; break;
	default :color = GOLD; break;

	}
	

	return color;
}
