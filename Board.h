#pragma once
// Header for printing the board.
#include "Tokens.h"

namespace board
{
	void boardPrint(); // prints the full board

	void gridPrint(); // prints the grid

	void locPrint(TokenClass **, unsigned int rows, unsigned int cols); // the location of all pieces
}