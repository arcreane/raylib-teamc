#include "Board.h"
#include <assert.h>
#include "Shape.h"
Board::Cell::Cell()
	:bExists{false},
	c{WHITE}

{

}

void Board::Cell::setColor(Color c_in)
{
	c = c_in;
	bExists = true;
}

void Board::Cell::Remove()
{
	bExists = false;
}

Color Board::Cell::getColor() const
{
	return c;
}

Board::Board(Vec2<int> pos, Vec2<int> shape, int size,int padding_in)
	:ScreenPos(pos),
	width(shape.getX()),
	height(shape.getY()),
	cellSize(size),
	padding(padding_in)
{
	assert(width > 0 && height>0);
	assert(size > 0);
	cells.resize((double)width * (double)height);

}

void Board::SetCell(Vec2<int> pos_in, Color c)
{	
	assert(pos_in.getX() >= 0 && pos_in.getY() >= 0);
	assert(pos_in.getX() < width&& pos_in.getY() < height);
	cells[(double)pos_in.getY() * (double)width + (double)pos_in.getX()].setColor(c);
}

int Board::CheckCells(std::vector<Vec2<int>> shape)
{	//tache 1
	//�liminer une rang�e et marquer
	return 1;
}

void Board::DrawCell(Vec2<int> pos_in) const
{	
	assert(pos_in.getX() >= 0 && pos_in.getY() >= 0);
	assert(pos_in.getX() < width && pos_in.getY() < height);
	Color c=cells[(double)pos_in.getY() * (double)width + (double)pos_in.getX()].getColor();
	Vec2<int> topleft = ScreenPos + padding + (pos_in * cellSize);
	raycpp::DrawRectangle(topleft, Vec2{cellSize,cellSize}-padding, c);
}

void Board::DrawBorder() const
{
	raycpp::DrawRectangleLinesEx(ScreenPos - (cellSize / 2), Vec2{ width * cellSize,height * cellSize } + cellSize,
									cellSize/2,GREEN);
}

void Board::Draw() const
{
	for (int iY = 0; iY < height; iY++)
		for (int iX = 0; iX < width; iX++)
			DrawCell(Vec2<int>{iX, iY});
}

int Board::getScore()
{
	return 0;
}
