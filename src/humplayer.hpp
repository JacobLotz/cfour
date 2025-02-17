#ifndef CFOUR_HUMPLAYER
#define CFOUR_HUMPLAYER

// Internal
#include "grid.hpp"

/**
 * Definition of the connect four frame
 */
class CFOUR_Humplayer
{
public:

	/// Default and only empty constructor
	CFOUR_Humplayer(CFOUR_Grid& grid_):
		grid(grid_){};

	/// Empty destructor
	~CFOUR_Humplayer(){};

	void Play();

protected:
	CFOUR_Grid& grid;
};


#endif