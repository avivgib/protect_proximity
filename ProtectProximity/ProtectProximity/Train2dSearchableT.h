#pragma once
#include "Searchable.h"
#include "Train2d.h"

class Train2dSearchableT :public Searchable<Position>
{
public:
	Train2dSearchableT(Train2d& train) : m_train(&train) {}

public:
	//Add implementation for shose methods
	virtual State<Position>*			getStartState();
	virtual State<Position>*			getGoalState();
	virtual vector<State<Position>*>*	getAllPossibleStates(State<Position>& p);

	virtual void						printState(State<Position>& p);
	virtual void						printVectorState(vector<State<Position>*> p1);
	virtual bool						compareStates(State<Position> & p1, State<Position> & p2);

private:
	Train2d* m_train;
};

