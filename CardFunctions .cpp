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
	// std::string input;
	int short pawn;
	bool move = true; // checks to see if the pawn was actually moved. If it's false, then the pawn couldn't be moved, and what the user chose is invalid.

	// Since a '1' or a '2' are needed to move a pawn off of 'START', this checks to see if the player can actually move anywhere.
	for (int i = 0; i < tColumns; i++)
	{
		if ((tokens[plyr - 1][i].getStart() == true && card <= 2) || (tokens[plyr - 1][i].getStart() == false && tokens[plyr - 1][i].getHome() == false)) // if the pawn is at 'START', the player can only move with a 1 of 2 card.
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

	while (move == false)
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
			
				case 7: // two functions
					// move = (tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;
				case 8:
					move = Eight(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;

				case 10: // multi-functional
					// move = Ten(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;

				case 11: // two functions
					break;
				case 12:
					move = Twelve(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;
				case 13: // the 'Sorry!' case
					// move = Sorry(tokens[plyr - 1][pawn - 1], bps[plyr - 1]);
					break;
			}

			if (move == false) // if move is equal to false, then something went wrong
			{
				std::cout << "That action is illegal. Try again." << std::endl;
				continue;
			}
		}
		else
		{
			std::cout << "\nThat is not a valid pawn number. Please provide another answer.\n" << std::endl;
			continue;
		}

		
	}
}

// REMEMBER TO ACCOUNT FOR PAWN COLLISION
bool cardFunc::One(TokenClass & p, BoardSpace & b) {					//Card "One"
	if (p.getHome() == true) // this pawn can't move if it's at home
	{
		return false;
	}
	else if (p.getStart() == true)
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
	if (p.getHome() == true) // this cannot move if the pawn is at home
	{
		return false;
	}
	else if (p.getStart() == true)
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