#pragma once
#include <iostream>
#include <vector>
#include "State.h"
#include "Train2dSearchableT.h"

template <class T>
class Solution
{
public:
	Solution() {};
	~Solution() {};

public:
	vector<State<T>*>	getSolution()					{ return this->m_solution; }
	void				reverseVector()					{ return reverse(m_solution.begin(), m_solution.end()); }
	void				setElement(State<T>* stateT)	{ m_solution.push_back(stateT); }

private:
	std::vector<State<T>*> m_solution;
	//for example [ Right | Right | Down | Down | Left ]
};