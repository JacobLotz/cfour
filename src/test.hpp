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

	bool allfail;

	allfail = TestGrid();

	if (allfail)
	{	
		cout << "\nFAIL: TESTS HAVE FAILED" << endl;
	}
	else
	{
		cout << "\nSUCCES: ALL TESTS HAVE PASSED" << endl;
	}

	return allfail;
}

// Grid testing functions. Returns true if all tests are passed.
bool TestGrid()
{
	bool gridfail = false;
	bool fail;

	cout << "\n\n1) Testing CFOUR_Grid::Draw()" << endl;
	{
		CFOUR_Grid grid;
		fail = grid.TestDraw();

		if(fail)
		{
			cout <<"-> Test FAILED" << endl;
			gridfail = true;
		}
		else
			cout <<"-> Test passed" << endl;

	}

	cout << "\n\n2) Testing Grid::Win()" << endl;
	{
		CFOUR_Grid grid;
		fail = grid.TestWin();

		if(fail)
		{
			cout <<"-> Test FAILED" << endl;
			gridfail = true;
		}
		else
			cout <<"-> Test passed" << endl;
	}

	cout << "\n\n3) Testing Grid::HumanInsert" << endl;
	{
		CFOUR_Grid grid;
		fail = grid.TestHumanInsert();

		if(fail)
		{
			cout <<"-> Test FAILED" << endl;
			gridfail = true;
		}
		else
			cout <<"-> Test passed" << endl;
	}

	cout << "\n\n4) Testing Grid::ComputerInsert" << endl;
	{
		CFOUR_Grid grid;
		fail = grid.TestComputerInsert();

		if(fail)
		{
			cout <<"-> Test FAILED" << endl;
			gridfail = true;
		}
		else
			cout <<"-> Test passed" << endl;
	}

	return gridfail;
}