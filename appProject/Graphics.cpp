#include "Graphics.h"
#include <cassert>


void Graphics::DrawCell(Vec2<int> pos_in) const
{

		assert(pos_in.getX() >= 0 && pos_in.getY() >= 0);

		assert(pos_in.getX() < 10 && pos_in.getY() < 20);

		Vec2<int> topleft = ScreenPos + padding + (pos_in * cellSize);
		raycpp::DrawRectangle(topleft, Vec2{ cellSize,cellSize } - padding, color);
	
}

Graphics::Graphics()
{
	width = 10;
	height = 20;
	cellSize = 20;
	padding = 2;
	ScreenPos = { 200,120 };
	color = WHITE;
}
Graphics::Graphics(Color color){
	width = 10;
	height = 20;
	cellSize = 20;
	padding = 2;
	ScreenPos = { 200,120 };
	this->color = color;
}
