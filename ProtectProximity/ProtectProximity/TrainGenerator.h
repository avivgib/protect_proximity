#pragma once
#include<iostream>
#include<string>
#include "Train2d.h"

//insert 1 & 0 to create train
class TrainGenerator
{
public:
	virtual string measureAlgorithmTime(int, int) = 0;
	virtual Train2d* generate(int, int) = 0;
};
