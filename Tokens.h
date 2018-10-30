#pragma once
#include "BoardSpaces.h"
//reference: https://www.geeksforgeeks.org/c-classes-and-objects/
class TokenClass {
public:
	// Variables
	int Player; // the number of the player the piece belongs to
	bool Start; // determines whether the pawn (token) is on its 'START' space or not.
	bool SafeZone; // determines whether the pawn (token) is in its safe zone
	bool Home; // determines whether the pawn is at its 'HOME' zone or not
	int Location; // the current location of the pawn

	// Constructors
	TokenClass();
	TokenClass(int p);

	// Getters
	bool getStart();
	bool getSafeZone();
	bool getHome();
	int getLocation();
	int getPlayer();

	// Setters
	void setStart(bool start);
	void setSafeZone(bool safe);
	void setHome(bool home);
	void setLocation(int space);
	void setPlayer(int p);

private:

};