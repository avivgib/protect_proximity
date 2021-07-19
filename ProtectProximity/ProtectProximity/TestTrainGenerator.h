#pragma once
#include <iostream>
#include <string>
#include "Train2dGenerator.h"
#include "Train2d.h"
#include "SimpleTrain2dGenerator.h"
using namespace std;

class TestTrainGenerator
{
public:
	TestTrainGenerator() {}

	void testTrainGenerator(Train2dGenerator& tg)
	{
		// prints the time it takes the algorithm to run
		tg.measureAlgorithmTime(5, 22);
		cout << tg << endl;

		// generate another 2d maze
		Train2d* train = tg.generate(5, 22);

		// get the maze entrance
		Position p = train->getGoalPosition();

		// print the position
		//cout << "The goal position is: " << p << endl << endl;
		cout << endl << endl;
		cout << *train << endl;
		//train->write(cout);

		// get all the possible moves from a position
		vector<Position> moves = train->getPossibleMoves(p);

		cout << "The possible moves is: " << endl;
		for (auto move : moves)
			cout << move << endl;

		//cout << train->getGoalPosition() << endl;
	}
};
