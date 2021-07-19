#include <iostream>
#include <string>
#include "Train2dGenerator.h"
#include "Train2d.h"
#include "SimpleTrain2dGenerator.h"
#include "TestTrainGenerator.h"
#include "Train2dSearchableT.h"
#include "Searcher.h"
#include "Bfs.h"

using namespace std;
int main()
{
	/*Create Train2d*/

	TestTrainGenerator t;
	Train2dGenerator* st2dg = new SimpleTrain2dGenerator();
	t.testTrainGenerator(*st2dg);
	Train2d *train = st2dg->generate(5, 22);
	
	
	
	//cout << *train << endl;
	
	/*------------------------------------------------------*/
	/*Create Search Algorithm*/

	Searcher<Position>* sp = new BFS<Position>();

	//Train2d* train; //st2dg->generate(5, 20);
	Train2dSearchableT ts(*train);
 	Solution<Position> s = sp->search(ts);

	cin.get();
	return 0;
}