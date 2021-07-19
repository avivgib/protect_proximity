#include "Train2d.h"
using namespace std;


ostream& operator << (ostream& out, const Position& pos)
{
	out << "(" << pos.x << ", " << pos.y << ")->" << pos.value << "." << endl;
	return out;
}

void Train2d::printPosition(Position& p)
{
	cout << p << endl;
}

bool Train2d::comparePositions(Position & p1, Position & p2)
{
	if (p1 == p2)
	{
		return true;
	}
	return false;
}


Train2d::Train2d(int columns, int rows)
{
	int r = rows;
	int c = columns;
	m_vect_mat.resize(r, vector<Position>(c));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			/*if (i == 0 || i == r - 1 || j == 2 || (i % 4 == 3 && j == 1) || (i % 4 == 3 && j == 3))
			{
				m_vect_mat[i][j].value = 0;
				m_vect_mat[i][j].x = i;
				m_vect_mat[i][j].y = j;
			}*/
			if ((i % 2 == 0 && j != 2 && i < r - 2 && i > 0))
			{
				m_vect_mat[i][j].value = 1;
				m_vect_mat[i][j].x = i;
				m_vect_mat[i][j].y = j;
				continue;
			}
			if ((i % 2 == 1 && i > 0 && i < r - 1) && (j != 2))
			{
				m_vect_mat[i][j].value = 3;
				m_vect_mat[i][j].x = i;
				m_vect_mat[i][j].y = j;
				continue;
			}
			else
			{
				m_vect_mat[i][j].value = 0;
				m_vect_mat[i][j].x = i;
				m_vect_mat[i][j].y = j;
			}
		}
	}
}


vector<Position> Train2d::getPossibleMoves(Position p)
{
	Position temp_pos;
	vector<Position> vec_pos_moves;

	if (p.value != 3)
	{
		//up
		if (p.x != 0)
		{
			temp_pos.x = p.x - 1;
			temp_pos.y = p.y;
			temp_pos.value = m_vect_mat[p.x -1][p.y].value;
			if (temp_pos.value == 0 || temp_pos.value == 1)
				vec_pos_moves.push_back(temp_pos);
		}
		//right
		if (p.y != 4)
		{
			temp_pos.x = p.x;
			temp_pos.y = p.y + 1;
			temp_pos.value = m_vect_mat[p.x][p.y + 1].value;
			if (temp_pos.value == 0 || temp_pos.value == 1)
				vec_pos_moves.push_back(temp_pos);
		}
		//down
		if (p.x != 19)
		{
			temp_pos.x = p.x + 1;
			temp_pos.y = p.y;
			temp_pos.value = m_vect_mat[p.x + 1][p.y].value;
			if (temp_pos.value == 0 || temp_pos.value == 1)
				vec_pos_moves.push_back(temp_pos);
		}
		//left
		if (p.y != 0)
		{
			temp_pos.x = p.x;
			temp_pos.y = p.y - 1;
			temp_pos.value = m_vect_mat[p.x][p.y - 1].value;
			if (temp_pos.value == 0 || temp_pos.value == 1)
				vec_pos_moves.push_back(temp_pos);
		}
	}
	else
		cout << "Test not possible!" << endl;
	return vec_pos_moves;
}

int Train2d::getValuePosition(int x, int y)
{
	int value = m_vect_mat[x][y].value;
	return value;
}
/*Stop here - creat operator << and >> by read and write mwthods 
void Train2d::read(istream& in) 
{
	in >> m_start.print;
	in >> m_goal.print;
	for (int i = 0; i < m_vect_mat.size(); i++) {
		for (int j = 0; j < m_vect_mat[i].size(); j++)
			cout << "(" << m_vect_mat[i][j].x << ", "<< m_vect_mat[i][j].y << ")" 
			<< "->" << m_vect_mat[i][j].value << " ";
		cout << endl;
	}
}

*/

ostream & Train2d::write(ostream & out)
{
	out << "Start Position" << endl;
	out << "(" << m_start.x << ", " << m_start.y << ") ->" << m_start.value << endl << endl;
	out << "Goal Position" << endl;
	out << "(" << m_goal.x << ", " << m_goal.y << ") ->" << m_goal.value << endl << endl;
	out << "Train Sketch" << endl;
	for (vector<Position> i : m_vect_mat)
	{
		for (Position j : i)
		{
			out /*<< "(" << j.x << ", "
				<< j.y << ") ->"
				*/<< j.value << " ";
		}
		out << endl;
	}
	return out;
}

void Train2d::setStartPosition(int x, int y, int value)
{
	m_start.x = x;
	m_start.y = y;
	m_start.value = value;
}
void Train2d::setGoalPosition(int x, int y, int value)
{
	m_goal.x = x;
	m_goal.y = y;
	m_goal.value = value;
}


/*----------------------------------------------------------------------------
istream& operator >> (istream& in, Train2d& train2d)
{
	train2d.read(in);
    return in;
}
/*----------------------------------------------------------------------------*/
ostream& operator << (ostream& out, Train2d& train2d)
{
	train2d.write(out);
    return out;
}
/*----------------------------------------------------------------------------*/