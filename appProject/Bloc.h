#pragma once
#include "Graphics.h"
class Bloc :
    public Graphics
{
public:
    void Update(std::vector<Vec2<int>> cells);
};

