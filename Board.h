#pragma once
// Header for printing the board.
#include "Tokens.h"

namespace board
{
	void boardPrint(); // prints the full board

	void gridPrint(); // prints the grid that shows the number of each space

	void locPrint(TokenClass **, unsigned int rows, unsigned int cols); // prints the location of all pieces on the board
}