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
	bool gamedraw = false;

	while(1)
	{
		// Human player plays
		humplayer.Play();
		grid.Print();
		gamewon = grid.Win();
		gamedraw = grid.Draw();

		if(gamewon == true || gamedraw == true)
			break;

		// Computer plays
		complayer.Play();
		grid.Print();
		gamewon = grid.Win();
		gamedraw = grid.Draw();

		if(gamewon == true || gamedraw == true)
			break;
	}


	return 0;
}