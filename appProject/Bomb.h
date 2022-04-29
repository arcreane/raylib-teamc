#pragma once
#include "Graphics.h"
#include "Vec2.h"
class Bomb :
    public Graphics
{
public:
    int rowScore;
    Bomb();
    void move(Vec2<int> dir);
    void explose();
};

