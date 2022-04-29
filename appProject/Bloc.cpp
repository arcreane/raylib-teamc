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
			if (std::find(cells.begin(), cells.end(), Vec2<int>{220, 140}) != cells.end())
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

int Bloc::checkCell(Vec2<int> cell)
{
	if (std::find(cells.begin(), cells.end(), cell) != cells.end()) {
		return 1;
	}

	return 0;
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
	for (int y = posY; y >= 0; y--)
	{
		for (int x = 0; x < 10; x++)
		{//TODO
			/*if (find(cells.begin(), cells.end(), Vec2<int>{x, y}))
			{

			}*/
		}

	}


}