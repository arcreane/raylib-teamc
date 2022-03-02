#include "raylibcpp.h"
#include <assert.h>
void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> shape, Color c)
{
	assert(pos.getX() >= 0 && pos.getY() >= 0);
	assert(pos.getX() < GetScreenWidth() && pos.getY() < GetScreenHeight());
	DrawRectangle(pos.getX(), pos.getY(), shape.getX(), shape.getY(), c
	);
}
