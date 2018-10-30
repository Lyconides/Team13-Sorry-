#pragma once

// Saves how many pawns the player has at 'START', how many they have at home, the space just outside of the 'SAFE' zone, and what space the pawns start on once leaving 'START'.
struct BoardSpace {

public:
	int Start = 4; // how many pawns are left at 'START'
	int StartSpace; // the tile the pawn starts on once leaving 'START'
	int SafeZoneGate; // the space right outside of a pawn's 'SAFE' set of spaces
	int Home = 0; // the amount of pawns in the 'HOME' zone

	BoardSpace(int); // constructor
};

