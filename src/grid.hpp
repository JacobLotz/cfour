#ifndef CFOUR_GRID
#define CFOUR_GRID

// External
#include <vector>
#include <iostream>

using namespace std;

/**
 * Definition of the connect four frame
 */
class CFOUR_Grid
{
public:
	/** Constructor sets the width using @a width_ and height using
	 * @a height_, creates a two dimensional data object to store the
	 * data of the grid in in @a grid and creates a one dimensional
	 * data object to store the amount of fiches in a column in. */
	CFOUR_Grid(int wgrid_, int hgrid_) : wgrid(wgrid_), hgrid(hgrid_),
	grid(wgrid_, vector<int>(wgrid, 0)), fill(wgrid,0) {};

	/// Destructor (empty)
	~CFOUR_Grid(){};

	/// Prints an explanation of the game
	void PrintGameplay();

	/** Returns the value in the grid at the indices @a i (hor.)
	 * and @a j (vert.) in the grid */
	int GetVal(int i, int j);

	/** Sets the value in the grid at the indices @a i (hor.)
	 * and @a j (vert.) in the grid */
	void SetVal(int i, int j, int val);

	/** Prints the grid with 0 for empty locations,
	 * -1 for locations filled by the computer, 1
	 * for indices filled by the player.*/
	void Print();

	/// Inserts a fiche in column @a i by the player
	void HumanInsert(int i);

	/// Inserts a fiche in column @a i by the computer
	void ComputerInsert(int i);

	/** Checks whether there is space in a column for
	 * an additional fiche. Returns true if the column is
	 * full; false if the column still has space. */
	bool CheckColFull(int i);

	/** Checks whether the game is won or not. Returns
	 * true if the game is won; false if not.
	 * */
	bool Win();

    /** Checks whether the game is a draw or not. Returns
	 * true if the game is a draw; false if not.
	 * */
	bool Draw();

	/// Returns the width of the grid as an integer.
	int GetWidth() const
		{return wgrid;};

	/// Returns the height of the grid as an integer.
	int GetHeight() const
		{return hgrid;};

	/** Verifies wheter the indices @a i (hor.) and 
	 * @a j (vert.) fit in the grid */
	void CheckSize(int i, int j);

	/// Testing functions
	bool TestWin();
	bool TestDraw();
	bool TestHumanInsert();
	bool TestComputerInsert();

protected:
	/// Width of the grid.
	const int wgrid;

	// Height of the grid.
	const int hgrid;

	/** Grid: origin is at bottom left. Use as:
	 * grid(ix, iy) to read data */
	vector<vector<int>> grid;

	/// Fill of the colums of the grid for each column
	vector<int> fill;
};


#endif