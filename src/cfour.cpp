// External
#include <iostream>


// Internal
#include "grid.hpp"
#include "complayer.hpp"
#include "humplayer.hpp"

// Namespaces
using namespace std;


int main()
{
	// Initialize the grid on which the game is played
	CFOUR_Grid grid;

	// Initialize the communicator with the human player
	CFOUR_Humplayer humplayer(grid);

	// Initialize the automatic computer player
	CFOUR_Complayer complayer(grid);

	// Run the game
	bool gamewon = false;

	while(gamewon == false)
	{
		humplayer.Play();
		grid.Print();
		gamewon = grid.Win();

		if(gamewon == true)
			break;

		complayer.Play();
		grid.Print();
		gamewon = grid.Win();
	}


	return 0;
}