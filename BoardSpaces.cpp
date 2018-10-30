// Saves the tile in front of 'START' and the in front of the player's safety spaces. Also saves what sliders the pawn is allowed to use.
#include "BoardSpaces.h"

BoardSpace::BoardSpace(int player) {
	// Saves the starting tile for each player once their given pawns leaves the 'START' zone.
	// It also saves the location of the space right outside of their first 'SAEFTY' tile.
	// And saves what sliders the player is allowed to use.

	// The player cannot use the slider of their colour, so the locations of the unusable slides are not saved as available options. The starting location of each slide and what colour it's for is listed below.
	// Red: 17, 25
	// Blue: 32, 40
	// Yellow: 47, 55
	// Green: 2, 10

	switch (player) {
		case 1: // Player 1 (Red)
			StartSpace = 20;
			SafeZoneGate = StartSpace - 2;

			// Can't use slides 17 or 25
			slides[0] = 32;
			slides[1] = 40;
			slides[2] = 47;
			slides[3] = 55;
			slides[4] = 2;
			slides[5] = 10;

			break;
		case 2: // Player 2 (Blue)
			StartSpace = 35;
			SafeZoneGate = StartSpace - 2;

			// Can't use slides 32 or 40
			slides[0] = 17;
			slides[1] = 25;
			slides[2] = 47;
			slides[3] = 55;
			slides[4] = 2;
			slides[5] = 10;

			break;
		case 3: // Player 3 (Yellow)
			StartSpace = 50;
			SafeZoneGate = StartSpace - 2;

			// Can't use slides 47 or 55
			slides[0] = 17;
			slides[1] = 25;
			slides[2] = 32;
			slides[3] = 40;
			slides[4] = 2;
			slides[5] = 10;

			break;
		case 4: // Player 4 (Green)
			StartSpace = 5;
			SafeZoneGate = StartSpace - 2;

			// Can't use slides 2 or 10
			slides[0] = 17;
			slides[1] = 25;
			slides[2] = 32;
			slides[3] = 40;
			slides[4] = 47;
			slides[5] = 55;

			break;
	}
}

int BoardSpace::onSlide(int loc) // checks to see if the player's pawn is on a slider by getting their current location. If the player is not on any of the slides, a -1 is returned.
{
	for (int i = 0; i < sizeof(slides) / sizeof(int); i++) // goes through each slides index to see if the player's pawn has the same location as any of them.
	{
		if (loc == slides[i])
		{
			return slides[i];
		}
	}

	return -1;
}