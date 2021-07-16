#include "SimpleTrain2dGenerator.h"
#include <iostream>
Train2d * SimpleTrain2dGenerator::generate(int x, int y)
{
	Train2d* train = new Train2d(x, y);
	train->setStartPosition(0, 0, 0);//Start Position p((x, y) -> value)
	train->setGoalPosition(18, 0, 1);
	return train;
}