/*
Names and Student Numbers: Angus Wai (100719558), Jason Lee (100698121), Jiminy Cao (100701335), Roderick “R.J.” Montague (100701758), Ulric Miller (100693403)
Date: 10/30/2018
References: Cplusplus.com - random_shuffle(http://www.cplusplus.com/reference/algorithm/random_shuffle/), Stackoverflow.com - "Is it possible to random shuffle an array of int elements" (https://stackoverflow.com/questions/14720134/is-it-possible-to-random-shuffle-an-array-of-int-elements)
		> Cplusplus.com - toupper(http://www.cplusplus.com/reference/cctype/toupper/), TutorialsPoint.com - Dynamic Memory (https://www.tutorialspoint.com/cplusplus/cpp_dynamic_memory.htm), GeeksforGeeks.org - Classes and Objects (https://www.geeksforgeeks.org/c-classes-and-objects/)

*/

// GAME DEVELOPMENT WORKSHOP - PROJECT 2
#include "Tokens.h"
#include "Board.h"
#include "BoardSpaces.h"
#include "CardFunctions .h"

#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>

// The array that stores the order the cards will be drawn in; there are 5 '1' cards, and '4' of every other card type. When all cards are used, the array is reshuffeled. Card '13' represents the 'Sorry!' card.
const unsigned short int LEN(45); // length of ary (there are 45 cards total)
static unsigned short int ary[LEN] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 7, 7, 7, 7, 8, 8, 8, 8, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13 };

// Function prototypes
int cardGet();
void rules(int);
std::string game(const short int);

void rules(int m) // prints the rules for the game.
{
	switch (m)
	{
		case 1: // prints the rules of the Sorry! board game
			std::cout << "\nRULES OF THE BOARDGAME SORRY!\n*************************************" << std::endl;
			std::cout << "Here is a general explanation of how the boardgame \'Sorry!\' works." << std::endl;

			std::cout << "\nGeneral\n-----------------" << std::endl;
			std::cout << "\'Sorry!\' is a 2-4 player game where your job is to get all 4 of your colour of pawns from their starting zone to their home zone as fast as possible. " << std::endl;
			std::cout << "Ideally, you want to get there before anyone else, but the game can continue until all but one of the players make it to the end. \n" << std::endl;

			std::cout << "In order to make your pawns move, you must utilize the card that you draw." << std::endl;
			std::cout << "There are 11 possible cards you can draw: cards numbered 1 - 12 (with 6 and 9 excluded), or a Sorry! card. There are 5 \'1\' cards and 4 of each other type, totaling to 45 cards." << std::endl;
			std::cout << "The numbered cards all denote how many spaces you can move, but some of the cards have additional uses that will be discussed later." << std::endl;
			std::cout << "Two pawns cannot share the same space, so if a move would put a pawn on the same tile as an enemy pawn, said enemy pawn would be taken back to their \"START\" space (will be explained later). \n" << std::endl;
			
			std::cout << "If a move would put two pawns of the same colour on the same tile, the move cannot be used. If there are no legal moves, the player's turn is skipped. " << std::endl;
			std::cout << "On the board there are generic tiles, along with \"SLIDE\" spaces, \"SAFETY\" spaces, a \"START\" zone, and a \"HOME\" zone. These will be explained below, along with the cards." << std::endl;
			
			std::cout << "\n------------------------------------------\nSpecial Tiles\n-----------------" << std::endl;
			std::cout << "START: the starting area for a pawn. Each pawn must begin in the \"START\" area that shares their same colour. To move out of the starting zone a 1, 2, or Sorry! card is need." << std::endl;
			std::cout << "HOME: the ending area for a pawn.A pawn's objective is to get to the home zone that corresponds with their colour." << std::endl;
			std::cout << "SAFETY : a tile that can only be used by a pawn that has the same colour as it.As the same suggests, pawns here are uneffected by certain card uses." << std::endl;
			std::cout << "SLIDE: if a pawn lands at the start of a slide that is not of their own colour, they are shifted to the end of it, sending all pawns they pass back to their starting areas." << std::endl;
			
			std::cout << "\n------------------------------------------\nCard Mechanics\n-----------------" << std::endl;
			std::cout << "1: move 1 space, or move 1 space off of the \"START\" tile" << std::endl;
			std::cout << "2: move 1 space, move 1 space off of the \"START\" tile. Also allows the player to draw another card, even if the '2' card could not be used." << std::endl;
			std::cout << "3: move 3 spaces forward" << std::endl;
			std::cout << "4: move 4 spaces backward" << std::endl;
			std::cout << "5: move 5 spaces forward" << std::endl;
			std::cout << std::endl;
			std::cout << "7: move 7 spaces forward, or split the 7 spaces across two pawns (7 spaces total must be moved). A '7' card cannot be used to move backwards and cannot be used to move a pawn move off of \"START\"." << std::endl;
			std::cout << "8: move 8 spaces forward" << std::endl;
			std::cout << "10: move 10 spaces forward, or move on space back. If no pawns can be moved 10 spaces forward, you must move a pawn 1 space back." << std::endl;
			std::cout << "11: move 11 spaces forward, or swap places with an opponent's pawn. You cannot switch a pawn that is in its designated \"START\", \"SAFETY\", or \"HOME\" zone." << std::endl;
			std::cout << "12: move 12 spaces forward" << std::endl;
			std::cout << std::endl;
			std::cout << "Sorry!: take a pawn from your \"START\" space and move it to a tile occupied by an opponent's pawn. This makes the opponent's pawn go back to start." << std::endl;
			std::cout << "\t-the player has no pawns in their \"START\" zone, or all of the opponent's pawns are in their \"START\", \"SAFETY\", or \"HOME\", all pawns stay where they are." << std::endl;

			std::cout << "_____________________________________________________________________________" << std::endl;
			break;

		case 2: // prints the rules of our text-based version of Sorry!
			std::cout << "\nMECHANICS OF THE PROGRAM\n*************************************\n" << std::endl;
			std::cout << "Here are the list of significant differences from the board game \'Sorry!\', and our text-based version." << std::endl;

			std::cout << "\t-Each player has a set colour. Player 1 is Red, Player 2 is Blue, Player 3 is Yellow, and Player 4 is Green." << std::endl;
			std::cout << "\t-The player that goes first is random, but it will always go in this order: Player 1 > Player 2 > Player 3 > Player 4." << std::endl;
			std::cout << "\t-The board will be printed to the screen and the locations of all pawns (tokens) will be shown in a list." << std::endl;
			std::cout << "\t-The cards will be randomly drawn at the start of each turn, and automatically reshuffled once all 45 cards have been used." << std::endl;
			std::cout << "\t-Once the card is drawn, the player will select the pawn and available movement options will be displayed." << std::endl;
			std::cout << "\t-The player's pawns can share the same tile." << std::endl;

			std::cout << "_____________________________________________________________________________" << std::endl;

			break;

		default:
			return;
	}

}

int cardGet() // returns the card the player has drawn.
{
	static unsigned short int index; // saves the number of cards drawn, and is used to provide the next card. It's static so that the value is saved even when the program is not using this function.

	if (index == 0 ^ index >= 45) // shuffles the array only at the start, or once all cards have been used.
	{
		std::random_shuffle(std::begin(::ary), std::end(::ary)); // shuffles array's values+ from beginning to end.
		index = 0;
	}

	index++; // adding to the number of cards drawn.
	return ::ary[index - 1]; // the index is increased by 1 before it's used to get the next card, so index - 1 is used for what needs to be returned.
}

std::string game(const short int pTotal) // the game loop.
{
	int plyr(rand() % pTotal + 1); // the current player
	const short int tknAmnt(4); // the amount of tokens each player has.

	short int card(0); // the current card
	std::string rank(""); // the place each player comes in. When a player wins, their number is added to the 'place' string.

	TokenClass ** tokens = new TokenClass *[pTotal]; // creating a 2D dynamic array to store the player variables. This is done by creating a 1D pointer array of pointers.
	BoardSpace * pLocs = new BoardSpace(pTotal); // a dynamic array that tracks how many of the player's pawns are at 'START', and how many are at 'HOME'.
	cardFunc move; // the object that's used to move pieces around.

	for (int i = 0; i < pTotal; i++)
	{
		tokens[i] = new TokenClass[tknAmnt]; // filling those indexes with a dynamic array of type TokenClass so that it can be a 2D array of pawns.
		pLocs[i] = BoardSpace(i + 1); // Giving every player an index in boardSpace
	}

	for (int i = 0; i < pTotal; i++) // putting a player token into each space. The first row is for P1, the second row is for P2, the third if for P3, and the forth is for Player 4.
		for (int j = 0; j < tknAmnt; j++)
		{
			tokens[i][j] = TokenClass(i + 1); // filling each space with a player number.
		}
	
	// The layout for the tokens array is as follows: { {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4} }
	while (rank.length() < pTotal) // main game loop
	{
		if (rank.find(std::to_string(plyr)) != std::string::npos) { // if the player's number is found in the rank variable, it means all of their pawns are at "HOME"
			std::cout << "\nPlayer " << plyr << "\'s pieces are all in the \'HOME\' zone.\n" << std::endl;
		}
		else
		{
			do // card question loop. A '2' allows the player to pull another card, which is what this loop checks.
			{
				board::boardPrint(); // printing the board.
				std::cout << std::endl;
				board::gridPrint();
				std::cout << std::endl;
				board::locPrint(tokens, pTotal, tknAmnt);

				std::cout << "It is Player " << plyr << "\'s Turn.\n" << std::endl;
				card = cardGet(); // getting the current player's card
				(card == 13) ? std::cout << "Player " << plyr << " got a \'Sorry!\' Card!" << std::endl : std::cout << "You got a \'" << card << "\' card!" << std::endl; // printing out the card the user got
				
				move.cardDesc(card); // prints the description of the card
				move.cardGot(tokens, pTotal, tknAmnt, pLocs, pTotal, plyr, card); // calling the card function to do the movements.

				// checking to see if that move got all of the player's pawns in the home zone.
				if (tokens[plyr - 1][0].getHome() == true && tokens[plyr - 1][1].getHome() == true && tokens[plyr - 1][2].getHome() == true && tokens[plyr - 1][3].getHome() == true)
				{
					rank += std::to_string(plyr); // adds the player number to the 'rank' string, which lists who won, and in what order.
				}

			} while (card == 2); // accounts for situations when the player pulls another card
		}

		if (plyr < pTotal) // changing the player number
		{
			plyr++;
		}
		else if(plyr >= pTotal) // going back to player 1 once all players have gone that given round
		{
			plyr = 1;
		}

		system("pause");
		system("CLS"); // clears the screen
	}

	std::cout << "\nThe game has ended, here are the results!\n" << std::endl;
	return rank; // returns the order the players finished in
}

int main()
{
	std::string input; // user input
	unsigned short int pTotal(0); // the total number of players
	std::string rank; // saves the order the player's finished in

	srand(time(0)); // seeding the randomizer to make it actually random.
	
	// Introduction
	std::cout << "Game Development Workshop - Project 2 - Sorry!\n--------------------------------------------------------------" << std::endl;
	std::cout << "Developer(s): (Team 13)" << std::endl;
	std::cout << "--------------------------------------------------------------\n" << std::endl;

	std::cout << "Welcome to Team 13's recreation of the board game \'Sorry!\'." << std::endl;
	do // Printing the rules of Sorry!
	{
		// Asking the user if they want the rules of the board game and/or the rules of the text-game printed.
		std::cout << "Instructions: Do you know the rules of Sorry!? Do you know the rules of the program? Enter the number that you correspond with. " << std::endl;
		std::cout << "(1) I know how both work." << std::endl;
		std::cout << "(2) I know how the board game Sorry! works, but not how this program works." << std::endl;
		std::cout << "(3) I know how the program works, but not how Sorry! works." << std::endl;
		std::cout << "(4) I don't know how either of them work." << std::endl;
		std::cout << "\nInput: ";
		getline(std::cin, input);

		if (input == "1") // no rules are printed
		{
			std::cout << "Alright. then we can get right into this." << std::endl;
		}
		else if (input == "2") // the rules of the program are printed
		{
			std::cout << "Printing how the program works." << std::endl;
			rules(2);
		}
		else if (input == "3") // the ruels of the board game Sorry! are printed
		{	
			std::cout << "Printing how the Sorry! works." << std::endl;
			rules(1);
		}
		else if (input == "4") // the rules of teh board game and the text-based version of it are printed
		{
			std::cout << "Printing the rules of Sorry!, and the rules of the program." << std::endl;
			rules(1);
			rules(2);
		}
		else // invalid input; the program asks the user again
		{
			std::cout << "I don't know what you're trying to say. Ask again.\n" << std::endl;
			input = "";
		}

	} while (input == "");

	std::cout << std::endl;

	do // Getting how many players are in this round (1 - 4).
	{
		std::cout << "Now that we have gotten the rules out of the way, I must ask you, how many people are playing? This game supports 2-4 players, so enter the amount of people playing:" << std::endl;
		std::cout << "Players: ";

		// Checks to see if the input was a valid number.
		if (!(std::cin >> pTotal)) // checks to see if a valid character was given
		{
			std::cout << "\nInvalid. Go Again.\n" << std::endl;
			
			// Removing the rest of the invalid input.
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			pTotal = 0;
			continue;
		}
		if (pTotal < 2 || pTotal > 4) // if the player number is greater than or less than the range stated.
		{
			std::cout << "\nThis game only supports 2-4 players. Try again.\n" << std::endl;
			pTotal = 0;
			continue;
		}

	} while (pTotal == 0); // loops until a valid number is given

	std::cout << "\nPlayers Set! Starting Game..." << std::endl;
	do // loop for doing multiple matches of the game,
	{
		rank = game(pTotal); // Game Loop

		std::cout << "\nEnding Standings\n---------------" << std::endl; // printing the ending standings
		for (int i = 0; i < rank.length(); i++)
		{
			std::cout << i + 1 << ") Player " << rank[i] << std::endl;
		}

		// Asking the user(s) if they want to play again.
		do
		{
			std::cout << "\nWould you all like to play again? Enter \'1\' for yes, or \'0\' for no." << std::endl;
			std::cout << "Decision: ";
			std::getline(std::cin, input);

			if (input == "1" || input == "y" || input == "Y" || input == "yes" || input == "YES" || input == "Yes") // they want to play again
			{
				std::cout << "A new game will be started." << std::endl;
				input = "";
			}
			else if (input == "0" || input == "n" || input == "N" || input == "no" || input == "NO" || input == "No") // they don't want to play again
			{
				std::cout << "Very well. The game will now end." << std::endl;
			}
			else // unusable input
			{
				std::cout << "Invalid Input. You all will be prompted again for a decision." << std::endl;
				input = "The Spanish Inquisition";
			}
		} while (input == "The Spanish Inquisition"); // there's no reason why this is the Spanish Inquisition, but there's also no reason why it can't be the Spnaish Inqusition.
		
	} while (input == "");
	

	std::cout << "\nThank you for playing our game." << std::endl;
	system("pause");
	return 0;
}