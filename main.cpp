/*
Names: Angus Wai (100719558), Jason Lee (100698121), Jiminy Cao (100701335), Roderick “R.J.” Montague (100701758), Ulric Miller (100693403)
Date: 10/17/2018
References: Cplusplus.com - random_shuffle(http://www.cplusplus.com/reference/algorithm/random_shuffle/), Stackoverflow.com - "Is it possible to random shuffle an array of int elements" (https://stackoverflow.com/questions/14720134/is-it-possible-to-random-shuffle-an-array-of-int-elements)
		> Cplusplus.com - toupper(http://www.cplusplus.com/reference/cctype/toupper/)

*/

// GAME DEVELOPMENT WORKSHOP - PROJECT 2
// #include "Tokens.h"

#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>

const unsigned short int LEN(45);
static unsigned short int ary[LEN] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 7, 7, 7, 7, 8, 8, 8, 8, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13 }; // #13 is te sorry card

int cardGet();
void rules(int);
void game();

void rules(int m) // prints the rules for the game.
{
	switch (m)
	{
		case 1:
			std::cout << "\nRULES OF THE BOARDGAME SORRY!\n" << std::endl;

			std::cout << "\'Sorry!\' is a 2-4 player game where your job is to get all 4 of your colour of pawns from their starting zone to their home zone as fast as possible." << std::endl;
			break;
		case 2:
			std::cout << "\nRULES OF PROGRAM SORRY (FULL)!\n" << std::endl;
			break;
		case 3:
		default:
			std::cout << "\nRULES OF PROGRAM SORRY (SHORT)\n" << std::endl;

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

void game()
{

}

// int sorry()
int main()
{
	std::string input;
	unsigned short int pNum(0);

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


	do
	{
		std::cout << "Now that we have gotten the rules out of the way, I must ask you, how many people are playing? This game supports 2-4 players, so enter the amount of people playing:" << std::endl;
		std::cout << "Players: ";

		if (!(std::cin >> pNum)) // checks to see if a valid character was given
		{
			std::cout << "\nInvalid. Go Again.\n" << std::endl;
			
			// Removing the rest of the invalid input.
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			pNum = 0;
			continue;
		}
		if (pNum < 2 || pNum > 4) // if the player number is greater than or less than the range stated.
		{
			std::cout << "\nThis game only supports 2-4 players. Try again.\n" << std::endl;
			pNum = 0;
			continue;
		}

	} while (pNum == 0);

	system("pause");
	return 0;
}