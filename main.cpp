/*
Names: Angus Wai (100719558), Jason Lee (100698121), Jiminy Cao (100701335), Roderick “R.J.” Montague (100701758), Ulric Miller (100693403)
Date: 10/25/2018
References: Cplusplus.com - random_shuffle(http://www.cplusplus.com/reference/algorithm/random_shuffle/), Stackoverflow.com - "Is it possible to random shuffle an array of int elements" (https://stackoverflow.com/questions/14720134/is-it-possible-to-random-shuffle-an-array-of-int-elements)
		> Cplusplus.com - toupper(http://www.cplusplus.com/reference/cctype/toupper/), TutorialsPoint.com - Dynamic Memory (https://www.tutorialspoint.com/cplusplus/cpp_dynamic_memory.htm)

*/

// GAME DEVELOPMENT WORKSHOP - PROJECT 2
#include "Tokens.h"
#include "Board.h"

#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>

const unsigned short int LEN(45);
static unsigned short int ary[LEN] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 7, 7, 7, 7, 8, 8, 8, 8, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13 }; // #13 is te sorry card

int cardGet();
void rules(int);
std::string game(const short int);

void rules(int m) // prints the rules for the game.
{
	switch (m)
	{
		case 1:
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
		case 2:
			std::cout << "\nMECHANICS OF THE PROGRAM\n*************************************\n" << std::endl;
			std::cout << "Here are the list of significant differences from the board game \'Sorry!\', and our text-based version." << std::endl;

			std::cout << "\t-Each player has a set colour. Player 1 is Red, Player 2 is Blue, Player 3 is Yellow, and Player 4 is Green." << std::endl;
			std::cout << "\t-The player that goes first is random, but it will always go in this order: Player 1 > Player 2 > Player 3 > Player 4." << std::endl;
			std::cout << "\t-The board will be printed to the screen and the locations of all pawns (tokens) will be shown in a list." << std::endl;
			std::cout << "\t-The cards will be randomly drawn at the start of each turn, and automatically reshuffled once all 45 cards have been used." << std::endl;
			std::cout << "\t-Once the card is drawn, the player will select the pawn and available movement options will be displayed." << std::endl;

			std::cout << "_____________________________________________________________________________" << std::endl;

			break;
		default:
			return;
	}

}

int cardGet() // cardGet2 optimized
{
	static unsigned short int index;

	if (index == 0 ^ index >= 45) // shuffles the array only at the start, or once all values have been used
	{
		std::random_shuffle(std::begin(::ary), std::end(::ary)); // shuffles array from beginning to end.
		index = 0;
	}

	index++;

	return ::ary[index - 1]; // index is added to before being sent back, so index - 1 is used for what needs to be returned.
}

std::string game(const short int pTotal) // the game loop.
{
	int plyr(rand() % pTotal + 1); // the current player
	const short int tknAmnt(4); // the amount of tokens each player has.

	short int card(0); // the current card
	std::string rank(""); // the place each player comes in. When a player wins, their number is added to the 'place' string.
	
	// Making an object of player pieces
	TokenClass token = TokenClass(1);

	// int * test = new int[3];
	// test[3] = new int[3];

	// creating a 2D dynamic array to store the player variables
	TokenClass ** tokens = new TokenClass * [pTotal]; // creating a 1D pointer array of pointers
	for (int i = 0; i < pTotal; i++) // filling those secondary points with objects of type TokenClass
		tokens[i] = new TokenClass [tknAmnt];

	
	for (int i = 0; i < pTotal; i++)
		for (int j = 0; j < tknAmnt; j++)
			tokens[i][j] = TokenClass(i + 1); // filling each space with a player number.
	
	// The layout for the tokens array is as follows: { {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4} }

	while (rank.length() < pTotal) // main game loop
	{
		// rank = "1243";
		if (rank.find(std::to_string(plyr)) != std::string::npos) { // if the player's number is found in the rank variable, it means all of their pawns are at "HOME"
			std::cout << "\nPlayer " << plyr << "\'s pieces are all in the \'HOME\' zone.\n" << std::endl;
		}
		else
		{
			board::boardPrint(); // printing the board.
			// rank = "3421";

			do // card question loop. A '2' allows the player to pull another card, which is what this loop checks.
			{
				std::cout << "It is Player " << plyr << "\'s Turn.\n" << std::endl;
				card = cardGet(); // getting the current player's card
				(card == 13) ? std::cout << "You got a \'Sorry!\' Card!" << std::endl : std::cout << "You got a \'" << card << "\' card!" << std::endl; // printing out the card the user got

				// calling the card function to do the movements.

				// checking to see if that move got all of the player's pawns in the home zone.
				if (tokens[plyr - 1][0].getHome() == true && tokens[plyr - 1][1].getHome() == true && tokens[plyr - 1][2].getHome() == true && tokens[plyr - 1][3].getHome() == true)
				{
					rank += std::to_string(plyr); // adds the player number to the 'rank' string, which lists who won, and in what order.
				}

			} while (card == 2); // accounts for situations when the player pulls another card
		}
		
		system("pause");
		if (plyr < pTotal) // changing the player number
		{
			plyr++;
		}
		else if(plyr >= pTotal) // going back to player 1 once all players have gone that given round
		{
			plyr = 1;
		}
		
	}

	std::cout << "\nThe game has ended, here are the results!\n" << std::endl;
	return rank; // returns the order the players finished in
}

// int sorry()
int main()
{
	std::string input; // user input
	unsigned short int pTotal(0); // the total number of players
	std::string rank; // the place each person comes in.

	srand(time(0)); // seeding the randomizer.

	std::cout << "Game Development Workshop - Project 2 - Sorry!\n--------------------------------------------------------------" << std::endl;
	std::cout << "Developers (Team 13):\n*********************" << std::endl;
	std::cout << "Angus Wai\nJason Lee\nJiminy Cao\nRoderick \"R.J.\" Montague\nUlric Miller" << std::endl;
	std::cout << "--------------------------------------------------------------\n" << std::endl;

	std::cout << "Welcome to Team 13's recreation of the board game \'Sorry!\'." << std::endl;
	do // Printing the rules of Sorry!
	{
		std::cout << "Instructions: Do you the know the rules of Sorry!? Do you know the rules of the program? Enter the number that you correspond with. " << std::endl;
		std::cout << "(1) I know how both work." << std::endl;
		std::cout << "(2) I know how the board game Sorry! works, but not how this program works." << std::endl;
		std::cout << "(3) I know how the program works, but not how Sorry! works." << std::endl;
		std::cout << "(4) I don't know how either of them work." << std::endl;
		std::cout << "\nInput: ";
		getline(std::cin, input);

		if (input == "1")
		{
			std::cout << "Alright. then we can get right into this." << std::endl;
		}
		else if (input == "2")
		{
			std::cout << "Printing how the program works." << std::endl;
			rules(2);
		}
		else if (input == "3")
		{	
			std::cout << "Printing how the Sorry! works." << std::endl;
			rules(1);
		}
		else if (input == "4")
		{
			std::cout << "Printing the rules of Sorry!, and the rules of the program." << std::endl;
			rules(1);
			rules(2);
		}
		else
		{
			std::cout << "I don't know what you're trying to say. Ask again.\n" << std::endl;
			input = "";
		}

	} while (input == "");

	std::cout << std::endl;

	do // Setting the player number
	{
		std::cout << "Now that we have gotten the rules out of the way, I must ask you, how many people are playing? This game supports 2-4 players, so enter the amount of people playing:" << std::endl;
		std::cout << "Players: ";

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

	} while (pTotal == 0);

	std::cout << "\nPlayers Set! Starting Game..." << std::endl;

	do
	{
		rank = game(pTotal); // game Loop
		// rank = "4213";
		
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
				std::cout << "Very well. The game will now end." << std::endl;
				input = "";
			}
			else if (input == "0" || input == "n" || input == "N" || input == "no" || input == "NO" || input == "No") // the person doesn't want to play again
			{
				std::cout << "Very well. The game will now end." << std::endl;
			}
			else // unusable input
			{
				std::cout << "Invalid Input. You all will be prompted again for a decision." << std::endl;
				input = "Inquisition";
			}
		} while (input == "Inquisition");
		
	} while (input == "");
	

	std::cout << "\nThank you for playing our game." << std::endl;
	system("pause");
	return 0;
}