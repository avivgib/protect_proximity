#pragma once
#include "Train2dGenerator.h"
#include "Train2d.h"

class SimpleTrain2dGenerator : public Train2dGenerator
{
public:
	SimpleTrain2dGenerator() {}

public:
	virtual Train2d* generate(int x, int y);

private:
	Train2d* train;
};