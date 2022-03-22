#pragma once
#include <raylib.h>
#include "Vec2.h"
namespace raycpp
{
	void DrawRectangle(Vec2<int> pos, Vec2<int> shape, Color c);
	void DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> WidthHeight,int lineThick, Color c);
}