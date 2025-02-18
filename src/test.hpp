// External
#include <iostream>

// Internal
#include "grid.hpp"

// Namespaces
using namespace std;

bool TestCFour();
bool TestGrid();

// Returns true if all tests are passed
bool TestCFour()
{
	cout << "\nTESTING THE FUNCTIONALITY OF THE GAME" << endl;

	bool allpass;

	allpass = TestGrid();

	if (!allpass)
	{	
		cout << "\nFAIL: TESTS HAVE FAILED" << endl;
	}
	else
	{
		cout << "\nSUCCES: ALL TESTS HAVE PASSED" << endl;
	}

	cout << "allpass = " << allpass << endl;
	return allpass;
}

// Grid testing functions. Returns true if all tests are passed.
bool TestGrid()
{
	bool allpass = true;
	bool pass;

	cout << "\n\n1) Testing CFOUR_Grid::Draw()" << endl;
	{
		CFOUR_Grid grid;
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
		CFOUR_Grid grid;
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
		CFOUR_Grid grid;
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
		CFOUR_Grid grid;
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