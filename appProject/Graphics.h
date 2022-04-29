#pragma once
#include <raylib.h>
#include "Vec2.h"
#include "raylibcpp.h"

#include<vector>
class Graphics
{
public:
	Color color;
	std::vector<Vec2<int>> cells;
	void Draw();
	void DrawCell(Vec2<int> pos_in) const;
	Graphics();
	Graphics(Color color);
	~Graphics() {}

protected:
	int width;
	int height;
	int cellSize;
	int padding;
	
	Vec2<int> ScreenPos;
};

