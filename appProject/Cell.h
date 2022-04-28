#pragma once
#include "raylibcpp.h"

class Cell
{
public:
	Cell();
	void setColor(Color c_in);
	void Remove();
	Color getColor() const;
	void setVal(int v);
	int getVal();
private:
	bool bExists;
	Color c;
	int val;
};

