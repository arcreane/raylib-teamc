#include "Bloc.h"
#include <cassert>
#include <vector>


void Bloc::Update(std::vector<Vec2<int>> pos_in)
{
	for (int i = 0; i < 4; i++)
	{
		cells.push_back(pos_in[i]);
	}
}

