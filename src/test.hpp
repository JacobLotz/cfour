// External
#include <iostream>

// Internal
#include "grid.hpp"

// Namespaces
using namespace std;

bool TestCFour();
bool TestGrid();

bool TestCFour()
{
	bool allpass;

	allpass = TestGrid();

	if (!allpass)
	{	
		cout << "\n___________________________" << endl;
		cout << "FAIL: TESTS HAVE FAILED" << endl;
		cout << "___________________________" << endl;
	}
	else
	{
		cout << "\n___________________________" << endl;
		cout << "SUCCES: ALL TESTS HAVE PASSED" << endl;
		cout << "___________________________" << endl;
	}

	return allpass;
}



// Grid testing functions
bool TestGrid()
{
	cout << "Running tests on the game" << endl;
	bool allpass = true;
	bool pass;

	cout << "\n\n1) Testing CFOUR_Grid::Draw()" << endl;
	{
		CFOUR_Grid grid(false);
		pass = grid.TestDraw();

		if(pass)
			cout <<"-> Test passed" << endl;
		else
		{
			cout <<"-> Test FAILED" << endl;
			allpass = false;
		}
	}

	cout << "\n\n2) Testing Grid::Win()" << endl;
	{
		CFOUR_Grid grid(false);
		pass = grid.TestWin();

		if(pass)
			cout <<"-> Test passed" << endl;
		else
		{
			cout <<"-> Test FAILED" << endl;
			allpass = false;
		}
	}

	cout << "\n\n3) Testing Grid::HumanInsert" << endl;
	{
		CFOUR_Grid grid(false);
		pass = grid.TestHumanInsert();

		if(pass)
			cout <<"-> Test passed" << endl;
		else
		{
			cout <<"-> Test FAILED" << endl;
			allpass = false;
		}
	}

	cout << "\n\n4) Testing Grid::ComputerInsert" << endl;
	{
		CFOUR_Grid grid(false);
		pass = grid.TestComputerInsert();

		if(pass)
			cout <<"-> Test passed" << endl;
		else
		{
			cout <<"-> Test FAILED" << endl;
			allpass = false;
		}
	}

	return allpass;
}