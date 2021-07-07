#pragma once
#include <chrono>
#include <sstream>
#include "Train2d.h"
#include "TrainGenerator.h"
#include <string> // for string

using namespace std;
using namespace std::chrono;

//insert 1 & 0 to create train
class Train2dGenerator : public TrainGenerator
{
public:
	Train2dGenerator() {}

public:
	virtual Train2d* generate(int, int) = 0;
	virtual string measureAlgorithmTime(int, int);

public:
	//virtual istream& read(istream& in);
	virtual ostream& write(ostream& out);

private:
	//Train2d& 
	string m_measureTime;

};

ostream &operator<<(ostream & out, Train2dGenerator & train2dg);