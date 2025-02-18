// External
#include <iostream>

// Internal
#include "grid.hpp"
#include "complayer.hpp"
#include "humplayer.hpp"
#include "test.hpp"

// Namespaces
using namespace std;

// Definition at bottom of script
void WelcomeMessage(bool test_);

int main(int argc, char *argv[])
{
    // Command line options
    bool test = false; // Default to false

    if (argc > 1) // Check if an argument was provided
    {
        std::string argument = "--test";
        if (argument == argv[1]) // Compare the first argument
            test = true;
    }

    // Welcome our player
    WelcomeMessage(test);

    // Body of the code
	if (test) // Test environment
	{
		return TestCFour();
	}
	else // Actual game
	{
		// Initialize the grid on which the game is played
		CFOUR_Grid grid;
		grid.PrintGameplay();

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
	}

	return 0;
}


void WelcomeMessage(bool test_)
{
	cout <<"    _____        _  _    "<< endl;
   	cout <<"   / ____|      | || |   "<< endl;
   	cout <<"  | |   ______  | || |_  "<< endl;
   	cout <<"  | |  |______| |__   _| "<< endl;
   	cout <<"  | |____          | |   "<< endl;
   	cout <<"   \\_____|         |_|   \n"<< endl;

   	if(test_)
   	{
   		cout << "Hello, this is C-4 are I am going \n";
		cout << "to perform some tests for you.\n\n";
   	}
   	else
   	{
   		cout << "Hello, this is C-4 are you ready \n";
		cout << "for a blasting game????\n\n";
	}

	cout << "Use the --test option to test the" << endl;
	cout << "functionality of the game.\n" <<endl;
}
