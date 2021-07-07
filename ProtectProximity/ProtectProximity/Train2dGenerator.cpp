#include "Train2dGenerator.h"

string Train2dGenerator::measureAlgorithmTime(int x, int y)
{
	auto start = high_resolution_clock::now();
	Train2d* td = this->generate(x, y);
	auto stop = high_resolution_clock::now();
	cout << *td << endl;
	auto duration = duration_cast<milliseconds>(stop - start);
	m_measureTime = to_string(duration.count());
	return m_measureTime;
}

/*----------------------------------------------------------------------------*/
ostream & Train2dGenerator::write(ostream & out)
{
	out << "Time taken by function: " << m_measureTime << " microseconds!";
	return out;
}
/*----------------------------------------------------------------------------*/

ostream &operator<<(ostream & out, Train2dGenerator & train2dg)
{
	train2dg.write(out);
	return out; 
}