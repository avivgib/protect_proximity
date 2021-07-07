#include "Train2dSearchableT.h"

void Train2dSearchableT::printState(State<Position>& p1)
{
	m_train->printPosition(*p1.getState());
}

void Train2dSearchableT::printVectorState(vector<State<Position>*> p1)
{
	for (int i = 0; i < int(p1.size()); i++)
	{
		m_train->printPosition(*p1[i]->getState());
	}
}

bool Train2dSearchableT::compareStates(State<Position>& p1, State<Position> & p2)
{
	if (m_train->comparePositions(*p1.getState(), *p2.getState()))
		return true;
	return false;
}

State<Position>* Train2dSearchableT::getStartState()
{
	Position p = m_train->getStartPosition();
	State<Position>* p1 = new State<Position>(p);// Adaptter DP
	return p1;
}

State<Position>* Train2dSearchableT::getGoalState() //const
{
	Position p2 = m_train->getGoalPosition();
	State<Position>* p3 = new State<Position>(p2);// Adaptter DP
	return p3;
}

std::vector<State<Position>*>* Train2dSearchableT::getAllPossibleStates(State<Position>& p)
{
	std::vector<State<Position>*>* smoves = new std::vector<State<Position>*>();
	std::vector<Position> moves = m_train->getPossibleMoves(*p.getState());
	for (auto it = moves.begin(); it != moves.end(); ++it)
	{
		smoves->push_back(new State<Position>(*it)); // Adapter DP loop
	}
	return smoves;
}