#pragma once

#include <vector>
#include "State.h"

template <class T>
class Searchable
{
public:
	virtual State<T>*			getStartState() = 0;
	virtual State<T>*			getGoalState() = 0;
	virtual vector<State<T>*>*	getAllPossibleStates(State<T>& s) = 0;

	virtual void				printState(State<T>& p) = 0;
	virtual void				printVectorState(vector<State<T>*> p1) = 0;
	virtual bool				compareStates(State<T> & p1, State<T> & p2) = 0;
};