#pragma once
#include <string>
#include <memory>
using namespace std;

template <class T>
class State
{
public:
	State(T& state) : m_state(new T(state)), m_cost(0), m_cameFrom(nullptr) {}
	~State() { delete m_state; };

public:
	bool operator()(State& s1, State& s2)
	{
		// If values are the same then
		// return true
		if (s2.m_state() == s2.getState()) {
			return true;
		}
		return false;
	}
	bool				operator != (State& s)		{ return this.m_state != s.m_state; }
	T*					getState()					{ return this->m_state; }
	State<T>*			getCameFrom()				{ return m_cameFrom; }
	void				setCameFrom(State<T>* scf)	{ scf->m_cameFrom = this; } //insert current state to s.m_cameFrom
	State<T>*			operator = (State<T>* s)	{ return *this; }
	//State<T>*			operator == (State<T>* s)	{ return this.m_state.compare(s.m_state) == 0;; }

private:
	T*						m_state; //data
	double					m_cost;
	State<T>*				m_cameFrom;
};