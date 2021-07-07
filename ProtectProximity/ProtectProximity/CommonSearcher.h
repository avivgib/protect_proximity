#pragma once
#include "Searcher.h"
#include <queue>

template <class T>
class CommonSearcher : public Searcher<T>
{
public:
	CommonSearcher() : m_evaluatedNodes(0) {}

	//Abstraction
public:
	virtual Solution<T> search(Searchable<T>& s) = 0;
	virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; };

	//Aditional implementation
public:
	const State<T>& popOpenList() { return m_openList.top(); }
	void addToOpenList() { m_evaluatedNodes++; }

protected:
	int m_evaluatedNodes;						//number of nodes are solved
	std::priority_queue<State<T>*> m_openList;	//All state are possible
};