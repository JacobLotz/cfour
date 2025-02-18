// Internal
#include "grid.hpp"

// External
#include <iostream>
#include <array>
#include <cmath>


using namespace std;

CFOUR_Grid::CFOUR_Grid(bool print)
{
	if(print)
	{
    	cout <<"    _____        _  _    "<< endl;
    	cout <<"   / ____|      | || |   "<< endl;
    	cout <<"  | |   ______  | || |_  "<< endl;
    	cout <<"  | |  |______| |__   _| "<< endl;
    	cout <<"  | |____          | |   "<< endl;
    	cout <<"   \\_____|         |_|   \n"<< endl;

		cout << "Hello, this is C-4 are you ready \n";
		cout << "for a blasting game????\n\n";

		cout << "You are playing connect four against\n";
		cout << "me. If it is your turn you can play\n";
		cout << "your piece by picking a column\n";
		cout << "between 0-6\n\n";

		cout << "The grid looks like this: \n";
	
		Print();

		cout << "Here \n";
		cout << " -1 indicates that this location is \n";
		cout << "    filled by a fiche of me; \n";
		cout << "  0 means it empty;\n";
		cout << "  1 means that one of your fiches\n";
		cout << "    fills this spot.\n\n";

		cout << "You can start!\n";
	}
};

int CFOUR_Grid::GetVal(int i, int j)
{
	CheckSize(i,j);
	return grid[i][j];
}

void CFOUR_Grid::SetVal(int i, int j, int val)
{
	CheckSize(i,j);
	grid[i][j] = val;
}

void CFOUR_Grid::Print()
{
	cout << "---------------------" << endl;

	// Print from top to bottom
	for (int j = hgrid-1; j >= 0; j--)
	{
		for (int i = 0; i < wgrid; i++)
		{
			// Print with leading spaces and space after
			printf("%*d ",2,GetVal(i,j));
		}
		cout << endl;
	}

	cout << "---------------------" << endl;
}

void CFOUR_Grid::HumanInsert(int i)
{
	SetVal(i, fill[i], 1);
	fill[i] += 1;
}

void CFOUR_Grid::ComputerInsert(int i)
{
	SetVal(i, fill[i], -1);
	fill[i] += 1;
}

bool CFOUR_Grid::CheckColFull(int i)
{
	bool avail = false;
	if (fill[i]>=hgrid)
	{
		avail = true;
	}

	return avail;
}

bool CFOUR_Grid::Win()
{
	bool win = false;
	bool sign;

	// Check horizontal win
	for (int j = 0; j < hgrid; j++)
		for (int i = 0; i < wgrid-3; i++)
		{
			int total = GetVal(i, j) + GetVal(i+1, j) 
				+ GetVal(i+2, j) + GetVal(i+3, j);

			sign = signbit(total);

			total = abs(total);

			if (total>3)
			{
				win = true;
				goto endwin;
			}
		}

	// Check vertical win
	for (int i = 0; i < wgrid; i++)
		for (int j = 0; j < hgrid-3; j++)
		{
			int total = GetVal(i, j) + GetVal(i, j+1) 
				+ GetVal(i, j+2) + GetVal(i, j+3);

			sign = signbit(total);

			total = abs(total);

			if (total>3)
			{
				win = true;
				goto endwin;
			}
		}

	// Check win with diagonal positive grad
	for (int i = 0; i < wgrid-3; i++)
		for (int j = 0; j < hgrid-3; j++)
		{
			int total = GetVal(i, j) + GetVal(i+1, j+1) 
				+ GetVal(i+2, j+2) + GetVal(i+3, j+3);

			sign = signbit(total);

			total = abs(total);

			if (total>3)
			{
				win = true;
				goto endwin;
			}
		}

	// Check win with diagonal negative grad
	for (int i = 3; i < wgrid; i++)
		for (int j = 0; j < hgrid-3; j++)
		{
			int total = GetVal(i, j) + GetVal(i-1, j+1) 
				+ GetVal(i-2, j+2) + GetVal(i-3, j+3);

			sign = signbit(total);

			total = abs(total);

			if (total>3)
			{
				win = true;
				goto endwin;
			}
		}

endwin:

	// Report result
	if(win)
	{
		cout << "\nGAME OVERRRRRR" << endl;

		if (sign)
		{
			cout << "I HAVE WON!" << endl;
		}
		else
		{
			cout << "YOU HAVE WON!" << endl;
		}

		return true;
	}

	return false;
}

bool CFOUR_Grid::Draw()
{
	// Check if there is a possible move in each column
	for (int i = 0; i < wgrid; i++)
		if (!CheckColFull(i))
		{
			return false;
		}

	cout << "\nGAME IS A DRAW" << endl;

	return true;
}

void CFOUR_Grid::CheckSize(int i, int j)
{
	if (i >= wgrid || j >= hgrid)
	{
		cout << "ERROR: grid index does not exist\n";
		exit(1);
	}
}

// Testing functions
bool CFOUR_Grid::TestWin()
{
	bool pass;

	// Horizontal test
	SetVal(0,0, 1);
	SetVal(1,0, 1);
	SetVal(2,0, 1);
	SetVal(3,0, 1);

	pass = Win();


	// Vertical test
	for(auto& row : grid)
  		for(auto& i : row)
  		{
  			i = 0;
  		}

  	SetVal(0,0, 1);
	SetVal(0,1, 1);
	SetVal(0,2, 1);
	SetVal(0,3, 1);

	pass = Win();


	// Diagonal positive grad test
	for(auto& row : grid)
  		for(auto& i : row)
  		{
  			i = 0;
  		}

	SetVal(0,0, -1);
	SetVal(1,1, -1);
	SetVal(2,2, -1);
	SetVal(3,3, -1);

	pass = Win();

	// Diagonal negative grad test
	for(auto& row : grid)
  		for(auto& i : row)
  		{
  			i = 0;
  		}


	SetVal(3,0, -1);
	SetVal(2,1, -1);
	SetVal(1,2, -1);
	SetVal(0,3, -1);

	pass = Win();
  	

	return pass;  
}

bool CFOUR_Grid::TestDraw()
{
	for(auto& i : fill)
	{
  		i = hgrid;
  	}

	return Draw();  
}

bool CFOUR_Grid::TestHumanInsert()
{
	for(auto& row : grid)
  		for(auto& i : row)
  		{
  			i = 0;
  		}

  	HumanInsert(1);

  	if (GetVal(1,0) == 1)
  		return true;
  	
  	else
  		return false;
}

bool CFOUR_Grid::TestComputerInsert()
{
	for(auto& row : grid)
  		for(auto& i : row)
  		{
  			i = 0;
  		}

  	ComputerInsert(5);

  	if (GetVal(5,0) == -1)
  		return true;
  	
  	else
  		return false;
}