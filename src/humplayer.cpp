// Internal
#include "humplayer.hpp"

// External
#include <iostream>
using namespace std;

void CFOUR_Humplayer::Play()
{
	cout << "\n___________________________\n" << endl;
	cout << "Where do you want to place your fiche? (0-6)" << endl;

	int i;
	bool noentry = true;

	while(noentry)
	{
		cin >> i;

		if (i>(grid.GetWidth()-1) || i<0)
		{
			cout << "Please select a value between 0-6" << endl;
		}
		else if (grid.CheckColFull(i))
		{
			cout << "Cannot be placed here, new entry please" << endl;
		}
		else
		{
			noentry = false;
		}
	}

	grid.HumanInsert(i);
}