#pragma once
#include "State.h"
#include "Train2d.h"

class Train2dState : public State<Position>
{
public:
	Train2dState(Position state) : State(state) {}
	~Train2dState() {}

	//double calculatecost(State& targetstate) {}//TO-DO COST calculation
};