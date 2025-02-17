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

	/// Default and only constructor (empty)
	CFOUR_Grid();

	/// Destructor (empty)
	~CFOUR_Grid(){};

	void CheckSize(int i, int j);
	int GetVal(int i, int j);
	void SetVal(int i, int j, int val);

	void Print();

	void HumanInsert(int i);

	void ComputerInsert(int i);

	bool CheckColFull(int i);

	bool Win();

	bool Draw();

	int GetWidth() const
		{return wgrid;};

	int GetHeight() const
		{return hgrid;};

protected:
	// Width of the grid, fixed
	static const int wgrid = 7;

	// Height of the grid, fixed
	static const int hgrid = 6;


	/** Grid: origin is at bottom left. Use as:
	 *  grid(ix, iy)
	 */
	std::array<std::array<int, hgrid>, wgrid> grid = {0};

	/// Fil of grid
	std::array<int, wgrid> fill = {0};
};


#endif