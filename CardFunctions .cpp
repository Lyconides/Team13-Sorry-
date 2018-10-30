#include "CardFunctions .h"

#include <string>
#include <iostream>

cardFunc::cardFunc() // constructor
{

}

void cardFunc::cardDesc(const unsigned int card) // prints the description of the card based on the number provided.
{
	switch (card) // prints the description of the provided number.
	{
		case 1:
			std::cout << "1: move 1 space, or move 1 space off of the \"START\" tile" << std::endl;
			break;
		case 2:
			std::cout << "2: move 1 space, move 1 space off of the \"START\" tile. Also allows the player to draw another card, even if the '2' card could not be used." << std::endl;
			break;
		case 3:
			std::cout << "3: move 3 spaces forward" << std::endl;
			break;
		case 4:
			std::cout << "4: move 4 spaces backward" << std::endl;
			break;
		case 5:
			std::cout << "5: move 5 spaces forward" << std::endl;
			break;
		case 7:
			std::cout << "7: move 7 spaces forward, or split the 7 spaces across two pawns (7 spaces total must be moved). A '7' card cannot be used to move backwards and cannot be used to move a pawn move off of \"START\"." << std::endl;
			break;
		case 8:
			std::cout << "8: move 8 spaces forward" << std::endl;
			break;
		case 10:
			std::cout << "10: move 10 spaces forward, or move on space back. If no pawns can be moved 10 spaces forward, you must move a pawn 1 space back." << std::endl;
			break;
		case 11: // two functions
			std::cout << "11: move 11 spaces forward, or swap places with an opponent's pawn. You cannot switch a pawn that is in its designated \"START\", \"SAFETY\", or \"HOME\" zone." << std::endl;
			break;
		case 12:
			std::cout << "12: move 12 spaces forward" << std::endl;
			break;
		case 13: // the 'Sorry!' card
			std::cout << "Sorry!: take a pawn from your \"START\" space and move it to a tile occupied by an opponent's pawn. This makes the opponent's pawn go back to start." << std::endl;
			std::cout << "\t-the player has no pawns in their \"START\" zone, or all of the opponent's pawns are in their \"START\", \"SAFETY\", or \"HOME\", all pawns stay where they are." << std::endl;
			break;
		default:
			std::cout << "No card of that number exists." << std::endl;
			break;
	}
}

void cardFunc::cardGot(TokenClass** & tokens, const int tRows, const int tColumns, BoardSpace* & bps, const int bpsLen, int plyr, int card) //determines what function to call based on what card it recieves
{
	std::string input = ""; // user input
	unsigned short int pawn(1); // the number of the pawn the player is using
	unsigned short int pawn2(1); // the second pawn the player will use in the same turn (card 7 exclusive)
	unsigned short int share(0); // the amount of spaces the player wants the pawn they're sharing with to move (card 7 exclusive)
	unsigned short int opnt(0); // saves the opponent the current player selects (used for card 11).
	
	bool move = true; // checks to see if the pawn was actually moved. If it's false, then the pawn couldn't be moved, and what the user chose is invalid.
	int slide(-1); // saves the location of the player if they are on a usable slide.

	// Since a '1' or a '2' are needed to move a pawn off of 'START', this checks to see if the player can actually move anywhere.
	for (int i = 0; i < tColumns; i++)
	{
		if ((tokens[plyr - 1][i].getStart() == true && (card <= 2 || card == 13)) || (tokens[plyr - 1][i].getStart() == false && tokens[plyr - 1][i].getHome() == false)) // if the pawn is at 'START', the player can only move with a 1 of 2 card.
		{
			move = false;
			break;
		}
	}

	if (move == true) // if no moves can be made, then nothing happens and a message is printed.
	{
		std::cout << "No moves are available." << std::endl;
		return;
	}

MAINLOOP:
	while (move == false) // the main loop for getting user input.
	{
		std::cout << "Enter the number of the pawn you would wish to use: ";
		// std::getline(std::cin, input);

		if (!(std::cin >> pawn)) // checks to see if a number was given
		{
			std::cout << "\nThat input was not valid. Please make sure that you are only entering a pawn number.\n" << std::endl;
			// Removing the rest of the invalid input.
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue; // sends back to the start of the loop
		}
		// system("pause");
		if (pawn > 0 && pawn <= 4) // the pawn numbers should only be from 1 - 4, which is what this if statement checks.
		{
			if (tokens[plyr - 1][pawn - 1].getHome() == true) // if the pawn is at 'HOME', it cannot be moved.
			{
				std::cout << "\nThis pawn is in its \'HOME\' zone. It cannot be moved" << std::endl;
				continue;
			}

			// Sending the pawn to the appropriate function
			switch (card)
			{
				case 1:
					move = One(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;
				case 2:
					move = Two(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;
				case 3:
					move = Three(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;
				case 4:
					move = Four(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;
				case 5:
					move = Five(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;
			
				case 7: // has special cases
					do
					{
						std::cout << "\nThe '7' card allows you to split it across two pawns. Would you like to do that? Type \'1\' for yes, or \'0\' for no. To choose a different pawn, enter \'-1\'." << std::endl;
						std::cout << "Choice: ";
						getline(std::cin, input);

						if (input == "1" || input == "yes" || input == "YES" || input == "y" || input == "Y" || input == "Yes") // the value of '7' will be shared.
						{
							std::cout << "\nOkay. What pawn would you like to choose?";
							std::cout << "Pawn: ";
							getline(std::cin, input);

							if (input == "1" || input == "2" || input == "3" || input == "4") // if the input is valid.
							{
								if (std::stoi(input) == pawn) // if the pawn selects the pawn they already have for move sharing.
								{
									std::cout << "\nYou can't share your pawn's moves with itself. I will ask you about sharing with another pawn again." << std::endl;
									input = "";
									continue;
								}
								
								pawn2 = std::stoi(input); // getting the pawn number
								if (tokens[plyr - 1][pawn2 - 1].getStart() == true || tokens[plyr - 1][pawn2 - 1].getHome() == true) // a 7 card cannot be used to move a pawn from 'START', and a pawn at 'HOME' can't move.
								{
									std::cout << "\nYou can't use the '7' card to move a pawn off of \'START\', or move it from \'HOME\'. Try again" << std::endl;
									input = "";
									continue;
								}

								std::cout << "\nHow many spaces would you like pawn " << pawn << " to be moved? Keep in mind that the total number of spaces moved cannot exceed the number 7." << std::endl;
								std::cout << "Spaces: ";
								getline(std::cin, input);

								if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7") // if the number of moves selected was valid
								{
									share = 7 - std::stoi(input); // the amount of spaces being shared with the other pawn.

									if (tokens[plyr - 1][pawn - 1].getLocation() + 7 - share > 65 || tokens[plyr - 1][pawn2 - 1].getLocation() + share > 65 || 7 - std::stoi(input) < 0) // the amount of moves used must total to 7, even when one pawn is moved into 'START'.
									{
										std::cout << "\nThe amount of moves used must total to \'7\'. If you want to move a pawn to \'HOME\', the remaining amount of moves must be used up by the other pawn." << std::endl;
									}
									else
									{
										// Moves both pawns.
										std::cout << "Okay, so pawn " << pawn << " will move " << (7 - share) << " tiles, and pawn " << pawn2 << " will move " << share << "spaces." << std::endl;
										Seven(tokens[plyr - 1][pawn - 1], 7 - share, tokens[plyr - 1][pawn2 - 1], share, bps[plyr - 1]);
									}	
								}

								else // the amount of spaces attempted would exceed a total of 7.
								{
									std::cout << "\nThe number of spaces shared between the two pawns must total up to 7. Try again." << std::endl;
									input = "";
									continue;
								}

							}
							else if (input == "-1")
							{
								std::cout << "\nOkay. I'll will ask you to select a new pawn." << std::endl;
								goto MAINLOOP;
							}
							else // if the input is not valid.
							{
								std::cout << "\nI can't tell what you're trying to do. Can you try again?" << std::endl;

							}
						}
						else if (input == "0" || input == "no" || input == "NO" || input == "n" || input == "N" || input == "No") // the value of '7' will not be shared.
						{
							move = Seven(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
						}
						else
						{
							std::cout << "\nThat is not an option. Try again.\n" << std::endl;
							input = "";
						}

					} while (input == "");
					break;
				case 8:
					move = Eight(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;

				case 10: // has special cases
					do
					{
						std::cout << "\nWould you like to move \'10\' spaces forward, or \'1\' space back? Enter \'10\' for 10 spaces forward, and \'1\' for 1 space backwards." << std::endl;
						std::cout << "Decision: ";
						getline(std::cin, input);

						if (input == "10" || input == "ten" || input == "TEN") // moving the pawn 10 spaces forward.
						{
							std::cout << "\nOkay. Moving 10 spaces forward!" << std::endl;
							move = Ten(tokens[plyr - 1][pawn - 1], 10, bps[plyr - 1]);
						}
						else if (input == "1" || input == "-1" || input == "One" || input == "one") // moving the pawn 1 space back.
						{
							std::cout << "\nOkay. Moving 1 space backwards!" << std::endl;
							move = Ten(tokens[plyr - 1][pawn - 1], -1, bps[plyr - 1]);
						}
						else
						{
							std::cout << "\nThat input was unacceptable. Try again." << std::endl;
							input = "";
							continue;
						}
					} while (input == "");
					break;

				case 11: // has special cases
					do
					{
						std::cout << "\nYou have three options: move 11 spaces forward (if possible), swap with an opponent's pawn (if possible), or forfeit the turn." << std::endl;
						std::cout << "Enter \'1\' to move 11 spaces, enter \'2\' to swap places with an enemy pawn, or enter \'3\' to forfeit the turn." << std::endl;
						std::cout << "Choice: ";
						getline(std::cin, input);

						if (input == "1" || input == "11") // moving 11 spaces forward.
						{
							std::cout << "\nMoving 11 spaces forward!" << std::endl;
							move = Eleven(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
						}
						else if (input == "2" || input == "swap")
						{
							std::cout << "\nWhich player has the pawn you would like to switch places with?" << std::endl;
							std::cout << "Player: ";
							getline(std::cin, input);

							if (input == "1" || input == "2" || input == "3" || input == "4")
							{
								opnt = std::stoi(input); // getting the number of the opponent
								if (opnt == plyr) // if the player selects themselves 
								{
									std::cout << "\nYou cannot swap places with one of your own pieces. Try again." << std::endl;
									input = "";
									continue;
								}
								else if (opnt > tRows) // if the player selects an inactive player.
								{
									std::cout << "\nThat is not an available player choice. Go again." << std::endl;
									input = "";
									continue;
								}

								// Getting which piece the player would like to swap with.
								std::cout << "Type in the number of the piece you would like to switch places with. Remember that you can't switch places with a piece in its 'START', 'SAFETY' or 'HOME' zones." << std::endl;
								std::cout << "Piece: ";
								getline(std::cin, input);

								if (input == "1" || input == "2" || input == "3" || input == "4")
								{
									pawn2 = std::stoi(input); // getting the value of 'input' as an integer to store in pawn2.
									if (tokens[opnt - 1][pawn2 - 1].getStart() == true || tokens[opnt - 1][pawn2 - 1].getSafeZone() == true || tokens[opnt - 1][pawn2 - 1].getHome() == true) // the pawn can't be swapped with if it's in its 'START', 'SAFETY', or 'HOME' zone.
									{
										std::cout << "\nThat pawn cannot be swapped with. You will have to do something else." << std::endl;
										input = "";
										continue;
									}
									else
									{
										std::cout << "Okay, the posiions of Player " << plyr << "'s pawn " << pawn << " and Player " << opnt << "'s pawn will be swapped." << std::endl;
										move = Eleven(tokens[plyr - 1][pawn - 1], tokens[opnt - 1][pawn2 - 1]);
									}

								}
								else
								{
									std::cout << "That input was not valid. Please, please, please, please, please, please, please, please use valid inputs only." << std::endl;
									input = "";
									continue;
								}
							}
							else
							{
								std::cout << "\nI can't use that response. Please follow the rules." << std::endl;
							}
						}
						else if (input == "3" || input == "forfeit" || input == "skip") // skipping the player's turn.
						{
							std::cout << "\nAlright. Your turn for this round is being skipped." << std::endl;
							move = true;
						}
						else
						{
							std::cout << "\nThat answer doesn't make sense. Try again please." << std::endl;
							input = "";
							continue;
						}

					} while (input == "");
					break;

				case 12:
					move = Twelve(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;

				case 13: // the 'Sorry!' case
					// move = Sorry(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					move = true;
					for (int i = 0; i < tColumns; i++) // checks to see if the player has any pawns in start to move.
					{
						if (tokens[plyr - 1][i].getStart() == true)
						{
							move = false;
							break;
						}
					}

					if (move == true) // mo pawns can be moed
					{
						std::cout << "\nYou have no pawns at \'START\', which means that you have no options. Turn forfeitted." << std::endl;
					}
					else
					{
						move = true;
						// Goes through each token to make sure there are tokens available to swap with.
						for (int i = 0; i < tRows; i++)
						{
							for (int j = 0; j < tColumns && i != plyr - 1; j++) {
								if (tokens[i][j].getStart() == false && tokens[i][j].getSafeZone() == false && tokens[i][j].getHome() == false) // if all tiles are false, there's at least one pawn that can be swapped with.
								{
									move = false;
									break;
								}
							}
						}
						
						if (move == true) // no opponents can be swapped with.
						{
							std::cout << "\nYour opponent(s) have no pawns that you can swap with, so your turn is forfeit." << std::endl;
						}
						else
						{
							do // has the player select which pawn they want to change places with.
							{
								std::cout << "\nWhich of your pawns would you want to take from 'START?' Type in its number." << std::endl;
								std::cout << "Your Pawn:" << std::endl;
								getline(std::cin, input);

								if (input == "1" || input == "2" || input == "3" || input == "4")
								{
									pawn = std::stoi(input); // getting the input as an integer.
									if (tokens[plyr - 1][pawn - 1].getStart() == true) // if the pawn is at its start space, then it is usuable.
									{
										std::cout << "\nWhat opponent has the piece that you would like to send back to 'START?'" << std::endl;
										getline(std::cin, input);

										if (input == "1" || input == "2" || input == "3" || input == "4")
										{
											opnt = std::stoi(input); // getting the number of the opponent
											if (opnt == plyr) // if the player selects themselves 
											{
												std::cout << "Y\nou cannot sned one of your own pawns back to start. Try again." << std::endl;
												input = "";
												continue;
											}
											else if (opnt > tRows) // if the player selects an inactive player.
											{
												std::cout << "\That player is not available. Go again." << std::endl;
												input = "";
												continue;
											}

											// Getting which piece the player would like to swap with.
											std::cout << "Type in the number of the piece you would like to send back to its starting tile. Remember that you can't move a piece that's in its 'START', 'SAFETY' or 'HOME' zones." << std::endl;
											std::cout << "Piece: ";
											getline(std::cin, input);

											if (input == "1" || input == "2" || input == "3" || input == "4")
											{
												pawn2 = std::stoi(input); // getting the value of 'input' as an integer to store in pawn2.
												if (tokens[opnt - 1][pawn2 - 1].getStart() == true || tokens[opnt - 1][pawn2 - 1].getSafeZone() == true || tokens[opnt - 1][pawn2 - 1].getHome() == true) // the pawn can't be swapped with if it's in its 'START', 'SAFETY', or 'HOME' zone.
												{
													std::cout << "\nThat pawn cannot be sent back to its 'START' space. Go again." << std::endl;
													input = "";
													continue;
												}
												else // doing the Sorry! calculation
												{
													std::cout << "Okay, player " << plyr << "'s number " << pawn << " pawn (token) will be moved to the space of player " << opnt << "'s pawn." << std::endl;
													std::cout << "Player " << opnt << "'s pawn will be sent back to its \'START\' space" << std::endl;
													move = Sorry(tokens[plyr - 1][pawn - 1], tokens[opnt - 1][pawn2 - 1], bps[plyr - 1], bps[opnt - 1]); // calling the Sorry! function
												}

											}
											else
											{
												std::cout << "I don't know what this is, but I know I can't use it. Try again." << std::endl;
												input = "";
												continue;
											}

										}
										else
										{
											std::cout << "That... is not allowed. Disobedience will not be tolerated. Go again." << std::endl;
											input = "";
											continue;
										}
									}
									else
									{
										std::cout << "\nThat pawn cannot be used. Try again." << std::endl;
										input = "";
										continue;
									}
								}
								else
								{
									std::cout << "\nI can't use that. Try again." << std::endl;
									input = "";
									continue;
								}

							} while (input == "");
						}

					}
					break;
			}

			if (move == true)
			{
				std::cout << "\nAction successful!" << std::endl;
			}
			else if (move == false) // if move is equal to false, then something went wrong
			{
				std::cout << "\nThat action is illegal. Try again." << std::endl;
				continue;
			}
		}
		else
		{
			std::cout << "\nThat is not a valid pawn number. Please provide another answer.\n" << std::endl;
			continue;
		}

		
	}

	slide = bps->onSlide(tokens[plyr - 1][pawn - 1].getLocation()); // gets whether the player is on a usuable slide or not. If not, a -1 is reutrned.

	switch (slide)
	{
		// Slides 2, 17, 32, 47, and move the player 3 spaces forward.
		case 2:
		case 17:
		case 32:
		case 47:
			std::cout << "\nYou landed on a slider! Your pawn got moved over '3' spaces forward!\n" << std::endl;
			tokens[plyr - 1][pawn - 1].setLocation(tokens[plyr - 1][pawn - 1].getLocation() + 3);
			break;

		// Sliders 25, 40, 55, and 10 move the player 4 spaces forward.
		case 10:
		case 25:
		case 40:
		case 55:
			std::cout << "\nYou landed on a slider! Your pawn got moved '4' spaces!\n" << std::endl;
			tokens[plyr - 1][pawn - 1].setLocation(tokens[plyr - 1][pawn - 1].getLocation() + 4);
			break;
	
	}

	// Checking to see if the location of the player's pawn is the same as that of an enemy pawn. If so, the enemy pawn is sent back to start.
	for (int i = 0; i < tRows; i++)
	{
		for (int j = 0; j < tColumns && i != plyr - 1; j++)
		{
			if (tokens[plyr - 1][pawn - 1].getLocation() == tokens[i][j].getLocation()) // if the locations are equal, the opponent's token is sent back to start.
			{
				if (tokens[i][j].getStart() == false && tokens[i][j].getSafeZone() == false && tokens[i][j].getHome() == false) // Internally, 'Start' and 'Home' are considered zero, so to avoid a false positive these special tiles need to be checked.
				{
					std::cout << "Player " << plyr << "'s number " << pawn << " pawn landed on the same space as Player " << i + 1 << "'s number " << j + 1 << " pawn!" << std::endl;
					std::cout << "Player " << i + 1 << "'s pawn has been sent back to it's 'START' space!" << std::endl;

					tokens[i][j].setLocation(bps[i].StartSpace); // setting the opponent's token to their start space.
				}
			}
		}
	}
	
}


bool cardFunc::One(TokenClass & p, BoardSpace & b) {					//Card "One"
	if (p.getStart() == true)
	{									//Checks if the pawn the player chose is in start or on the board
		p.setStart(false);								//If in start, set start check to false,
		p.setLocation(b.StartSpace);					//move pawn to start space,
		b.Start -= 1;									//and decrement number of pawns in start
	}
	else {												//Move Pawn if not in start
		if ((p.getLocation() + 1) > 65) {					//If pawn has enough movement to move into home,
			p.setLocation(0);							//moves pawn off board
			p.setSafeZone(false);
			p.setHome(true);							//sets pawn in home
			b.Home += 1;
		}
		else if (p.getLocation() == (b.SafeZoneGate)) {	//Ensures pawn moves into safety zone instead of looping back to starting space
			p.setLocation(61);
			p.setSafeZone(true);
		}
		else if (p.getLocation() == 60) {					//Fixes movement to loop through all 60 spaces on the board
			p.setLocation(1);
		}
		else {
			p.setLocation(p.getLocation() + 1);
		}
	}

	return true;
}

bool cardFunc::Two(TokenClass & p, BoardSpace & b) {
	if (p.getStart() == true)
	{
		p.setStart(false);

		p.setLocation(b.StartSpace);
		b.Start -= 1;
	}
	else {
		if ((p.getLocation() + 2) > 65) {
			p.setLocation(0);
			p.setSafeZone(false);
			p.setHome(true);
			b.Home += 1;
		}
		else if (((p.getLocation() + 2) > (b.SafeZoneGate)) && p.getLocation() < b.SafeZoneGate) {
			p.setLocation(60 + (2 - (b.SafeZoneGate - p.getLocation())));
			p.setSafeZone(true);
		}
		else if ((p.getLocation() + 2) > 60 && !(p.getSafeZone())) {
			p.setLocation(2 - (60 - p.getLocation()));
		}
		else {
			p.setLocation(p.getLocation() + 2);
		}
	}
	return true;
}

bool cardFunc::Three(TokenClass & p, BoardSpace & b) { // Card 3
	if (p.getStart() == true || p.getHome() == true) // the pawn can't move if it's at 'HOME' or 'START'
	{
		return false;
	}
	else if ((p.getLocation() + 3) > 65) {
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation() + 3) > (b.SafeZoneGate) && p.getLocation() < b.SafeZoneGate) {
		p.setLocation(60 + (3 - (b.SafeZoneGate - p.getLocation())));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 3) > 60 && !(p.getSafeZone())) {
		p.setLocation(3 - (60 - p.getLocation()));
	}
	else {
		p.setLocation(p.getLocation() + 3);
	}

	return true;
}

bool cardFunc::Four(TokenClass & p, BoardSpace & b) { //Card "Four"
	if (p.getStart() == true || p.getHome() == true) // the pawn can't move if it's at 'HOME' or 'START'
	{
		return false;
	}
	else if ((p.getLocation() - 4) < 61 && p.getSafeZone())
	{
		p.setLocation((b.SafeZoneGate) - (4 - (p.getLocation() - 60)));
		p.setSafeZone(false);
	}
	else if ((p.getLocation() - 4) < 1) {
		p.setLocation(60 - (4 - p.getLocation()));
	}
	else {
		p.setLocation(p.getLocation() - 4);
	}

	return true;
}

bool cardFunc::Five(TokenClass & p, BoardSpace & b) {
	if (p.getStart() == true || p.getHome() == true) // the pawn can't move if it's at 'HOME' or 'START'.
	{
		return false;
	}
	else if ((p.getLocation() + 5) > 65)
	{
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation() + 5) > 60 && !(p.getSafeZone()) && (5 - (60 - p.getLocation())) > b.SafeZoneGate) {
		p.setLocation(5 - (b.SafeZoneGate - p.getLocation()));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 5) > (b.SafeZoneGate) && p.getLocation() < b.SafeZoneGate) {
		p.setLocation(60 + (5 - (b.SafeZoneGate - p.getLocation())));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 5) > 60 && !(p.getSafeZone())) {
		p.setLocation(5 - (60 - p.getLocation()));
	}
	else {
		p.setLocation(p.getLocation() + 5);
	}
	
	return true;
}

bool cardFunc::Seven(TokenClass & p, BoardSpace & b) {
	if (p.getStart() == true || p.getHome() == true) // the pawn can't move if it's at 'HOME' or 'START'.
	{
		return false;
	}
	else if ((p.getLocation() + 7 > 65 && p.getSafeZone()) || (p.getLocation() + 7 > b.SafeZoneGate + 5 && p.getLocation() <= b.SafeZoneGate)) {
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation() + 7) > 60 && !(p.getSafeZone()) && (7 - (60 - p.getLocation())) > b.SafeZoneGate) {
		p.setLocation(7 - (b.SafeZoneGate - p.getLocation()));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 7) > (b.SafeZoneGate) && p.getLocation() < b.SafeZoneGate) {
		p.setLocation(60 + (7 - (b.SafeZoneGate - p.getLocation())));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 7) > 60 && !(p.getSafeZone())) {
		p.setLocation(7 - (60 - p.getLocation()));
	}
	else {
		p.setLocation(p.getLocation() + 7);
	}

	return true;
}

bool cardFunc::Seven(TokenClass & p1, int m1, TokenClass & p2, int m2, BoardSpace & b) {
	if (p1.getStart() == true || p1.getHome() == true || p2.getStart() == true || p2.getHome() == true) // neither pawn can move if at their 'HOME' or 'START' space, which means that a movement is not allowed.
	{
		return false;
	}
	
	//First Pawn
	if ((p1.getLocation() + m1 > 65 && p1.getSafeZone())
		|| (p1.getLocation() + m1 > b.SafeZoneGate + 5 && p1.getLocation() <= b.SafeZoneGate)) {
		p1.setLocation(0);
		p1.setSafeZone(false);
		p1.setHome(true);
		b.Home += 1;
	}
	else if ((p1.getLocation() + m1) > 60 && !(p1.getSafeZone()) && (m1 - (60 - p1.getLocation())) > b.SafeZoneGate) {
		p1.setLocation(m1 - (b.SafeZoneGate - p1.getLocation()));
		p1.setSafeZone(true);
	}
	else if ((p1.getLocation() + m1) > (b.SafeZoneGate) && p1.getLocation() < b.SafeZoneGate) {
		p1.setLocation(60 + (m1 - (b.SafeZoneGate - p1.getLocation())));
		p1.setSafeZone(true);
	}
	else if ((p1.getLocation() + m1) > 60 && !(p1.getSafeZone())) {
		p1.setLocation(m1 - (60 - p1.getLocation()));
	}
	else {
		p1.setLocation(p1.getLocation() + m1);
	}
	//Second Pawn
	if ((p2.getLocation() + m2 > 65 && p2.getSafeZone())
		|| (p2.getLocation() + m2 > b.SafeZoneGate + 5 && p2.getLocation() <= b.SafeZoneGate)) {
		p2.setLocation(0);
		p2.setSafeZone(false);
		p2.setHome(true);
		b.Home += 1;
	}
	else if ((p2.getLocation() + m2) > 60 && !(p2.getSafeZone()) && (m2 - (60 - p2.getLocation())) > b.SafeZoneGate) {
		p2.setLocation(m2 - (b.SafeZoneGate - p2.getLocation()));
		p2.setSafeZone(true);
	}
	else if ((p2.getLocation() + m2) > (b.SafeZoneGate) && p2.getLocation() < b.SafeZoneGate) {
		p2.setLocation(60 + (m2 - (b.SafeZoneGate - p2.getLocation())));
		p2.setSafeZone(true);
	}
	else if ((p2.getLocation() + m2) > 60 && !(p2.getSafeZone())) {
		p2.setLocation(m2 - (60 - p2.getLocation()));
	}
	else {
		p2.setLocation(p2.getLocation() + m2);
	}

	return true;
}

bool cardFunc::Eight(TokenClass & p, BoardSpace & b) {
	if (p.getStart() == true || p.getHome() == true) // the pawn can't move if it's at 'HOME' or 'START'
	{
		return false;
	}

	if ((p.getLocation() + 8 > 65 && p.getSafeZone())
		|| (p.getLocation() + 8 > b.SafeZoneGate + 5 && p.getLocation() <= b.SafeZoneGate)) {
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation() + 8) > 60 && !(p.getSafeZone()) && (8 - (60 - p.getLocation())) > b.SafeZoneGate) {
		p.setLocation(8 - (b.SafeZoneGate - p.getLocation()));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 8) > (b.SafeZoneGate) && p.getLocation() < b.SafeZoneGate) {
		p.setLocation(60 + (8 - (b.SafeZoneGate - p.getLocation())));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 8) > 60 && !(p.getSafeZone())) {
		p.setLocation(8 - (60 - p.getLocation()));
	}
	else {
		p.setLocation(p.getLocation() + 8);
	}
	return true;
}

bool cardFunc::Ten(TokenClass & p, int m, BoardSpace & b) {
	if (p.getStart() == true || p.getHome() == true) // the pawn can't move if it's at 'HOME' or 'START'
	{
		return false;
	}

	if (m == 10) {
		if (((p.getLocation() + 10) > b.SafeZoneGate + 5 && p.getLocation() < b.StartSpace)
			|| ((p.getLocation() + 10) > 60 && !(p.getSafeZone()) && 10 - (60 - p.getLocation()) > b.SafeZoneGate + 5)
			|| (p.getLocation() + 10 > 65 && p.getSafeZone())) {
			p.setLocation(0);
			p.setSafeZone(false);
			p.setHome(true);
			b.Home += 1;
		}
		else if ((p.getLocation() + 10) > 60 && !(p.getSafeZone()) && (10 - (60 - p.getLocation())) > b.SafeZoneGate) {
			p.setLocation(10 - (b.SafeZoneGate - p.getLocation()));
			p.setSafeZone(true);
		}
		else if ((p.getLocation() + 10) > (b.SafeZoneGate) && p.getLocation() < b.SafeZoneGate) {
			p.setLocation(60 + (10 - (b.SafeZoneGate - p.getLocation())));
			p.setSafeZone(true);
		}
		else if ((p.getLocation() + 10) > 60 && !(p.getSafeZone())) {
			p.setLocation(10 - (60 - p.getLocation()));
		}
		else {
			p.setLocation(p.getLocation() + 10);
		}
	}
	else if (m == -1) {
		if (p.getLocation() == 61) {
			p.setLocation(b.SafeZoneGate);
			p.setSafeZone(false);
		}
		else if (p.getLocation() == 1) {
			p.setLocation(60);
		}
		else {
			p.setLocation(p.getLocation() - 1);
		}
	}
	return true;
}

bool cardFunc::Eleven(TokenClass & p, BoardSpace & b) {
	if (p.getStart() == true || p.getHome() == true) // the pawn can't move if it's at 'HOME' or 'START'
	{
		return false;
	}

	if (((p.getLocation() + 11) > b.SafeZoneGate + 5 && p.getLocation() < b.StartSpace)
		|| ((p.getLocation() + 11) > 60 && !(p.getSafeZone()) && 11 - (60 - p.getLocation()) > b.SafeZoneGate + 5)
		|| (p.getLocation() + 11 > 65 && p.getSafeZone())) {
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation() + 11) > 60 && !(p.getSafeZone()) && (11 - (60 - p.getLocation())) > b.SafeZoneGate) {
		p.setLocation(11 - (b.SafeZoneGate - p.getLocation()));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 11) > (b.SafeZoneGate) && p.getLocation() < b.SafeZoneGate) {
		p.setLocation(60 + (11 - (b.SafeZoneGate - p.getLocation())));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 11) > 60 && !(p.getSafeZone())) {
		p.setLocation(11 - (60 - p.getLocation()));
	}
	else {
		p.setLocation(p.getLocation() + 11);
	}

	return true;
}

bool cardFunc::Eleven(TokenClass & p1, TokenClass & p2) {
	p1.setLocation(p1.getLocation() + p2.getLocation());
	p2.setLocation(p1.getLocation() - p2.getLocation());
	p1.setLocation(p1.getLocation() - p2.getLocation());

	return true;
}

bool cardFunc::Twelve(TokenClass & p, BoardSpace & b) {
	if (p.getStart() == true || p.getHome() == true) // the pawn can't move if it's at 'HOME' or 'START'
	{
		return false;
	}
	
	if (((p.getLocation() + 12) > b.SafeZoneGate + 5 && p.getLocation() < b.StartSpace)
		|| ((p.getLocation() + 12) > 60 && !(p.getSafeZone()) && 12 - (60 - p.getLocation()) > b.SafeZoneGate + 5)
		|| (p.getLocation() + 12 > 65 && p.getSafeZone())) {
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation() + 12) > 60 && !(p.getSafeZone()) && (12 - (60 - p.getLocation())) > b.SafeZoneGate) {
		p.setLocation(12 - (b.SafeZoneGate - p.getLocation()));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 12) > (b.SafeZoneGate) && p.getLocation() < b.SafeZoneGate) {
		p.setLocation(60 + (12 - (b.SafeZoneGate - p.getLocation())));
		p.setSafeZone(true);
	}
	else if ((p.getLocation() + 12) > 60 && !(p.getSafeZone())) {
		p.setLocation(12 - (60 - p.getLocation()));
	}
	else {
		p.setLocation(p.getLocation() + 12);
	}
	return true;
}

bool cardFunc::Sorry(TokenClass & p1, TokenClass & p2, BoardSpace & b1, BoardSpace & b2) {
	if (p1.getStart() && !(p2.getSafeZone()) && !(p2.getHome()) && !(p2.getStart())) {
		p1.setLocation(p2.getLocation());
		p1.setStart(false);
		b1.Start -= 1;
		p2.setLocation(0);
		p2.setStart(true);
		b2.Start += 1;
	}

	return true;
}