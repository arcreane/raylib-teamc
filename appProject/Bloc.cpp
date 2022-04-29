#include "Bloc.h"
#include <cassert>
#include <vector>
#include <algorithm>




Bloc::Bloc() :
	Graphics()
{
	lineScore = 0;
}

void Bloc::Update(std::vector<Vec2<int>> pos_in)
{
	int flag = 0;
	for (int i = 0; i < 4; i++)
	{
		cells.push_back(pos_in[i]);
	}
	//check delete
	for (int y = 0; y < 20; y++)
	{
		flag = 0;
		for (int x = 0; x < 10; x++)
		{
			if (std::find(cells.begin(), cells.end(), Vec2<int>{x, y}) != cells.end())
			{
				flag++;
			}
		}
		if (flag == 10)
		{
			DeleteLine(y);
			lineScore++;
		}

	}

}

int Bloc::checkCell(std::vector<Vec2<int>> cell, Shape* shape)
{
	std::vector<Vec2<int>> currpos = shape->getCells();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < cells.size(); j++)
		{
			if (std::find(cells.begin(), cells.end(), currpos[i]) != cells.end()) {
				shape->setCells(cell);
				return 1;
			}
		}
	}
	//atButtom
	std::vector<Vec2<int>> nextpos;
	for (int i = 0; i < 4; i++)
	{
		nextpos.push_back(shape->getCells()[i] + Vec2<int>{0, 1});
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < cells.size(); j++)
		{
			if (std::find(cells.begin(), cells.end(), nextpos[i]) != cells.end()) {
				//shape->setCells(currpos);
				Update(shape->getCells());
				return 0;
			}
		}
	}
	return 1;
}

void Bloc::DeleteRow(Vec2<int> pos)
{
	for (int i = pos.getY(); i < 20; i++)
	{
		std::remove(cells.begin(), cells.end(), Vec2<int>{ pos.getX(), i});
	}
}

void Bloc::DeleteLine(int posY)
{
	for (int i = 0; i < 10; i++)
	{
		std::remove(cells.begin(), cells.end(), Vec2<int>{i, posY});
	}
	//std::vector<int>::iterator it;
	for (int i = 0; i < cells.size(); i++)
	{
		if (cells[i].getY() < posY) {
			cells[i] += Vec2<int> {0, 1};
		}
	}


}