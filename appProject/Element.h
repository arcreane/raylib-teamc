#pragma once
#include "Graphics.h"
#include "Vec2.h"
class Element :
    public Graphics
{
public:
    Element() {};
    void move(Vec2<int> dir);
};

