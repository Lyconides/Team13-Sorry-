#pragma once
// The header for the card functions
#include "Tokens.h"
#include "BoardSpaces.h"

class cardFunc
{
public:
	cardFunc(); // constructor
	void cardDesc(const unsigned int); // returns the description for the card gotten.
	void cardGot(TokenClass** &, const int, const int, BoardSpace* &, const int, int, int); // gets what card the user has, and uses the appropriate function.

private:
	// void One(TokenClass

	// If a 'true' value is returned, the move was successful. If a 'false' value is returned, the move failed.
	bool One(TokenClass & p, BoardSpace & b); // the '1' card
	bool Two(TokenClass & p, BoardSpace & b); // the '2' card
	bool Three(TokenClass & p, BoardSpace & b); // the '3' card
	bool Four(TokenClass & p, BoardSpace & b); // the '4' card

	bool Five(TokenClass & p, BoardSpace & b); // the '5' card
	bool Seven(TokenClass & p, BoardSpace & b); // the '7' card - used when only one pawn is being moved
	bool Seven(TokenClass & p1, int m1, TokenClass & p2, int m2, BoardSpace & b); // the '7' card - used when the movements are being split across two pawns.
	bool Eight(TokenClass & p, BoardSpace & b); // the '8' card

	bool Ten(TokenClass & p, int m, BoardSpace & b); // the '10' card
	bool Eleven(TokenClass & p, BoardSpace & b); // the '11' card for standard movement
	bool Eleven(TokenClass & p1, TokenClass & p2); // the '11' card; used when the location of two pawns are being swapped
	bool Twelve(TokenClass & p, BoardSpace & b); // the '12' card

	bool Sorry(TokenClass & p1, TokenClass & p2, BoardSpace & b1, BoardSpace & b2); // the Sorry! card


};
