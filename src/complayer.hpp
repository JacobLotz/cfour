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

	/// Default and only constructor
	CFOUR_Complayer(CFOUR_Grid& grid_);


	/// Empty destructor
	~CFOUR_Complayer(){};

	void Play();

protected:
	CFOUR_Grid& grid;
	int wgrid;

};


#endif