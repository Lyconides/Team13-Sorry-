#include "Tokens.h"
#include "BoardSpaces.h"
void One(TokenClass p, BoardSpace b,) {					//Card "One"
	if (p.getStart == true) {							//Checks if the pawn the player chose is in start or on the board
		p.setStart = false;								//If in start, set start check to false,
		p.setLocation(b.StartSpace);					//move pawn to start space,
		b.Start -= 1;									//and decrement number of pawns in start
	}
	else {												//Move Pawn if not in start
		if ((p.getLocation + 1) > 65) {					//If pawn has enough movement to move into home,
			p.setLocation(0);							//moves pawn off board
			p.setSafeZone(false);
			p.setHome(true);							//sets pawn in home
			b.Home += 1;
		}
		else if (p.getLocation == (b.SafeZoneGate)) {	//Ensures pawn moves into safety zone instead of looping back to starting space
			p.setLocation(61);
			p.setSafeZone(true);
		}
		else if (p.getLocation == 60) {					//Fixes movement to loop through all 60 spaces on the board
			p.setLocation(1);
		}
		else {
			p.setLocation(p.getLocation + 1);
		}
	}
}

void Two(TokenClass p, BoardSpace b) {
	if (p.getStart == true) {
		p.setStart = false;

		p.setLocation(b.StartSpace);
		b.Start -= 1;
	}
	else {
		if ((p.getLocation + 2) > 65) {
			p.setLocation(0);
			p.setSafeZone(false);
			p.setHome(true);
			b.Home += 1;
		}
		else if (((p.getLocation + 2) > (b.SafeZoneGate)) && p.getLocation< b.SafeZoneGate) {
			p.setLocation(60 + (2 - (b.SafeZoneGate - p.getLocation)));
			p.setSafeZone(true);
		}
		else if ((p.getLocation + 2) > 60 && !(p.getSafeZone)) {
			p.setLocation(2 - (60 - p.getLocation));
		}
		else {
			p.setLocation(p.getLocation + 2);
		}
	}
}

void Three(TokenClass p, BoardSpace b) {				//Card "Three"
	if ((p.getLocation + 3) > 65) {
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation + 3) > (b.SafeZoneGate) && p.getLocation < b.SafeZoneGate) {
		p.setLocation(60 + (3 - (b.SafeZoneGate - p.getLocation)));
		p.setSafeZone(true);
	}
	else if ((p.getLocation + 3) > 60 && !(p.getSafeZone)) {
		p.setLocation(3 - (60 - p.getLocation));
	}
	else {
		p.setLocation(p.getLocation + 3);
	}
}

void Four(TokenClass p, BoardSpace b) {				//Card "Four"
	if ((p.getLocation-4)<61 && p.getSafeZone) {
		p.setLocation((b.SafeZoneGate) - (4 - (p.getLocation - 60)));
		p.setSafeZone(false);
	}
	else if ((p.getLocation - 4) < 1) {
		p.setLocation(60 - (4 - p.getLocation))
	}
	else {
		p.setLocation(p.getLocation - 4);
	}
}

void Five(TokenClass p, BoardSpace b) {
	if ((p.getLocation + 5) > 65) {
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation + 5) > 60 && !(p.getSafeZone) && (5 - (60 - p.getLocation)) > b.SafeZoneGate) {
		p.setLocation(5 - (b.SafeZoneGate - p.getLocation));
		p.setSafeZone(true);
	}
	else if ((p.getLocation + 5) > (b.SafeZoneGate) && p.getLocation < b.SafeZoneGate) {
		p.setLocation(60 + (5 - (b.SafeZoneGate - p.getLocation)));
		p.setSafeZone(true);
	}
	else if ((p.getLocation + 5) > 60 && !(p.getSafeZone)) {
		p.setLocation(5 - (60 - p.getLocation));
	}
	else {
		p.setLocation(p.getLocation + 5);
	}
}

void Seven(TokenClass p, BoardSpace b) {
	if ((p.getLocation + 7 > 65 && p.getSafeZone)
		|| (p.getLocation + 7 > b.SafeZoneGate + 5 && p.getLocation <= b.SafeZoneGate)) {
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation + 7) > 60 && !(p.getSafeZone) && (7 - (60 - p.getLocation)) > b.SafeZoneGate) {
		p.setLocation(7 - (b.SafeZoneGate - p.getLocation));
		p.setSafeZone(true);
	}
	else if ((p.getLocation + 7) > (b.SafeZoneGate) && p.getLocation < b.SafeZoneGate) {
		p.setLocation(60 + (7 - (b.SafeZoneGate - p.getLocation)));
		p.setSafeZone(true);
	}
	else if ((p.getLocation + 7) > 60 && !(p.getSafeZone)) {
		p.setLocation(7 - (60 - p.getLocation));
	}
	else {
		p.setLocation(p.getLocation + 7);
	}
}

void Seven(TokenClass p1, int m1, TokenClass p2, int m2, BoardSpace b) {
	//First Pawn
	if ((p1.getLocation + m1 > 65 && p1.getSafeZone)
		|| (p1.getLocation + m1 > b.SafeZoneGate + 5 && p1.getLocation <= b.SafeZoneGate)) {
		p1.setLocation(0);
		p1.setSafeZone(false);
		p1.setHome(true);
		b.Home += 1;
	}
	else if ((p1.getLocation + m1) > 60 && !(p1.getSafeZone) && (m1 - (60 - p1.getLocation)) > b.SafeZoneGate) {
		p1.setLocation(m1 - (b.SafeZoneGate - p1.getLocation));
		p1.setSafeZone(true);
	}
	else if ((p1.getLocation + m1) > (b.SafeZoneGate) && p1.getLocation < b.SafeZoneGate) {
		p1.setLocation(60 + (m1 - (b.SafeZoneGate - p1.getLocation)));
		p1.setSafeZone(true);
	}
	else if ((p1.getLocation + m1) > 60 && !(p1.getSafeZone)) {
		p1.setLocation(m1 - (60 - p1.getLocation));
	}
	else {
		p1.setLocation(p1.getLocation + m1);
	}
	//Second Pawn
	if ((p2.getLocation + m2 > 65 && p2.getSafeZone)
		|| (p2.getLocation + m2 > b.SafeZoneGate + 5 && p2.getLocation <= b.SafeZoneGate)) {
		p2.setLocation(0);
		p2.setSafeZone(false);
		p2.setHome(true);
		b.Home += 1;
	}
	else if ((p2.getLocation + m2) > 60 && !(p2.getSafeZone) && (m2 - (60 - p2.getLocation)) > b.SafeZoneGate) {
		p2.setLocation(m2 - (b.SafeZoneGate - p2.getLocation));
		p2.setSafeZone(true);
	}
	else if ((p2.getLocation + m2) > (b.SafeZoneGate) && p2.getLocation < b.SafeZoneGate) {
		p2.setLocation(60 + (m2 - (b.SafeZoneGate - p2.getLocation)));
		p2.setSafeZone(true);
	}
	else if ((p2.getLocation + m2) > 60 && !(p2.getSafeZone)) {
		p2.setLocation(m2 - (60 - p2.getLocation));
	}
	else {
		p2.setLocation(p2.getLocation + m2);
	}
}

void Eight(TokenClass p, BoardSpace b) {
	if ((p.getLocation + 8 > 65 && p.getSafeZone)
		|| (p.getLocation + 8 > b.SafeZoneGate + 5 && p.getLocation <= b.SafeZoneGate)) {
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation + 8) > 60 && !(p.getSafeZone) && (8 - (60 - p.getLocation)) > b.SafeZoneGate) {
		p.setLocation(8 - (b.SafeZoneGate - p.getLocation));
		p.setSafeZone(true);
	}
	else if ((p.getLocation + 8) > (b.SafeZoneGate) && p.getLocation < b.SafeZoneGate) {
		p.setLocation(60 + (8 - (b.SafeZoneGate - p.getLocation)));
		p.setSafeZone(true);
	}
	else if ((p.getLocation + 8) > 60 && !(p.getSafeZone)) {
		p.setLocation(8 - (60 - p.getLocation));
	}
	else {
		p.setLocation(p.getLocation + 8);
	}
}

void Ten(TokenClass p, int m, BoardSpace b) {
	if (m == 10) {
		if (((p.getLocation + 10) > b.SafeZoneGate + 5 && p.getLocation < b.StartSpace)
			|| ((p.getLocation + 10) > 60 && !(p.getSafeZone) && 10 - (60 - p.getLocation) > b.SafeZoneGate + 5)
			|| (p.getLocation + 10 > 65 && p.getSafeZone)) {
			p.setLocation(0);
			p.setSafeZone(false);
			p.setHome(true);
			b.Home += 1;
		}
		else if ((p.getLocation + 10) > 60 && !(p.getSafeZone) && (10 - (60 - p.getLocation)) > b.SafeZoneGate) {
			p.setLocation(10 - (b.SafeZoneGate - p.getLocation));
			p.setSafeZone(true);
		}
		else if ((p.getLocation + 10) > (b.SafeZoneGate) && p.getLocation < b.SafeZoneGate) {
			p.setLocation(60 + (10 - (b.SafeZoneGate - p.getLocation)));
			p.setSafeZone(true);
		}
		else if ((p.getLocation + 10) > 60 && !(p.getSafeZone)) {
			p.setLocation(10 - (60 - p.getLocation));
		}
		else {
			p.setLocation(p.getLocation + 10);
		}
	}
	else if (m == -1) {
		if (p.getLocation == 61) {
			p.setLocation(b.SafeZoneGate);
			p.setSafeZone(false);
		}
		else if (p.getLocation == 1) {
			p.setLocation(60);
		}
		else {
			p.setLocation(p.getLocation - 1);
		}
	}
}

void Eleven(TokenClass p, BoardSpace b) {
	if (((p.getLocation + 11) > b.SafeZoneGate + 5 && p.getLocation < b.StartSpace)
		|| ((p.getLocation + 11) > 60 && !(p.getSafeZone) && 11 - (60 - p.getLocation) > b.SafeZoneGate + 5)
		|| (p.getLocation + 11 > 65 && p.getSafeZone)) {
		p.setLocation(0);
			p.setSafeZone(false);
			p.setHome(true);
			b.Home += 1;
	}
	else if ((p.getLocation + 11) > 60 && !(p.getSafeZone) && (11 - (60 - p.getLocation)) > b.SafeZoneGate) {
		p.setLocation(11 - (b.SafeZoneGate - p.getLocation));
			p.setSafeZone(true);
	}
	else if ((p.getLocation + 11) > (b.SafeZoneGate) && p.getLocation < b.SafeZoneGate) {
		p.setLocation(60 + (11 - (b.SafeZoneGate - p.getLocation)));
		p.setSafeZone(true);
	}
	else if ((p.getLocation + 11) > 60 && !(p.getSafeZone)) {
		p.setLocation(11 - (60 - p.getLocation));
	}
	else {
		p.setLocation(p.getLocation + 11);
	}
}

void Eleven(TokenClass p1, TokenClass p2) {
	p1.setLocation(p1.getLocation + p2.getLocation);
	p2.setLocation(p1.getLocation - p2.getLocation);
	p1.setLocation(p1.getLocation - p2.getLocation);
}

void Twelve(TokenClass p, BoardSpace b) {
	if (((p.getLocation + 12) > b.SafeZoneGate + 5 && p.getLocation < b.StartSpace)
		|| ((p.getLocation + 12) > 60 && !(p.getSafeZone) && 12 - (60 - p.getLocation) > b.SafeZoneGate + 5)
		|| (p.getLocation + 12 > 65 && p.getSafeZone)) {
		p.setLocation(0);
		p.setSafeZone(false);
		p.setHome(true);
		b.Home += 1;
	}
	else if ((p.getLocation + 12) > 60 && !(p.getSafeZone) && (12 - (60 - p.getLocation)) > b.SafeZoneGate) {
		p.setLocation(12 - (b.SafeZoneGate - p.getLocation));
		p.setSafeZone(true);
	}
	else if ((p.getLocation + 12) > (b.SafeZoneGate) && p.getLocation < b.SafeZoneGate) {
		p.setLocation(60 + (12 - (b.SafeZoneGate - p.getLocation)));
		p.setSafeZone(true);
	}
	else if ((p.getLocation + 12) > 60 && !(p.getSafeZone)) {
		p.setLocation(12 - (60 - p.getLocation));
	}
	else {
		p.setLocation(p.getLocation + 12);
	}
}

void Sorry(TokenClass p1, TokenClass p2, BoardSpace b1, BoardSpace b2) {
	if (p1.getStart && ((p2.getSafeZone && !(p2.getHome))
						|| (!(p2.getSafeZone) && p2.getHome))) {
		p1.setLocation(p2.getLocation);
		p1.setStart(false);
		b1.Start -= 1;
		p2.setLocation(0);
		p2.setStart(true);
		b2.Start += 1;
	}
}