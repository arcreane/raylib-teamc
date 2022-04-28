#pragma once
#include "Graphics.h"
#include "Vec2.h"
class Bomb :
    public Graphics
{
public:
    void move(Vec2<int> dir);
    void explose();
};

