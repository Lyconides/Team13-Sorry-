#pragma once

// Saves how many pawns the player has at 'START', how many they have at home, the space just outside of the 'SAFE' zone, and what space the pawns start on once leaving 'START'.
// It also saves what sliders the player can use
struct BoardSpace {

public:
	int Start = 4; // how many pawns are left at 'START'
	int StartSpace; // the tile the pawn starts on once leaving 'START'
	int SafeZoneGate; // the space right outside of a pawn's 'SAFE' set of spaces
	int Home = 0; // the amount of pawns in the 'HOME' zone

	// saves what slides the player is allowed to use.

	BoardSpace(int); // constructor

	int onSlide(int); // takes the pawn's location and sees if it's on a usable slide. If it's not, -1 is returned.

private:
	// Sliders
	// Red: 17, 25
	// Blue: 32, 40
	// Yellow: 47, 55
	// Green: 2, 10
	
	// the pawn cannot use the slider of its own colour
	// Slides 17, 32, 47, and 2 move the player 3 spaces forward. 
	// Sliders 25, 40, 55, and 10 move the player 4 spaces forward.

	int slides[6]; // saves the locations of the sliders the player can use.
};

