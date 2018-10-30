#include "BoardSpaces.h"

BoardSpace::BoardSpace(int player) {
	// Saves the starting tile for each player once their given pawns leaves the 'START' zone.
	// It also saves the location of the space right outside of their first 'SAEFTY' tile.
	switch (player) {
		case 1: // Player 1 (Red)
			StartSpace = 20;
			SafeZoneGate = StartSpace - 2;
			break;
		case 2: // Player 2 (Blue)
			StartSpace = 35;
			SafeZoneGate = StartSpace - 2;
			break;
		case 3: // Player 3 (Yellow)
			StartSpace = 48;
			SafeZoneGate = StartSpace - 2;
			break;
		case 4: // Player 4 (Green)
			StartSpace = 5;
			SafeZoneGate = StartSpace - 2;
			break;
	}
}