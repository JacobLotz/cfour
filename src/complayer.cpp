// Internal
#include "complayer.hpp"

// External
#include <iostream>

using namespace std;

CFOUR_Complayer::CFOUR_Complayer(CFOUR_Grid& grid_):
	grid(grid_)
{
	// Create and set a seeder for the random number generator
	time_t current_time = time(NULL);
	srand((unsigned) time(NULL));

	wgrid = grid.GetWidth();
}

void CFOUR_Complayer::Play()
{
	int i;
	bool noentry = true;

	while(noentry)
	{
		// Random number between 0 and wgrid
		i = (rand() % wgrid);

		if (!grid.CheckColFull(i))
		{
			noentry = false;
		}
	}

	cout << "\n___________________________\n" << endl;
	cout << "I play in column " << i << endl;

	grid.ComputerInsert(i);
}
