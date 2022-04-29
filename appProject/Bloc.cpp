#include "Bloc.h"
#include <cassert>
#include <vector>




Bloc::Bloc():
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
	for (int y = 0; y < 20; y++)
	{
		flag = 0;
		for (int x = 0;  x< 10; x++)
		{
			if (std::find(cells.begin(), cells.end(), Vec2<int>{220,140}) != cells.end())
			{
				flag++;
			}
		}
		if (flag == 10)
		{
			DeleteLine(y);
			lineScore ++;
		}

	}
	
}

void Bloc::DeleteLine(int posY)
{
}

