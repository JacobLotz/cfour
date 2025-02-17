#ifndef CFOUR_COMPLAYER
#define CFOUR_COMPLAYER

// Internal
#include "grid.hpp"

/**
 * Definition of the connect four frame
 */
class CFOUR_Complayer
{
public:

	/** Default constructor. Sets the grid to make it
	 * playable by the computer. */
	CFOUR_Complayer(CFOUR_Grid& grid_);

	/// Empty destructor
	~CFOUR_Complayer(){};

	/** Determine the move by the computer using a
	 * randomizer and play the move. */
	void Play();

protected:
	// Reference to the grid in cfour.cpp
	CFOUR_Grid& grid;

	/// Easy acces of width of the grid (copy)
	int wgrid;
};

#endif
