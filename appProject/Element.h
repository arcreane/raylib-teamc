#pragma once
#include "Graphics.h"
#include "Vec2.h"
class Element :
    public Graphics
{
public:
    Element():Graphics() {};
    void move(Vec2<int> dir);
};

