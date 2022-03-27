#pragma once
#include "Shape.h"
class Square :
    public virtual Shape
{
public:
    Square();
    void Turn()  override;
};