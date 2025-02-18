#ifndef CFOUR_GRID
#define CFOUR_GRID

// External
#include <array>
#include <iostream>

/**
 * Definition of the connect four frame
 */
class CFOUR_Grid
{
public:
	/** Default and only constructor. bool @a print
	 * allows for printing the start message (true) 
	 * or not (false) */
	CFOUR_Grid(bool print_);

	/// Destructor (empty)
	~CFOUR_Grid(){};

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
	// Width of the grid, fixed
	static const int wgrid = 7;

	// Height of the grid, fixed
	static const int hgrid = 6;


	/** Grid: origin is at bottom left. Use as:
	 * grid(ix, iy) */
	std::array<std::array<int, hgrid>, wgrid> grid = {0};

	/// Fill of the colums of the grid for each column
	std::array<int, wgrid> fill = {0};
};


#endif