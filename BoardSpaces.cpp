#include "BoardSpaces.h"

BoardSpace::BoardSpace(int player) {
	// Saves the starting tile for each player once their given pawns leaves the 'START' zone.
	// It also saves the location of the space right outside of their first 'SAEFTY' tile.
	// And saves what sliders the player is allowed to use.

	// The player cannot use the slider of their colour.
	// Red: 17, 25
	// Blue: 32, 40
	// Yellow: 47, 55
	// Green: 2, 10

	switch (player) {
		case 1: // Player 1 (Red)
			StartSpace = 20;
			SafeZoneGate = StartSpace - 2;

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

			slides[0] = 17;
			slides[1] = 25;
			slides[2] = 47;
			slides[3] = 55;
			slides[4] = 2;
			slides[5] = 10;

			break;
		case 3: // Player 3 (Yellow)
			StartSpace = 48;
			SafeZoneGate = StartSpace - 2;

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

			slides[0] = 17;
			slides[1] = 25;
			slides[2] = 32;
			slides[3] = 40;
			slides[4] = 47;
			slides[5] = 55;

			break;
	}
}

int BoardSpace::onSlide(int loc) // checks to see if the player's pawn is on a slider
{
	for (int i = 0; i < sizeof(slides) / sizeof(int); i++)
	{
		if (loc == slides[i])
		{
			return slides[i];
		}
	}

	return -1;
}