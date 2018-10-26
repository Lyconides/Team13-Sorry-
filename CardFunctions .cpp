#include "Tokens.h"
#include "BoardSpaces.h"
void One(TokenClass p, BoardSpace b,) {
	if (p.getStart == true) {
		p.getStart = false;

		p.setLocation(b.StartSpace);
		b.Start -= 1;
	}
	else {
		if (p.getLocation == 60) {
			p.setLocation(1);
		}
		else if (p.getLocation == (p.getHome - 2)) {
			p.setLocation(61);
			p.setSafeZone(true);
		}
		else if (p.getLocation == 65) {
			p.setLocation(0);
			p.setSafeZone(false);
			p.setHome(true);
			b.Home += 1;
		}
		else {
			p.setLocation(p.getLocation + 1);
		}
	}
}

void Two(TokenClass p, BoardSpace b) {
	if (p.getStart == true) {
		p.getStart = false;
		p.setLocation(b.StartSpace);


	}
	else {
		p.setLocation(p.getLocation + 2);
	}
}

void Seven(TokenClass p1, int m1, TokenClass p2, int m2) {
	p1.setLocation(p1.getLocation + m1);
	p2.setLocation(p2.getLocation + m2);
}


void cardGot(int i) {
	if (i == 1) {

	}
}


int main() {
	TokenClass temp(1);
	
}