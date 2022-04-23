#include "Board.h"
#include <assert.h>
#include <iostream>

#include "Shape.h"
#include <vector>
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
	//ï¿½liminer une rangï¿½e et marquer
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

void Board::DrawNext(int type)
{
	Vector2 p1, p2, p3,p4,size;
	size = { 17,17 };
	switch (type)
	{
	case 1: // Square
		p1 = { 475, 150 };
		p2 = { 475, 169 };
		p3 = { 494, 150 };
		p4 = { 494, 169 };

		DrawRectangleV(p1, size, WHITE);
		DrawRectangleV(p2, size, WHITE);
		DrawRectangleV(p3, size, WHITE);
		DrawRectangleV(p4, size, WHITE);
		break;
	case 2: //Line
		p1 = { 475, 150 };
		p2 = { 494, 150 };
		p3 = { 513, 150 };
		p4 = { 532, 150 };

		DrawRectangleV(p1, size, WHITE);
		DrawRectangleV(p2, size, WHITE);
		DrawRectangleV(p3, size, WHITE);
		DrawRectangleV(p4, size, WHITE);

	
		break;
	case 3: // LRight
		p1 = { 475, 150 };
		p2 = { 475, 169 };
		p3 = { 475, 188 };
		p4 = { 494, 188 };

		DrawRectangleV(p1, size, WHITE);
		DrawRectangleV(p2, size, WHITE);
		DrawRectangleV(p3, size, WHITE);
		DrawRectangleV(p4, size, WHITE);
		break;
	case 4: //LLeft
		p1 = { 475, 150 };
		p2 = { 475, 169 };
		p3 = { 475, 188 };
		p4 = { 456, 188 };

		DrawRectangleV(p1, size, WHITE);
		DrawRectangleV(p2, size, WHITE);
		DrawRectangleV(p3, size, WHITE);
		DrawRectangleV(p4, size, WHITE);
		break;
	case 5: //ollo
		p1 = { 475, 150 };
		p2 = { 475, 169 };
		p3 = { 456, 169 };
		p4 = { 494, 169 };

		DrawRectangleV(p1, size, WHITE);
		DrawRectangleV(p2, size, WHITE);
		DrawRectangleV(p3, size, WHITE);
		DrawRectangleV(p4, size, WHITE);	
		break;
	case 6: //Zleft
		p1 = { 513, 150 };
		p2 = { 494, 150 };
		p3 = { 494, 169 };
		p4 = { 475, 169 };

		DrawRectangleV(p1, size, WHITE);
		DrawRectangleV(p2, size, WHITE);
		DrawRectangleV(p3, size, WHITE);
		DrawRectangleV(p4, size, WHITE);
		break;
	default://Zright
		p1 = { 475, 150 };
		p2 = { 494, 150 };
		p3 = { 494, 169 };
		p4 = { 513, 169 };

		

		DrawRectangleV(p1, size, WHITE);
		DrawRectangleV(p2, size, WHITE);
		DrawRectangleV(p3, size, WHITE);
		DrawRectangleV(p4, size, WHITE);
		break;
	}
	
}

void Board::DrawScore(std::string score)
{
	int posX = 470;
	int posY = 400;
	int posY2 = 370;
	int fontSize = 40;
	int fontSize2 = 30;
	const char* scores = score.data();
	const char* text = "Scores: ";
	DrawText(text,  posX,  posY2,fontSize2 , WHITE);
	DrawText(scores,  posX,  posY,fontSize , WHITE);
}

void Board::DrawLevel(std::string level)
{
	int posX = 470;
	int posY = 300;
	int posY2 = 270;
	int fontSize = 40;
	int fontSize2 = 30;
	const char* levels = level.data();
	const char* text = "Level: ";
	DrawText(text, posX, posY2, fontSize2, WHITE);
	DrawText(levels, posX, posY, fontSize, WHITE);
}

int Board::getScore()
{
	bool  isWhite = true;
	int score = 0;

	for (int i = 0; i < cells.size(); i++)
	{   //vérifier ce tableau =>std::vector<Cell> cells;

		for (int j=0; j < width; j++) {
			{
				std::cout << "this is a me\n";
				Color cell_color = cells[i].getColor();
				if (cell_color.a == RED.a && cell_color.r == RED.r && cell_color.g == RED.g && cell_color.b == RED.b)
				{
					isWhite = false;
				}
			}
			if (isWhite == true) {
				//S'il y a une rangée entièrement blanche, supprimez cette rangée.
				for (int k = (i - width + 1); k <= i; k++) {
					cells[k].setColor(RED);
				}
				std::cout << "game over" << endl;

				score++;
			}
			isWhite = true;

		}
		isWhite = true;

		
		
		return score;
	}
}
