#include "Board.h"
#include <assert.h>
#include "Shape.h"
#include <vector>

/*int Board::RemoveLines()
{
	// This removes the full rows
	int removed = 0;
	for (int i = height - 1; i >= 0; i--)
	{
		bool entireLine = true;
		for (int j = 0; j < width; j++)
		{
			if (cells[j * width + i].getVal() == 0)
			{
				entireLine = false;
			}
		}
		if (entireLine)
		{
			removed++;
			for (int k = i; k > 0; k--)
			{
				for (int j = 0; j < width; j++)
				{
					cells[j * width + k].setVal(cells[j * width + k - 1].getVal());

				}
			}
			i++;
		}
	}
	return removed;
}*/

Board::Board(Color color):
	Graphics::Graphics(color)
{
	
	cells.resize((double)width * (double)height);

}

void Board::SetCell(Vec2<int> pos_in, Color c, int v)
{
	assert(pos_in.getX() >= 0 && pos_in.getY() >= 0);
	assert(pos_in.getX() < width && pos_in.getY() < height);
	cells[(double)pos_in.getY() * (double)width + (double)pos_in.getX()].setColor(c);
	cells[(double)pos_in.getY() * (double)width + (double)pos_in.getX()].setVal(v);
}

int Board::CheckCells(std::vector<Vec2<int>> shape)
{	//tache 1
	//�liminer une rang�e et marquer
	return 1;
}





void Board::DrawBorder() const
{
	raycpp::DrawRectangleLinesEx(ScreenPos - (cellSize / 2), Vec2{ width * cellSize,height * cellSize } + cellSize,
		cellSize / 2, GREEN);
}

void Board::Draw() const
{
	for (int iY = 0; iY < height; iY++)
		for (int iX = 0; iX < width; iX++)
			DrawCell(Vec2<int>{iX, iY});
}

void Board::DrawNext(int type)
{
	Vector2 p1, p2, p3, p4, size;
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
	DrawText(text, posX, posY2, fontSize2, WHITE);
	DrawText(scores, posX, posY, fontSize, WHITE);
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
	//v�rifier ce tableau =>std::vector<Cell> cells;
	//S'il y a une rang�e enti�rement blanche, supprimez cette rang�e.
	// et renvoie un score correspondant
	//
	return 0;
}
