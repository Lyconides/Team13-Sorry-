#include "Tokens.h"
// The functions for Tokens.h

TokenClass::TokenClass() { // default constructor; this is just a placeholder until a proper TokenClass object with the player number can be created.
	setStart(true);
	setSafeZone(false);
	setHome(false);
	setLocation(0);
}

TokenClass::TokenClass(int p) {
	Player = p;
	setStart(true);
	setSafeZone(false);
	setHome(false);
	setLocation(0);
}

// Getters for each variable
bool TokenClass::getStart() {
	return Start;
}
bool TokenClass::getSafeZone() {
	return SafeZone;
}
bool TokenClass::getHome() {
	return Home;
}
int TokenClass::getLocation() {
	return Location;
}

int TokenClass::getPlayer() {
	return Player;
}

// Setters for each variable
void TokenClass::setStart(bool start) {
	Start = start;
}

void TokenClass::setSafeZone(bool safe) {
	SafeZone = safe;
}

void TokenClass::setHome(bool home) {
	Home = home;
}

void TokenClass::setLocation(int space) {
	Location = space;
}

void TokenClass::setPlayer(int p) {
	Player = p;
}

// Resetting the token back to its default values
void TokenClass::reset()
{
	setStart(true);
	setSafeZone(false);
	setHome(false);
	setLocation(0);
}