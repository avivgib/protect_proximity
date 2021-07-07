#pragma once
#include "CommonSearcher.h"
#include "State.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

template <class T>
class BFS : public CommonSearcher<T>
{
public:
	virtual Solution<T> search(Searchable<T>& s) 
	{
		queue<State<T>*> frontier;
		vector<State<T>*>* possibleStates;
		vector<State<T>*> visited;
		Solution<T> solution;

		State<T>* currentState;
		State<T>* start = s.getStartState();
		State<T>* goal = s.getGoalState();
		
		frontier.push(start);
		visited.push_back(start);
		currentState = frontier.front();

		//while (!(s.compareStates(*currentState, *goal)))
		while (!(frontier.empty()))
		{
			bool currentVisitedFlag = false;
			vector<State<T>*> equalPossibleState;
			for (auto itDupV = visited.begin(); itDupV != visited.end(); ++itDupV)
			{
				if (s.compareStates(**itDupV, *currentState))
					currentVisitedFlag = true;
			}
			if (currentVisitedFlag == false)
			{
				visited.push_back(currentState);
			}
			/*
			if (std::find(visited.begin(), visited.end(), currentState) == visited.end()) {
				// someName not in name, add it
				visited.push_back(currentState);
			}*/
			possibleStates = s.getAllPossibleStates(*currentState);
			
			//possibleStates -  All Possible - States after checked if they in range
			for (auto itPS = possibleStates->begin(); itPS != possibleStates->end(); ++itPS)
			{
				for (auto itV = visited.begin(); itV != visited.end(); ++itV)
				{
					if (s.compareStates(**itPS, **itV))
					{
						equalPossibleState.push_back(*itPS);
					}
				}
			}
			//remove invalid states
			for (auto itEPS = equalPossibleState.begin(); itEPS != equalPossibleState.end(); ++itEPS)
			{
				//State<T>* eps = *itEPS;
				//possibleStates->erase(std::remove(equalPossibleState.begin(), equalPossibleState.end(), itEPS), equalPossibleState.end());
				possibleStates->erase(std::remove(possibleStates->begin(), possibleStates->end(), *itEPS));
			}

			// now possibleStates contain only validat possible state
			for (auto itPS2 = possibleStates->begin(); itPS2 != possibleStates->end(); ++itPS2)
			{
				currentState->setCameFrom(*itPS2);
				frontier.push(*itPS2);
			}

			//possibleStates: All Possible - States after checked they not visited
			if (s.compareStates(*currentState, *goal))
				break;
			frontier.pop();
			currentState = frontier.front();
		}

		State<T>* solState = currentState;
		solution.setElement(solState);

		while (!(s.compareStates(*solState->getCameFrom(), *start)))
		{
			State<T>* stateCameFrom = solState->getCameFrom();
			solution.setElement(stateCameFrom);
			solState = stateCameFrom;
		}
		solution.setElement(solState->getCameFrom());
		solution.reverseVector();

		cout << "The way from start to goal is: " << endl;
		s.printVectorState(solution.getSolution());
		delete start;
		delete goal;
		return solution;
	};

	/*bool eraseState(vector<State<T>*> visited, State<T>* state)
	{
		for (auto it = begin(visited) ; it != end(visited) ; it++)
		{
			if (*it == state)
				return true;
		}
		return false;
	};*/
};