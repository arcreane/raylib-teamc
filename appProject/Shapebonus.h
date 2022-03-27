#pragma once
#include "Shape.h"
class Shapebonus :
    public virtual Shape
{
public:
    Shapebonus();
private:
    Color ranColor();

};

