#include "Tokens.h"
#include "BoardSpaces.h"
void One(TokenClass p, BoardSpaces b) {
	if (p.getStart == true) {
		p.getStart = false;
		p.setLocation(b.StartSpace);
	}
	else {
		p.setLocation(p.getLocation + 1);
	}
}