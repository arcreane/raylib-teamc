#pragma once
#include <raylib.h>
class Graphics
{
public:
	Color color;
	Graphics() { color = WHITE; }
	Graphics(Color color) { this->color = color; }
	~Graphics(){}
};

