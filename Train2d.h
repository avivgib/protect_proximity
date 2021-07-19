#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct Position
{
	Position()
	{
		x = 0;
		y = 0;
	}
	Position(const Position& p)
	{
		x = p.x;
		y = p.y;
		value = p.value;
	}
	bool operator == (Position& pos)
	{
		if (x == pos.x && y == pos.y)
		{
			return true;
		}
		return false;
	}
	int x, y, value;
};

ostream& operator << (ostream& out, const Position& pos);

class Train2d
{
public:
	Train2d(int rows, int columns);

public:
	//istream& read(istream& in);
	ostream& write(ostream& out);

	void						setStartPosition(int x, int y, int value);
	void						setGoalPosition(int x, int y, int value);
	const Position&				getStartPosition() { return m_start; }
	const Position&				getGoalPosition() { return m_goal; }
	vector<Position>			getPossibleMoves(Position p);
	int							getValuePosition(int, int);
	void						printPosition(Position& p);
	bool						comparePositions(Position& p1, Position& p2);

private:
	Position				 m_start;
	Position			     m_goal;
	vector<vector<Position>> m_vect_mat;
};

//istream& operator >> (istream& in, Train2d& Train2d);
ostream& operator << (ostream& out, Train2d& Train2d);