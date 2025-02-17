#ifndef CFOUR_HUMPLAYER
#define CFOUR_HUMPLAYER

// Internal
#include "grid.hpp"

/**
 * Definition of the connect four human player
 */
class CFOUR_Humplayer
{
public:

	/** Default and only empty constructor. Sets
	 * the grid to make it playable by the player. */
	CFOUR_Humplayer(CFOUR_Grid& grid_):
		grid(grid_){};

	/// Empty destructor
	~CFOUR_Humplayer(){};

	/** Asks the player to make a move and does it 
	* for the player.*/
	void Play();

protected:
	// Reference to the grid in cfour.cpp
	CFOUR_Grid& grid;
};

#endif
